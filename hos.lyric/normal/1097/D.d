import std.conv, std.stdio, std.string;
import std.algorithm, std.array, std.bigint, std.container, std.math, std.range, std.regex, std.typecons;
import core.bitop, core.thread;

class EOFException : Throwable { this() { super("EOF"); } }
string[] tokens;
string readToken() { for (; tokens.empty; ) { if (stdin.eof) throw new EOFException; tokens = readln.split; } auto token = tokens[0]; tokens.popFront; return token; }
int readInt() { return readToken().to!int; }
long readLong() { return readToken().to!long; }
real readReal() { return readToken().to!real; }

void chmin(T)(ref T t, in T f) { if (t > f) t = f; }
void chmax(T)(ref T t, in T f) { if (t < f) t = f; }

int binarySearch(T)(in T[] as, in bool delegate(T) test) { int low = -1, upp = cast(int)(as.length); for (; low + 1 < upp; ) { int mid = (low + upp) >> 1; (test(as[mid]) ? low : upp) = mid; } return upp; }
int lowerBound(T)(in T[] as, in T val) { return as.binarySearch((T a) => (a < val)); }
int upperBound(T)(in T[] as, in T val) { return as.binarySearch((T a) => (a <= val)); }


immutable MO = 10L^^9 + 7;
immutable LIM = 10^^5 + 10;

long[] inv;
void prepare() {
  inv = new long[LIM];
  inv[1] = 1;
  foreach (i; 2 .. LIM) {
    inv[i] = MO - (MO / i) * inv[cast(size_t)(MO % i)] % MO;
  }
}

long N;
int K;

void main() {
  prepare();
  
  try {
    for (; ; ) {
      N = readLong();
      K = readInt();
      Tuple!(long, int)[] ps;
      long n = N;
      for (long d = 2; d * d <= n; ++d) {
        if (n % d == 0) {
          int e;
          do {
            ++e;
            n /= d;
          } while (n % d == 0);
          ps ~= tuple(d, e);
        }
      }
      if (n > 1) {
        ps ~= tuple(n, 1);
      }
      debug {
        writeln("ps = ", ps);
      }
      long ans = 1;
      foreach (entry; ps) {
        const p = entry[0];
        const e = entry[1];
        auto dp = new long[][](K + 1, e + 1);
        dp[0][0] = 1;
        foreach (i; 1 .. e + 1) {
          dp[0][i] = (dp[0][i - 1] * p) % MO;
        }
        foreach (k; 1 .. K + 1) {
          long sum;
          foreach (i; 0 .. e + 1) {
            (sum += dp[k - 1][i]) %= MO;
            dp[k][i] = (sum * inv[i + 1]) % MO;
          }
        }
        (ans *= dp[K][e]) %= MO;
      }
      writeln(ans);
    }
  } catch (EOFException e) {
  }
}