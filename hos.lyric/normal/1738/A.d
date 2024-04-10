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
      const numCases = readInt;
      foreach (caseId; 0 .. numCases) {
        const N = readInt;
        auto A = new int[N];
        foreach (i; 0 .. N) {
          A[i] = readInt;
        }
        auto B = new long[N];
        foreach (i; 0 .. N) {
          B[i] = readLong;
        }
        
        long[][2] bss;
        foreach (i; 0 .. N) {
          bss[A[i]] ~= B[i];
        }
        foreach (h; 0 .. 2) {
          bss[h].sort;
        }
        
        long ans;
        foreach (h0; 0 .. 2) {
          int[2] poss;
          foreach (h; 0 .. 2) {
            poss[h] = cast(int)(bss[h].length);
          }
          long score;
          int lastA;
          long lastB;
          for (; poss[0] > 0 || poss[1] > 0; ) {
            foreach (h; [h0, h0 ^ 1]) if (poss[h] > 0) {
              score += ((h != lastA) ? 2 : 1) * lastB;
              lastA = h;
              lastB = bss[h][--poss[h]];
            }
          }
          score += lastB;
          debug {
            writeln(h0, ": ", score);
          }
          chmax(ans, score);
        }
        
        writeln(ans);
      }
    }
  } catch (EOFException e) {
  }
}