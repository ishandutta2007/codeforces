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


enum A = 26;

void main() {
  try {
    for (; ; ) {
      const S = readToken();
      const L = cast(int)(S.length);
      
      auto cs = S.dup;
      auto bas = new BitArray[A];
      foreach (a; 0 .. A) {
        bas[a] = BitArray(iota(L).map!(i => (cs[i] - 'a' == a)).array);
      }
      
      const Q = readInt();
      foreach (q; 0 .. Q) {
        const typ = readInt();
        switch (typ) {
          case 1: {
            const i = readInt() - 1;
            const c = readToken()[0];
            bas[cs[i] - 'a'].flip(i);
            cs[i] = c;
            bas[cs[i] - 'a'].flip(i);
          } break;
          case 2: {
            const l = readInt() - 1;
            const r = readInt();
            const y = readToken();
            const yLen = cast(int)(y.length);
            if (yLen > r - l) {
              writeln(0);
              continue;
            }
            auto b = bas[y[0] - 'a'].dup;
            b >>= l;
            debug {
              writeln("  ", b);
            }
            foreach (j; 1 .. yLen) {
              auto ba = bas[y[j] - 'a'].dup;
              ba >>= (l + j);
              b &= ba;
              debug {
                writeln("  ", b);
              }
            }
            debug {
              writeln("b = ", b);
              writeln("bas = ", bas);
            }
            int ans = b.count;
            b >>= (r - l - yLen + 1);
            ans -= b.count;
            writeln(ans);
          } break;
          default: assert(false);
        }
      }
    }
  } catch (EOFException e) {
  }
}