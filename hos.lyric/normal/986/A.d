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




void main() {
  try {
    for (; ; ) {
      const N = readInt();
      const M = readInt();
      const K = readInt();
      const S = readInt();
      auto A = new int[N];
      foreach (u; 0 .. N) {
        A[u] = readInt() - 1;
      }
      auto U = new int[M];
      auto V = new int[M];
      foreach (i; 0 .. M) {
        U[i] = readInt() - 1;
        V[i] = readInt() - 1;
      }
      
      auto G = new int[][N];
      foreach (i; 0 .. M) {
        G[U[i]] ~= V[i];
        G[V[i]] ~= U[i];
      }
      
      auto ds = new int[][](N, K);
      auto que = new int[N];
      auto dist = new int[N];
      foreach (k; 0 .. K) {
        int qb, qe;
        dist[] = N;
        foreach (u; 0 .. N) {
          if (A[u] == k) {
            dist[u] = 0;
            que[qe++] = u;
          }
        }
        for (; qb != qe; ) {
          const u = que[qb++];
          foreach (v; G[u]) {
            if (chmin(dist[v], dist[u] + 1)) {
              que[qe++] = v;
            }
          }
        }
        foreach (u; 0 .. N) {
          ds[u][k] = dist[u];
        }
      }
      
      foreach (u; 0 .. N) {
        if (u > 0) write(" ");
        ds[u].sort;
        const ans = ds[u][0 .. S].sum;
        write(ans);
      }
      writeln();
    }
  } catch (EOFException e) {
  }
}