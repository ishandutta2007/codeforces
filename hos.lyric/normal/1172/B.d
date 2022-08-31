import std.conv, std.functional, std.range, std.stdio, std.string;
import std.algorithm, std.array, std.bigint, std.complex, std.container, std.math, std.numeric, std.regex, std.typecons;
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


enum long MO = 998244353;

int N;
int[] U, V;

int[][] G;
int[] deg;

void dfs(int u, int p) {
  foreach (v; G[u]) {
    if (v != p) {
      ++deg[u];
      dfs(v, u);
    }
  }
}

void main() {
  try {
    for (; ; ) {
      N = readInt();
      U = new int[N - 1];
      V = new int[N - 1];
      foreach (i; 0 .. N - 1) {
        U[i] = readInt() - 1;
        V[i] = readInt() - 1;
      }
      
      G = new int[][N];
      foreach (i; 0 .. N - 1) {
        G[U[i]] ~= V[i];
        G[V[i]] ~= U[i];
      }
      deg = new int[N];
      const rt = 0;
      dfs(rt, -1);
      
      long ans = N;
      foreach (u; 0 .. N) {
        foreach (k; 1 .. deg[u] + 1) {
          ans *= k;
          ans %= MO;
        }
        if (u != rt) {
          ans *= (deg[u] + 1);
          ans %= MO;
        }
      }
      writeln(ans);
    }
  } catch (EOFException e) {
  }
}