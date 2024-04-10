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


// a^-1 (mod m)
long modInv(long a, long m)
in {
  assert(m > 0, "modInv: m > 0 must hold");
}
do {
  long b = m, x = 1, y = 0, t;
  for (; ; ) {
    t = a / b;
    a -= t * b;
    if (a == 0) {
      assert(b == 1 || b == -1, "modInv: gcd(a, m) != 1");
      if (b == -1) {
        y = -y;
      }
      return (y < 0) ? (y + m) : y;
    }
    x -= t * y;
    t = b / a;
    b -= t * a;
    if (b == 0) {
      assert(a == 1 || a == -1, "modInv: gcd(a, m) != 1");
      if (a == -1) {
        x = -x;
      }
      return (x < 0) ? (x + m) : x;
    }
    y -= t * x;
  }
}


enum long MO = 998244353;

int N, M;
int[] A;
long[] W;

void main() {
  try {
    for (; ; ) {
      N = readInt();
      M = readInt();
      A = new int[N];
      foreach (i; 0 .. N) {
        A[i] = readInt();
      }
      W = new long[N];
      foreach (i; 0 .. N) {
        W[i] = readLong();
      }
      
      long R, S;
      foreach (i; 0 .. N) {
        if (A[i]) {
          R += W[i];
        }
        S += W[i];
      }
      
      auto invs = new long[2 * M + 1];
      foreach (x; -M .. +M + 1) {
        if (S + x > 0) {
          invs[M + x] = modInv(S + x, MO);
        }
      }
      
      auto dp = new long[][](M + 1, M + 1);
      dp[0][0] = 1;
      foreach (j; 0 .. M) {
        foreach (x; 0 .. j + 1) {
          if (S + x + (j - x) > 0) {
            const prob = ((R + x) * invs[M + x - (j - x)]) % MO;
            (dp[j + 1][x + 0] += dp[j][x] * (1 - prob)) %= MO;
            (dp[j + 1][x + 1] += dp[j][x] * prob) %= MO;
          }
        }
      }
      debug {
        writeln("dp = ", dp);
      }
      
      long eP, eN;
      foreach (x; 0 .. M + 1) {
        (eP += dp[M][x] * (R + x)) %= MO;
        (eN += dp[M][x] * (S - R - (M - x))) %= MO;
      }
      foreach (i; 0 .. N) {
        long ans;
        if (A[i]) {
          ans = (((eP * W[i]) % MO) * modInv(R, MO)) % MO;
        } else {
          ans = (((eN * W[i]) % MO) * modInv(S - R, MO)) % MO;
        }
        ans = (ans % MO + MO) % MO;
        writeln(ans);
      }
    }
  } catch (EOFException e) {
  }
}