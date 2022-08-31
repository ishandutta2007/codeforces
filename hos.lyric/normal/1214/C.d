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


int N;
string S;

void main() {
  try {
    for (; ; ) {
      N = readInt();
      S = readToken();
      
      auto as = new int[N + 1];
      auto ls = new int[N + 1];
      auto rs = new int[N + 1];
      foreach (i; 0 .. N) {
        as[i + 1] = as[i] + ((S[i] == '(') ? +1 : -1);
      }
      foreach (i; 0 .. N) {
        ls[i + 1] = min(ls[i], as[i + 1]);
      }
      foreach_reverse (i; 0 .. N) {
        rs[i] = min(rs[i + 1], as[i]);
      }
      
      bool ans;
      if (as[N] == 0) {
        debug {
          writeln("as = ", as);
          writeln("ls = ", ls);
          writeln("rs = ", rs);
        }
        ans = false;
        foreach (i; 0 .. N) {
          if (S[i] == '(') {
            if (1 + ls[i] >= 0 && rs[i + 1] >= 0) {
              ans = true;
            }
          } else {
            if (ls[i] >= 0 && 1 + rs[i + 1] >= 0) {
              ans = true;
            }
          }
        }
      } else {
        ans = false;
      }
      writeln(ans ? "Yes" : "No");
    }
  } catch (EOFException e) {
  }
}