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
      
      int[][] ans;
      if (N % 2 != 0) {
        ans ~= [0, 1, 2];
        ans ~= [0, 1, 2];
        for (int n = 3; n < N; n += 2) {
          ans ~= [n, n + 1, 0];
          ans ~= [n, n + 1, 0];
          for (int u = 1; u < n; u += 2) {
            ans ~= [n, u, n + 1, u + 1];
            ans ~= [n, u, n + 1, u + 1];
          }
        }
      } else {
        ans ~= [0, 1, 2];
        ans ~= [1, 2, 3];
        ans ~= [2, 3, 0];
        ans ~= [3, 0, 1];
        for (int n = 4; n < N; n += 2) {
          ans ~= [n, 0, n + 1, 1];
          ans ~= [n, n + 1, 0];
          ans ~= [n, n + 1, 1];
          for (int u = 2; u < n; u += 2) {
            ans ~= [n, u, n + 1, u + 1];
            ans ~= [n, u, n + 1, u + 1];
          }
        }
      }
      
      writeln(ans.length);
      foreach (cyc; ans) {
        write(cyc.length);
        foreach (u; cyc) {
          write(" ", u + 1);
        }
        writeln;
      }
      
      auto adj = new int[][](N, N);
      foreach (cyc; ans) {
        foreach (i; 0 .. cyc.length) {
          const u = cyc[i], v = cyc[(i + 1) % $];
          ++adj[u][v];
          ++adj[v][u];
        }
      }
      foreach (u; 0 .. N) foreach (v; 0 .. N) {
        assert(adj[u][v] == (u == v) ? 0 : 2);
      }
    }
  } catch (EOFException e) {
  }
}