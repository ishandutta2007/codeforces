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

int root(int[] uf, int u) {
  return (uf[u] < 0) ? u : (uf[u] = uf.root(uf[u]));
}
bool connect(int[] uf, int u, int v) {
  u = uf.root(u);
  v = uf.root(v);
  if (u == v) return false;
  if (uf[u] > uf[v]) swap(u, v);
  uf[u] += uf[v];
  uf[v] = u;
  return true;
}

int N;
long[] C;
int[] A, B;

int[][] G;
int zeit;
int[] dis, fin;

void dfs(int u, int p) {
  dis[u] = zeit;
  bool isLeaf = true;
  foreach (i; G[u]) {
    const v = A[i] ^ B[i] ^ u;
    if (v != p) {
      dfs(v, u);
      isLeaf = false;
    }
  }
  if (isLeaf) {
    ++zeit;
  }
  fin[u] = zeit;
}

void main() {
  try {
    for (; ; ) {
      N = readInt();
      C = new long[N];
      foreach (i; 0 .. N) {
        C[i] = readLong();
      }
      A = new int[N - 1];
      B = new int[N - 1];
      foreach (i; 0 .. N - 1) {
        A[i] = readInt() - 1;
        B[i] = readInt() - 1;
      }
      
      G = new int[][N];
      foreach (i; 0 .. N - 1) {
        G[A[i]] ~= i;
        G[B[i]] ~= i;
      }
      zeit = 0;
      dis = new int[N];
      fin = new int[N];
      dfs(0, -1);
      
      alias Entry = Tuple!(long, "cost", int, "a", int, "b", int, "id");
      auto es = new Entry[N];
      foreach (u; 0 .. N) {
        es[u] = Entry(C[u], dis[u], fin[u], u);
      }
      es.sort;
      
      auto uf = new int[zeit + 1];
      uf[] = -1;
      long total = 0;
      int[] ans;
      for (int j = 0, k; j < N; j = k) {
        for (k = j; k < N && es[j].cost == es[k].cost; ++k) {}
        foreach (l; j .. k) {
          if (uf.root(es[l].a) != uf.root(es[l].b)) {
            ans ~= es[l].id;
          }
        }
        foreach (l; j .. k) {
          if (uf.connect(es[l].a, es[l].b)) {
            total += es[l].cost;
          }
        }
      }
      
      ans.sort;
      writeln(total, " ", ans.length);
      foreach (index, u; ans) {
        if (index > 0) write(" ");
        write(u + 1);
      }
      writeln();
    }
  } catch (EOFException e) {
  }
}