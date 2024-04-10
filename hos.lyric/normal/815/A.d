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
      const M = readInt();
      const N = readInt();
      auto G = new int[][](M, N);
      foreach (x; 0 .. M) foreach (y; 0 .. N) {
        G[x][y] = readInt();
      }
      
      int ans = int.max;
      int am = -1;
      
      foreach (a; 0 .. G[0][0] + 1) {
        auto rows = new int[M];
        auto cols = new int[N];
        rows[0] = a;
        cols[0] = G[0][0] - a;
        foreach (x; 1 .. M) {
          rows[x] = G[x][0] - cols[0];
        }
        foreach (y; 1 .. N) {
          cols[y] = G[0][y] - rows[0];
        }
        if (rows.all!"a >= 0" && cols.all!"a >= 0") {
          bool ok = true;
          foreach (x; 0 .. M) foreach (y; 0 .. N) {
            ok = ok && (G[x][y] == rows[x] + cols[y]);
          }
          if (ok) {
            const cost = rows.sum + cols.sum;
            if (chmin(ans, cost)) {
              am = a;
            }
          }
        }
      }
      
      if (am == -1) {
        writeln(-1);
      } else {
        auto rows = new int[M];
        auto cols = new int[N];
        rows[0] = am;
        cols[0] = G[0][0] - am;
        foreach (x; 1 .. M) {
          rows[x] = G[x][0] - cols[0];
        }
        foreach (y; 1 .. N) {
          cols[y] = G[0][y] - rows[0];
        }
        writeln(ans);
        foreach (x; 0 .. M) {
          foreach (_; 0 .. rows[x]) {
            writeln("row ", x + 1);
          }
        }
        foreach (y; 0 .. N) {
          foreach (_; 0 .. cols[y]) {
            writeln("col ", y + 1);
          }
        }
      }
    }
  } catch (EOFException e) {
  }
}