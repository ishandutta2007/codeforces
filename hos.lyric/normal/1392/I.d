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


// a^-1 (mod m)
long modInv(long a, long m)
in {
  assert(m > 0, "modInv: m > 0 must hold");
}
do {
  long b = m, x = 1, y = 0, t;
  for (; ; ) {
    t = a / b; a -= t * b;
    if (a == 0) {
      assert(b == 1 || b == -1, "modInv: gcd(a, m) != 1");
      if (b == -1) y = -y;
      return (y < 0) ? (y + m) : y;
    }
    x -= t * y;
    t = b / a; b -= t * a;
    if (b == 0) {
      assert(a == 1 || a == -1, "modInv: gcd(a, m) != 1");
      if (a == -1) x = -x;
      return (x < 0) ? (x + m) : x;
    }
    y -= t * x;
  }
}
 
// M: prime, G: primitive root
class Fft(int M_, int G, int K) {
  import std.algorithm : reverse;
  import std.traits : isIntegral;
  alias M = M_;
  // 1, 1/4, 1/8, 3/8, 1/16, 5/16, 3/16, 7/16, ...
  int[] gs;
  this() {
    static assert(2 <= K && K <= 30, "Fft: 2 <= K <= 30 must hold");
    static assert(!((M - 1) & ((1 << K) - 1)), "Fft: 2^K | M - 1 must hold");
    gs = new int[1 << (K - 1)];
    gs[0] = 1;
    long g2 = G, gg = 1;
    for (int e = (M - 1) >> K; e; e >>= 1) {
      if (e & 1) gg = (gg * g2) % M;
      g2 = (g2 * g2) % M;
    }
    gs[1 << (K - 2)] = cast(int)(gg);
    for (int l = 1 << (K - 2); l >= 2; l >>= 1) {
      gs[l >> 1] = cast(int)((cast(long)(gs[l]) * gs[l]) % M);
    }
    assert((cast(long)(gs[1]) * gs[1]) % M == M - 1,
           "Fft: g^(2^(K-1)) == -1 (mod M) must hold");
    for (int l = 2; l <= 1 << (K - 2); l <<= 1) {
      foreach (i; 1 .. l) {
        gs[l + i] = cast(int)((cast(long)(gs[l]) * gs[i]) % M);
      }
    }
  }
  void fft(int[] xs) const {
    const n = cast(int)(xs.length);
    assert(!(n & (n - 1)), "Fft.fft: |xs| must be a power of two");
    assert(n <= 1 << K, "Fft.fft: |xs| <= 2^K must hold");
    for (int l = n; l >>= 1; ) {
      foreach (i; 0 .. (n >> 1) / l) {
        const(long) g = gs[i];
        foreach (j; (i << 1) * l .. (i << 1 | 1) * l) {
          const t = cast(int)((g * xs[j + l]) % M);
          if ((xs[j + l] = xs[j] - t) < 0) xs[j + l] += M;
          if ((xs[j] += t) >= M) xs[j] -= M;
        }
      }
    }
  }
  void invFft(int[] xs) const {
    const n = cast(int)(xs.length);
    assert(!(n & (n - 1)), "Fft.invFft: |xs| must be a power of two");
    assert(n <= 1 << K, "Fft.invFft: |xs| <= 2^K must hold");
    for (int l = 1; l < n; l <<= 1) reverse(xs[l .. l << 1]);
    for (int l = 1; l < n; l <<= 1) {
      foreach (i; 0 .. (n >> 1) / l) {
        const(long) g = gs[i];
        foreach (j; (i << 1) * l .. (i << 1 | 1) * l) {
          int t = cast(int)((g * (xs[j] - xs[j + l])) % M);
          if (t < 0) t += M;
          if ((xs[j] += xs[j + l]) >= M) xs[j] -= M;
          xs[j + l] = t;
        }
      }
    }
  }
  T[] convolute(T)(inout(T)[] as, inout(T)[] bs) const if (isIntegral!T) {
    const na = cast(int)(as.length), nb = cast(int)(bs.length);
    int n, invN = 1;
    for (n = 1; n < na + nb - 1; n <<= 1) {
      invN = ((invN & 1) ? (invN + M) : invN) >> 1;
    }
    auto xs = new int[n], ys = new int[n];
    foreach (i; 0 .. na) if ((xs[i] = cast(int)(as[i] % M)) < 0) xs[i] += M;
    foreach (i; 0 .. nb) if ((ys[i] = cast(int)(bs[i] % M)) < 0) ys[i] += M;
    fft(xs);
    fft(ys);
    foreach (i; 0 .. n) {
      xs[i] = cast(int)((((cast(long)(xs[i]) * ys[i]) % M) * invN) % M);
    }
    invFft(xs);
    auto cs = new T[na + nb - 1];
    foreach (i; 0 .. na + nb - 1) cs[i] = cast(T)(xs[i]);
    return cs;
  }
}
 
 
enum FFT_K = 20;
alias Fft3_0 = Fft!(1045430273, 3, FFT_K);  // 2^20 997 + 1
alias Fft3_1 = Fft!(1051721729, 6, FFT_K);  // 2^20 1003 + 1
alias Fft3_2 = Fft!(1053818881, 7, FFT_K);  // 2^20 1005 + 1
 
enum long FFT_INV01 = modInv(Fft3_0.M, Fft3_1.M);
enum long FFT_INV012 = modInv(cast(long)(Fft3_0.M) * Fft3_1.M, Fft3_2.M);
Fft3_0 FFT3_0;
Fft3_1 FFT3_1;
Fft3_2 FFT3_2;
void initFft3() {
  FFT3_0 = new Fft3_0;
  FFT3_1 = new Fft3_1;
  FFT3_2 = new Fft3_2;
}
long[] convolute(inout(long)[] as, inout(long)[] bs) {
  const cs0 = FFT3_0.convolute(as, bs);
  const cs1 = FFT3_1.convolute(as, bs);
  const cs2 = FFT3_2.convolute(as, bs);
  auto cs = new long[cs0.length];
  foreach (i; 0 .. cs0.length) {
    long d0 = cs0[i] % Fft3_0.M;
    long d1 = (FFT_INV01 * (cs1[i] - d0)) % Fft3_1.M;
    if (d1 < 0) d1 += Fft3_1.M;
    long d2 =
        (FFT_INV012 * ((cs2[i] - d0 - Fft3_0.M * d1) % Fft3_2.M)) % Fft3_2.M;
    if (d2 < 0) d2 += Fft3_2.M;
    cs[i] = d0 + Fft3_0.M * d1 + (cast(long)(Fft3_0.M) * Fft3_1.M) * d2;
  }
  return cs;
}

/*
  1 pt: for comp
  2 pt: for comp, for enclosing non-empty face (opposite sign)
  F': empty face (<=> 2x2)
  
  (C_{>=} - (F_{>=} - F'_{>=})) - (C_< - (F_< - F'_<))
  = (V_{>=} - E_{>=} + F'_{>=}) - (V_< - E_< + F'_<)
*/
void main() {
  enum MMM = 1L * Fft3_0.M * Fft3_1.M * Fft3_2.M;
  initFft3;
  
  try {
    for (; ; ) {
      const M = readInt();
      const N = readInt();
      const Q = readInt();
      auto A = new int[M];
      foreach (x; 0 .. M) {
        A[x] = readInt();
      }
      auto B = new int[N];
      foreach (y; 0 .. N) {
        B[y] = readInt();
      }
      auto C = new int[Q];
      foreach (q; 0 .. Q) {
        C[q] = readInt();
      }
      
      auto ans = new long[Q];
      
      const AMax = A.maxElement;
      const BMax = B.maxElement;
      foreach (s; [+1, -1]) {
        auto fs = new long[AMax + 1];
        auto gs = new long[BMax + 1];
        foreach (x; 0 .. M) {
          ++fs[A[x]];
        }
        foreach (x; 0 .. M - 1) {
          --fs[max(A[x], A[x + 1])];
        }
        foreach (y; 0 .. N) {
          ++gs[B[y]];
        }
        foreach (y; 0 .. N - 1) {
          --gs[max(B[y], B[y + 1])];
        }
        auto hs = convolute(fs, gs);
        foreach (i; 0 .. AMax + BMax + 1) {
          if (!(0 <= hs[i] && hs[i] <= 4L * M * N)) {
            hs[i] -= MMM;
          }
        }
        debug {
          writeln("fs = ", fs);
          writeln("gs = ", gs);
          writeln("hs = ", hs);
        }
        hs ~= 0;
        foreach_reverse (i; 0 .. AMax + BMax + 1) {
          hs[i] += hs[i + 1];
        }
        foreach (q; 0 .. Q) {
          ans[q] += s * hs[min(max(C[q], 0), AMax + BMax + 1)];
        }
        
        foreach (x; 0 .. M) {
          A[x] = AMax - A[x];
        }
        foreach (y; 0 .. N) {
          B[y] = BMax - B[y];
        }
        foreach (q; 0 .. Q) {
          C[q] = AMax + BMax - (C[q] - 1);
        }
      }
      
      foreach (q; 0 .. Q) {
        writeln(ans[q]);
      }
    }
  } catch (EOFException e) {
  }
}