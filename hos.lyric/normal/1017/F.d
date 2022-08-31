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

// floor(sqrt(a))
long floorSqrt(long a) {
  import core.bitop : bsr;
  import std.algorithm : min;
  long b = a, x = 0, y = 0;
  for (int e = bsr(a) & ~1; e >= 0; e -= 2) {
    x <<= 1;
    y <<= 1;
    if (b >= (y | 1) << e) {
      b -= (y | 1) << e;
      x |= 1;
      y += 2;
    }
  }
  return x;
}

// get([N / j]) = \sum_{p<=[N/j]} p^K
//   O(N^(3/4) / log N) time, O(N^(1/2)) space
class PrimeSum(T, int K) {
  long N, sqrtN;
  bool[] isPrime;
  T[] small, large;
  this(long N) {
    assert(N >= 1, "PrimeSum: N >= 1 must hold");
    this.N = N;
    sqrtN = floorSqrt(N);
    isPrime = new bool[cast(int)(sqrtN + 1)];
    small = new T[cast(int)(sqrtN + 1)];
    large = new T[cast(int)(sqrtN + 1)];
    isPrime[2 .. $] = true;
    T powerSum(long n) {
      static if (K == 0) {
        return T(n);
      } else static if (K == 1) {
        long n0 = n, n1 = n + 1;
        ((n0 % 2 == 0) ? n0 : n1) /= 2;
        return T(n0) * T(n1);
      } else static if (K == 2) {
        long n0 = n, n1 = n + 1, n2 = 2 * n + 1;
        ((n0 % 2 == 0) ? n0 : n1) /= 2;
        ((n0 % 3 == 0) ? n0 : (n1 % 3 == 0) ? n1 : n2) /= 3;
        return T(n0) * T(n1) * T(n2);
      } else static if (K == 3) {
        long n0 = n, n1 = n + 1;
        ((n0 % 2 == 0) ? n0 : n1) /= 2;
        return T(n0) * T(n0) * T(n1) * T(n1);
      } else {
        static assert(false, "PrimeSum: K is out of range");
      }
    }
    foreach (n; 1 .. sqrtN + 1) small[cast(int)(n)] = powerSum(n);
    foreach (l; 1 .. sqrtN + 1) large[cast(int)(l)] = powerSum(N / l);
    foreach (p; 2 .. sqrtN + 1) {
      if (isPrime[cast(int)(p)]) {
        for (long n = p^^2; n <= sqrtN; n += p) isPrime[cast(int)(n)] = false;
        const pk = T(p)^^K, g1 = get(p - 1);
        foreach (l; 1 .. sqrtN + 1) {
          const n = N / l;
          if (n < p^^2) break;
          large[cast(int)(l)] -= pk * (get(n / p) - g1);
        }
        foreach_reverse (n; 1 .. sqrtN + 1) {
          if (n < p^^2) break;
          small[cast(int)(n)] -= pk * (get(n / p) - g1);
        }
      }
    }
    small[1 .. $] -= T(1);
    large[1 .. $] -= T(1);
  }
  T get(long n) {
    return (n <= sqrtN) ? small[cast(int)(n)] : large[cast(int)(N / n)];
  }
}


void main() {
  try {
    for (; ; ) {
      const N = readLong();
      const A = readLong();
      const B = readLong();
      const C = readLong();
      const D = readLong();
      
      auto ps3 = new PrimeSum!(long, 3)(N);
      auto ps2 = new PrimeSum!(long, 2)(N);
      auto ps1 = new PrimeSum!(long, 1)(N);
      auto ps0 = new PrimeSum!(long, 0)(N);
      long get(long n) {
        return A * ps3.get(n) + B * ps2.get(n) + C * ps1.get(n) + D * ps0.get(n);
      }
      
      long ans;
      for (long a = 0, b; b < N; a = b) {
        const k = N / (a + 1);
        b = N / k;
        // (a, b]: k
        ans += k * (get(b) - get(a));
      }
      foreach (p; 2 .. ps0.sqrtN + 1) {
        if (ps0.isPrime[cast(int)(p)]) {
          const f = get(p) - get(p - 1);
          for (long n = N / p^^2; n >= 1; n /= p) {
            ans += n * f;
          }
        }
      }
      ans &= (1L << 32) - 1;
      writeln(ans);
    }
  } catch (EOFException e) {
  }
}