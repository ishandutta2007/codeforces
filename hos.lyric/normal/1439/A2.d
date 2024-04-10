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
      const numCases = readInt();
      foreach (caseId; 0 .. numCases) {
        const M = readInt();
        const N = readInt();
        auto A = new string[M];
        foreach (x; 0 .. M) {
          A[x] = readToken();
        }
        
        auto a = new int[][](M, N);
        foreach (x; 0 .. M) foreach (y; 0 .. N) {
          a[x][y] = A[x][y] - '0';
        }
        
        int[][] ans;
        void oper(int x0, int y0, int x1, int y1, int x2, int y2) {
          ans ~= [x0, y0, x1, y1, x2, y2];
          a[x0][y0] ^= 1;
          a[x1][y1] ^= 1;
          a[x2][y2] ^= 1;
        }
        
        foreach (x; 0 .. M - 2) foreach (y; 0 .. N - 2) {
          if (a[x][y]) {
            oper(x, y, x, y + 1, x + 1, y);
          }
        }
        foreach (x; 0 .. M - 2) {
          const y = N - 2;
          if (a[x][y]) {
            if (a[x][y + 1]) {
              oper(x, y, x, y + 1, x + 1, y);
            } else {
              oper(x, y, x + 1, y, x + 1, y + 1);
            }
          } else {
            if (a[x][y + 1]) {
              oper(x, y + 1, x + 1, y, x + 1, y + 1);
            } else {
              oper(x, y, x, y + 1, x + 1, y);
              oper(x, y, x, y + 1, x + 1, y);
            }
          }
        }
        foreach (y; 0 .. N - 2) {
          const x = M - 2;
          if (a[x][y]) {
            if (a[x + 1][y]) {
              oper(x, y, x + 1, y, x, y + 1);
            } else {
              oper(x, y, x, y + 1, x + 1, y + 1);
            }
          } else {
            if (a[x + 1][y]) {
              oper(x + 1, y, x, y + 1, x + 1, y + 1);
            } else {
              oper(x, y, x + 1, y, x, y + 1);
              oper(x, y, x + 1, y, x, y + 1);
            }
          }
        }
        {
          const x = M - 2, y = N - 2;
          foreach (p; 0 .. 1 << 4) {
            auto bs = new int[4];
            foreach (i; 0 .. 4) {
              if (p & 1 << i) {
                foreach (j; 0 .. 4) {
                  if (i != j) {
                    bs[j] ^= 1;
                  }
                }
              }
            }
            debug {
              writeln(p, ": ", bs);
            }
            bool ok = true;
            foreach (j; 0 .. 4) {
              ok = ok && (a[x + j / 2][y + j % 2] == bs[j]);
            }
            if (ok) {
              if (p & 1 << 0) oper(x, y + 1, x + 1, y, x + 1, y + 1);
              if (p & 1 << 1) oper(x, y, x + 1, y, x + 1, y + 1);
              if (p & 1 << 2) oper(x, y, x, y + 1, x + 1, y + 1);
              if (p & 1 << 3) oper(x, y, x, y + 1, x + 1, y);
            }
          }
        }
        
        writeln(ans.length);
        foreach (row; ans) {
          foreach (i; 0 .. 6) {
            if (i > 0) write(" ");
            write(row[i] + 1);
          }
          writeln;
        }
        debug {
          writeln("a = ", a);
        }
      }
    }
  } catch (EOFException e) {
  }
}