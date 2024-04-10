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


struct ModInt(int M_) {
  import std.conv : to;
  alias M = M_;
  int x;
  this(ModInt a) { x = a.x; }
  this(long a) { x = cast(int)(a % M); if (x < 0) x += M; }
  ref ModInt opAssign(long a) { return (this = ModInt(a)); }
  ref ModInt opOpAssign(string op)(ModInt a) {
    static if (op == "+") { x += a.x; if (x >= M) x -= M; }
    else static if (op == "-") { x -= a.x; if (x < 0) x += M; }
    else static if (op == "*") { x = cast(int)((cast(long)(x) * a.x) % M); }
    else static if (op == "/") { this *= a.inv(); }
    else static assert(false);
    return this;
  }
  ref ModInt opOpAssign(string op)(long a) {
    static if (op == "^^") {
      if (a < 0) return (this = inv()^^(-a));
      ModInt t2 = this, te = ModInt(1);
      for (long e = a; e > 0; e >>= 1) {
        if (e & 1) te *= t2;
        t2 *= t2;
      }
      x = cast(int)(te.x);
      return this;
    } else return mixin("this " ~ op ~ "= ModInt(a)");
  }
  ModInt inv() const {
    int a = x, b = M, y = 1, z = 0, t;
    for (; ; ) {
      t = a / b; a -= t * b;
      if (a == 0) {
        assert(b == 1 || b == -1);
        return ModInt(b * z);
      }
      y -= t * z;
      t = b / a; b -= t * a;
      if (b == 0) {
        assert(a == 1 || a == -1);
        return ModInt(a * y);
      }
      z -= t * y;
    }
  }
  ModInt opUnary(string op: "-")() const { return ModInt(-x); }
  ModInt opBinary(string op, T)(T a) const {
    return mixin("ModInt(this) " ~ op ~ "= a");
  }
  ModInt opBinaryRight(string op)(long a) const {
    return mixin("ModInt(a) " ~ op ~ "= this");
  }
  bool opCast(T: bool)() const { return (x != 0); }
  string toString() const { return x.to!string; }
}

enum MO = 998244353;
alias Mint = ModInt!MO;

enum LIM = 10^^5 + 10;
Mint[] inv, fac, invFac;
void prepare() {
  inv = new Mint[LIM];
  fac = new Mint[LIM];
  invFac = new Mint[LIM];
  inv[1] = 1;
  foreach (i; 2 .. LIM) {
    inv[i] = -(Mint.M / i) * inv[cast(size_t)(Mint.M % i)];
  }
  fac[0] = invFac[0] = 1;
  foreach (i; 1 .. LIM) {
    fac[i] = fac[i - 1] * i;
    invFac[i] = invFac[i - 1] * inv[i];
  }
}
Mint binom(long n, long k) {
  if (0 <= k && k <= n) {
    assert(n < LIM);
    return fac[cast(size_t)(n)] * invFac[cast(size_t)(k)] * invFac[cast(size_t)(n - k)];
  } else {
    return Mint(0);
  }
}


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
  ModInt!M[] convolute(inout(ModInt!M)[] as, inout(ModInt!M)[] bs) const {
    const na = cast(int)(as.length), nb = cast(int)(bs.length);
    int n, invN = 1;
    for (n = 1; n < na + nb - 1; n <<= 1) {
      invN = ((invN & 1) ? (invN + M) : invN) >> 1;
    }
    auto xs = new int[n], ys = new int[n];
    foreach (i; 0 .. na) xs[i] = as[i].x;
    foreach (i; 0 .. nb) ys[i] = bs[i].x;
    fft(xs);
    fft(ys);
    foreach (i; 0 .. n) {
      xs[i] = cast(int)((((cast(long)(xs[i]) * ys[i]) % M) * invN) % M);
    }
    invFft(xs);
    auto cs = new ModInt!M[na + nb - 1];
    foreach (i; 0 .. na + nb - 1) cs[i].x = xs[i];
    return cs;
  }
  int[] convolute(int M1)(inout(ModInt!M1)[] as, inout(ModInt!M1)[] bs) const
      if (M != M1) {
    const na = cast(int)(as.length), nb = cast(int)(bs.length);
    int n, invN = 1;
    for (n = 1; n < na + nb - 1; n <<= 1) {
      invN = ((invN & 1) ? (invN + M) : invN) >> 1;
    }
    auto xs = new int[n], ys = new int[n];
    foreach (i; 0 .. na) xs[i] = as[i].x;
    foreach (i; 0 .. nb) ys[i] = bs[i].x;
    fft(xs);
    fft(ys);
    foreach (i; 0 .. n) {
      xs[i] = cast(int)((((cast(long)(xs[i]) * ys[i]) % M) * invN) % M);
    }
    invFft(xs);
    return xs[0 .. na + nb - 1];
  }
}

alias Fft0 = Fft!(998244353, 3, 20);


/*
  Pr[large piece after m cuts]
  = 1 - \prod_{m[1]+...+m[N]=m} m!/(m[1]!...m[N]!) \prod_{i=1}^N (L[i]/L)^m[i] Pr[no large piece after m[i] cuts on the i-th chocolate]
  
  \sum_{m>=0} (L[i]/L)^m Pr[no large piece after m cuts on the i-th chocolate] x^m/m!
  = \sum_{m>=0} (L[i]/L)^m (\sum_{j: L[i]-Kj>0} binom(m+1, j) (-1)^j ((L[i]-Kj)/L[i])^m) x^m/m!
  = \sum_{j: L[i]-Kj>0} \sum_m binom(m+1, j) (-1)^j (((L[i]-Kj)/L) x)^m / m!
  = \sum_{m>=0} ((L[i]/L) x)^m / m! + \sum_{j>=1: L[i]-Kj>0} (-1)^j/j! \sum_{m>=j-1} (m+1)/((m-j+1)!) (((L[i]-Kj)/L) x)^m
  |
  | \sum_{m>=j-1} (m+1)/((m-j+1)!) X^m
  | = \sum_{m>=0} (m+j)/m! X^(m+j-1)
  | = \sum_{m>=1} 1/(m-1)! X^(m+j-1) + j \sum_{m>=0} (j/m!) X^(m+j-1)
  | = exp(X) (X^j + j X^(j-1))
  |
  = exp((L[i]/L) x) + (-1)^j/j! \sum_{j>=1: L[i]-Kj>0} exp(((L[i]-Kj)/L) x) ((((L[i]-Kj)/L) x)^j + j (((L[i]-Kj)/L) x)^(j-1))
  |
  | y := exp(-(K/L) x) x
  | c[i] := (L[i]-Kj)/L
  |
  = exp((L[i]/L) x) (1 + \sum_{j>=1: L[i]-Kj>0} (-1)^j/j! y^j (c[i]^j + j c[i]^(j-1) x^-1))
  
  \sum_{m\ge0} Pr[large piece after m cuts]
  = exp(x) - exp(x) \prod_{i=1}^N (1 + \sum_{j>=1: L[i]-Kj>0} (-1)^j/j! y^j (c[i]^j + j c[i]^(j-1) x^-1))
*/

Fft0 FFT;
Mint[][] mul(Mint[][] fss, Mint[][] gss) {
  const mf = cast(int)(fss.length), nf = cast(int)(fss[0].length);
  const mg = cast(int)(gss.length), ng = cast(int)(gss[0].length);
  const m = mf + mg - 1, n = nf + ng - 1;
  auto fs = new Mint[m * n];
  auto gs = new Mint[m * n];
  foreach (i; 0 .. mf) foreach (j; 0 .. nf) fs[i * n + j] = fss[i][j];
  foreach (i; 0 .. mg) foreach (j; 0 .. ng) gs[i * n + j] = gss[i][j];
  const hs = FFT.convolute(fs, gs);
  auto hss = new Mint[][](m, n);
  foreach (i; 0 .. m) foreach (j; 0 .. n) hss[i][j] = hs[i * n + j];
  return hss;
}

void main() {
  prepare;
  FFT = new Fft0;
  
  try {
    for (; ; ) {
      const N = readInt();
      const K = readInt();
      auto L = new int[N];
      foreach (i; 0 .. N) {
        L[i] = readInt();
      }
      
      const LSum = L.sum;
      
      // rectangular
      auto fsss = new Mint[][][2 * N - 1];
      foreach (i; 0 .. N) {
        const jLim = (L[i] + K - 1) / K;
        fsss[i] = new Mint[][](jLim, 2);
        fsss[i][0][0] = 1;
        foreach (j; 1 .. jLim) {
          const c = Mint(L[i] - K * j) / Mint(LSum);
          fsss[i][j][0] = (-1)^^(j & 1) * invFac[j] * c^^j;
          fsss[i][j][1] = (-1)^^(j & 1) * invFac[j] * j * c^^(j - 1);
        }
      }
      foreach (i; N .. 2 * N - 1) {
        fsss[i] = mul(fsss[(i - N) << 1], fsss[(i - N) << 1 | 1]);
      }
      const fss = fsss[$ - 1];
      debug {
        if (LSum / K <= 20) {
          writeln("fss = ", fss);
        }
      }
      
      Mint ans;
      foreach (j; 1 .. cast(int)(fss.length)) {
        foreach (h; 0 .. cast(int)(fss[j].length)) {
          /*
            exp((1 - (K/L) j) x) x^(j-h)
            
            \sum_m m! [x^m] exp(r x) x^a
            = \sum_m (m+a)!/m! r^m
            = a! / (1 - r)^(a+1)
          */
          if (j - h >= 0) {
            const r = Mint(1) - Mint(K) / Mint(LSum) * Mint(j);
            const a = j - h;
            debug {
              if (LSum / K <= 20) {
                writeln(r, " ", a, ": ", fss[j][h]);
              }
            }
            ans -= (fac[a] / (1 - r)^^(a + 1)) * fss[j][h];
          } else {
            assert(!fss[j][h]);
          }
        }
      }
      writeln(ans);
    }
  } catch (EOFException e) {
  }
}