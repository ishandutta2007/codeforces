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


int N, K;
int[] A, B;

int[][] G;
int[] par, dep, sz;

void dfs(int u, int p) {
  par[u] = p;
  dep[u] = (p == -1) ? 0 : (dep[p] + 1);
  sz[u] = 1;
  foreach (i; G[u]) {
    const v = A[i] ^ B[i] ^ u;
    if (v != p) {
      dfs(v, u);
      sz[u] += sz[v];
    }
  }
}

void main() {
  try {
    for (; ; ) {
      N = readInt();
      K = readInt();
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
      par = new int[N];
      dep = new int[N];
      sz = new int[N];
      dfs(0, -1);
      
      auto degs = new int[N];
      foreach (u; 1 .. N) {
        ++degs[par[u]];
      }
      alias Entry = Tuple!(int, "score", int, "u");
      BinaryHeap!(Array!Entry) que;
      foreach (u; 1 .. N) {
        if (degs[u] == 0) {
          que.insert(Entry(dep[u], u));
        }
      }
      
      long ans;
      foreach (k; 0 .. K) {
        const e = que.front;
        que.removeFront;
        debug {
          writeln("e = ", e);
        }
        ans += e.score;
        const p = par[e.u];
        if (p != 0 && --degs[p] == 0) {
          que.insert(Entry(dep[p] - (sz[p] - 1), p));
        }
      }
      writeln(ans);
    }
  } catch (EOFException e) {
  }
}