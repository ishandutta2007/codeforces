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
      const K = readInt();
      auto A = new int[][](4, N);
      foreach (x; 0 .. 4) foreach (y; 0 .. N) {
        A[x][y] = readInt();
      }
      
      auto a = new int[][](4, N);
      foreach (x; 0 .. 4) foreach (y; 0 .. N) {
        a[x][y] = A[x][y];
      }
      
      int[] xs, ys;
      foreach (y; 0 .. N) {
        xs ~= 1;
        ys ~= y;
      }
      foreach_reverse (y; 0 .. N) {
        xs ~= 2;
        ys ~= y;
      }
      const len = cast(int)(xs.length);
      
      int[][] ans;
      
      for (; ; ) {
        bool ok = true;
        foreach (x; [1, 2]) foreach (y; 0 .. N) {
          if (a[x][y] != 0) {
            if (a[x][y] == a[x ^ 1][y]) {
              ans ~= [a[x][y], x ^ 1, y];
              a[x][y] = 0;
            } else {
              ok = false;
            }
          }
        }
        if (ok) {
          break;
        }
        int i0 = -1;
        foreach (i; 0 .. len) {
          if (a[xs[i]][ys[i]] == 0) {
            i0 = i;
            break;
          }
        }
        if (i0 == -1) {
          writeln(-1);
          goto failed;
        }
        foreach (di; 0 .. len - 1) {
          const i = (i0 + di) % len;
          const j = (i0 + di + 1) % len;
          if (a[xs[j]][ys[j]] != 0) {
            assert(a[xs[i]][ys[i]] == 0);
            ans ~= [a[xs[j]][ys[j]], xs[i], ys[i]];
            swap(a[xs[i]][ys[i]], a[xs[j]][ys[j]]);
          }
        }
      }
      
      writeln(ans.length);
      foreach (move; ans) {
        writeln(move[0], " ", move[1] + 1, " ", move[2] + 1);
      }
     failed:
    }
  } catch (EOFException e) {
  }
}