import std.conv, std.functional, std.range, std.stdio, std.string;
import std.algorithm, std.array, std.bigint, std.bitmanip, std.complex, std.container, std.math, std.numeric, std.regex, std.typecons;
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


enum A = 5 - 1, B = 10 - 1, C = 50 - 1;

void main() {
  try {
    for (; ; ) {
      const N = readLong();
      
      alias Entry = Tuple!(long, "key", int, "val");
      auto ess = new Entry[][C];
      foreach (x; 0 .. C) foreach (y; 0 .. C) {
        if (x + y <= N) {
          const r = cast(int)((A * x + B * y) % C);
          const mn = A * x + B * y;
          const mx = A * x + B * y + C * (N - x - y);
          ess[r] ~= Entry((mn - r) / C, +1);
          ess[r] ~= Entry((mx - r) / C + 1, -1);
        }
      }
      long ans;
      foreach (r; 0 .. C) {
        ess[r].sort;
        int now;
        foreach (j; 0 .. cast(int)(ess[r].length) - 1) {
          now += ess[r][j].val;
          if (now > 0) {
            ans += ess[r][j + 1].key - ess[r][j].key;
          }
        }
      }
      writeln(ans);
    }
  } catch (EOFException e) {
  }
}