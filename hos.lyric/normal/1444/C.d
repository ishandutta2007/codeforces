import std.conv, std.functional, std.range, std.stdio, std.string;
import std.algorithm, std.array, std.bigint, std.bitmanip, std.complex, std.container, std.math, std.mathspecial, std.numeric, std.regex, std.typecons;
import core.bitop;

class EOFException : Throwable { this() { super("EOF"); } }
string[] tokens;
string readToken() { for (; tokens.empty; ) { if (stdin.eof) { throw new EOFException; } tokens = readln.split; } auto token = tokens.front; tokens.popFront; return token; }
int readInt() { return readToken.to!int; }
long readLong() { return readToken.to!long; }
real readReal() { return readToken.to!real; }

bool chmin(T)(ref T t, in T f) { if (t > f) { t = f; return true; } else { return false; } }
bool chmax(T)(ref T t, in T f) { if (t < f) { t = f; return true; } else { return false; } }

int binarySearch(alias pred, T)(in T[] as) { int lo = -1, hi = cast(int)(as.length); for (; lo + 1 < hi; ) { const mid = (lo + hi) >> 1; (unaryFun!pred(as[mid]) ? hi : lo) = mid; } return hi; }
int lowerBound(T)(in T[] as, T val) { return as.binarySearch!(a => (a >= val)); }
int upperBound(T)(in T[] as, T val) { return as.binarySearch!(a => (a > val)); }


alias KV = Tuple!(int, "key", int, "val");
KV[] history;

int root(int[] uf, int u) {
  // return (uf[u] < 0) ? u : (uf[u] = uf.root(uf[u]));
  if (uf[u] < 0) {
    return u;
  } else {
    const r = uf.root(uf[u]);
    history ~= KV(u, uf[u]);
    return uf[u] = r;
  }
}
bool connect(int[] uf, int u, int v) {
  u = uf.root(u);
  v = uf.root(v);
  if (u == v) return false;
  if (uf[u] > uf[v]) swap(u, v);
  history ~= KV(u, uf[u]);
  uf[u] += uf[v];
  history ~= KV(v, uf[v]);
  uf[v] = u;
  return true;
}


void main() {
  try {
    for (; ; ) {
      const N = readInt();
      const M = readInt();
      const K = readInt();
      auto C = new int[N];
      foreach (u; 0 .. N) {
        C[u] = readInt() - 1;
      }
      auto A = new int[M];
      auto B = new int[M];
      foreach (i; 0 .. M) {
        A[i] = readInt() - 1;
        B[i] = readInt() - 1;
      }
      
      auto uss = new int[][K];
      foreach (u; 0 .. N) {
        uss[C[u]] ~= u;
      }
      
      auto uf = new int[N * 2];
      uf[] = -1;
      
      alias Entry = Tuple!(int, "ca", int, "cb", int, "i");
      Entry[] es;
      foreach (i; 0 .. M) {
        if (C[A[i]] > C[B[i]]) {
          swap(A[i], B[i]);
        }
        if (C[A[i]] == C[B[i]]) {
          uf.connect(A[i] * 2 + 0, B[i] * 2 + 1);
          uf.connect(A[i] * 2 + 1, B[i] * 2 + 0);
        } else {
          es ~= Entry(C[A[i]], C[B[i]], i);
        }
      }
      es.sort;
      const esLen = cast(int)(es.length);
      
      auto good = new bool[K];
      good[] = true;
      foreach (k; 0 .. K) {
        foreach (u; uss[k]) {
          good[k] = good[k] && (uf.root(u * 2 + 0) != uf.root(u * 2 + 1));
        }
      }
      debug {
        writeln("good = ", good);
      }
      const numGood = cast(long)(good.count(true));
      long ans = numGood * (numGood - 1) / 2;
      
      for (int g = 0, h; g < esLen; g = h) {
        for (h = g; h < esLen && (es[g].ca == es[h].ca && es[g].cb == es[h].cb); ++h) {}
        if (good[es[g].ca] && good[es[g].cb]) {
          debug {
            writeln(es[g .. h]);
          }
          history = [];
          foreach (ref e; es[g .. h]) {
            const i = e.i;
            uf.connect(A[i] * 2 + 0, B[i] * 2 + 1);
            uf.connect(A[i] * 2 + 1, B[i] * 2 + 0);
          }
          bool ok = true;
          foreach (ref e; es[g .. h]) {
            const i = e.i;
            ok = ok && (uf.root(A[i] * 2 + 0) != uf.root(A[i] * 2 + 1));
            ok = ok && (uf.root(B[i] * 2 + 0) != uf.root(B[i] * 2 + 1));
          }
          if (!ok) {
            --ans;
          }
          foreach_reverse (ref kv; history) {
            uf[kv.key] = kv.val;
          }
        }
      }
      
      writeln(ans);
    }
  } catch (EOFException e) {
  }
}