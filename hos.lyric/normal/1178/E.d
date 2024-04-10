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


string S;
int N;

void main() {
  try {
    for (; ; ) {
      S = readToken();
      N = cast(int)(S.length);
      
      char[] ansL, ansM;
      for (int l = 0, r = N; l < r; ) {
        if (l + 4 <= r) {
          bool found;
          foreach (d; "abc") {
            if ((S[l] == d || S[l + 1] == d) && (S[r - 2] == d || S[r - 1] == d)) {
              found = true;
              ansL ~= d;
              break;
            }
          }
          assert(found);
          l += 2;
          r -= 2;
        } else {
          ansM ~= S[l];
          break;
        }
      }
      write(ansL.to!string);
      write(ansM.to!string);
      ansL.reverse;
      write(ansL.to!string);
      writeln();
    }
  } catch (EOFException e) {
  }
}