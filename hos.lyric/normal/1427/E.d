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


enum LIM = 4 * 10L^^18;

alias Line = Tuple!(char, "op", long, "a", long, "b");

void main() {
  debug {
    for (long n = 1; n < 10^^6; n += 2) {
      assert(gcd(n, n ^ (n << bsr(n))) == 1);
    }
  }
  
  try {
    for (; ; ) {
      const N = readLong();
      if (N == 1) {
        writeln(0);
        continue;
      }
      
      const K = bsr(N);
      const B = N ^ (N << K);
      
      Line[] ans;
      for (int i = 1; ; ++i) {
        if (N << i > LIM) {
          break;
        }
        ans ~= Line('+', N << (i - 1), N << (i - 1));
      }
      ans ~= Line('^', N, N << K);
      for (int i = 1; ; ++i) {
        if (B << i > LIM) {
          break;
        }
        ans ~= Line('+', B << (i - 1), B << (i - 1));
      }
      
      int L;
      for (L = 1; 1L << L < N * B; ++L) {}
      foreach (t; [1L << L, 1L << L | 1]) {
        foreach (y; 0 .. N) {
          if ((t - B * y) % N == 0) {
            const x = (t - B * y) / N;
            long sum;
            foreach (e; 0 .. bsr(x) + 1) {
              if ((x >> e) & 1) {
                if (sum > 0) {
                  ans ~= Line('+', sum, N << e);
                }
                sum += N << e;
              }
            }
            foreach (e; 0 .. bsr(y) + 1) {
              if ((y >> e) & 1) {
                if (sum > 0) {
                  ans ~= Line('+', sum, B << e);
                }
                sum += B << e;
              }
            }
            assert(sum == t);
            break;
          }
        }
      }
      ans ~= Line('^', 1L << L, 1L << L | 1);
      
      writeln(ans.length);
      foreach (ref line; ans) {
        writefln("%s %s %s", line.a, line.op, line.b);
      }
    }
  } catch (EOFException e) {
  }
}