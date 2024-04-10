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
        const N = readInt();
        const M = readInt();
        auto B = new long[][](N, M);
        foreach (i; 0 .. N) {
          foreach (j; 0 .. M) {
            B[i][j] = readLong();
          }
          B[i].sort;
        }
        debug {
          writeln("B = ", B);
        }
        
        auto ls = new int[N];
        auto rs = new int[N];
        ls[] = 0;
        rs[] = M;
        
        auto ans = new long[][](M, N);
        foreach (h; 0 .. M) {
          int im = -1;
          foreach (i; 0 .. N) {
            if (im == -1 || B[im][ls[im]] > B[i][ls[i]]) {
              im = i;
            }
          }
          debug {
            writeln(ls, " ", rs, " ", im, " ", B[im][ls[im]]);
          }
          ans[h][im] = B[im][ls[im]++];
          foreach (i; 0 .. N) {
            if (im != i) {
              ans[h][i] = B[i][--rs[i]];
            }
          }
        }
        
        foreach (i; 0 .. N) {
          foreach (h; 0 .. M) {
            if (h > 0) write(" ");
            write(ans[h][i]);
          }
          writeln;
        }
      }
    }
  } catch (EOFException e) {
  }
}