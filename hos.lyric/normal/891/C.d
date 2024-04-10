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
    if (uf[u] != r) {
      history ~= KV(u, uf[u]);
      uf[u] = r;
    }
    return r;
  }
}
bool connect(int[] uf, int u, int v) {
  u = uf.root(u);
  v = uf.root(v);
  if (u == v) return false;
  if (uf[u] > uf[v]) swap(u, v);
  history ~= KV(u, uf[u]);
  history ~= KV(v, uf[v]);
  uf[u] += uf[v];
  uf[v] = u;
  return true;
}



void main() {
  try {
    for (; ; ) {
      const N = readInt();
      const M = readInt();
      auto U = new int[M];
      auto V = new int[M];
      auto W = new int[M];
      foreach (i; 0 .. M) {
        U[i] = readInt() - 1;
        V[i] = readInt() - 1;
        W[i] = readInt();
      }
      const Q = readInt();
      auto K = new int[Q];
      auto E = new int[][Q];
      foreach (q; 0 .. Q) {
        K[q] = readInt();
        E[q] = new int[K[q]];
        foreach (k; 0 .. K[q]) {
          E[q][k] = readInt() - 1;
        }
      }
      
      const limW = W.maxElement + 1;
      auto edgess = new int[][limW];
      foreach (i; 0 .. M) {
        edgess[W[i]] ~= i;
      }
      alias QK = Tuple!(int, "q", int, "k");
      auto qkss = new QK[][limW];
      foreach (q; 0 .. Q) {
        foreach (k; 0 .. K[q]) {
          qkss[W[E[q][k]]] ~= QK(q, k);
        }
      }
      
      auto ans = new bool[Q];
      ans[] = true;
      auto uf = new int[N];
      uf[] = -1;
      foreach (w; 0 .. limW) {
        auto qks = qkss[w];
        const len = cast(int)(qks.length);
        for (int j = 0, k; j < len; j = k) {
          for (k = j; k < len && qks[j].q == qks[k].q; ++k) {}
          history = [];
          foreach (l; j .. k) {
            const e = E[qks[l].q][qks[l].k];
            if (!uf.connect(U[e], V[e])) {
              ans[qks[l].q] = false;
            }
          }
          foreach_reverse (kv; history) {
            uf[kv.key] = kv.val;
          }
        }
        foreach (i; edgess[w]) {
          uf.connect(U[i], V[i]);
        }
      }
      
      foreach (q; 0 .. Q) {
        writeln(ans[q] ? "YES" : "NO");
      }
    }
  } catch (EOFException e) {
  }
}