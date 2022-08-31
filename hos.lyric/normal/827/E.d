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

alias Fft0 = Fft!(998244353, 3, 20);


void main() {
  const FFT = new Fft0;
  
  try {
    for (; ; ) {
      const numCases = readInt();
      foreach (caseId; 0 .. numCases) {
        const N = readInt();
        const S = readToken();
        
        auto fs = new int[N + 1];
        auto gs = new int[N + 1];
        foreach (i; 0 .. N) {
          switch (S[i]) {
            case 'V': ++fs[i]; break;
            case 'K': ++gs[N - i]; break;
            default: {}
          }
        }
        const hs = FFT.convolute(fs, gs);
        debug {
          writeln("hs = ", hs);
        }
        
        auto has = new bool[N + 1];
        foreach (x; -N .. +N + 1) {
          if (hs[N + x]) {
            has[abs(x)] = true;
          }
        }
        
        int[] ans;
        foreach (k; 1 .. N + 1) {
          bool ok = true;
          for (int l = k; l <= N; l += k) {
            ok = ok && !has[l];
          }
          if (ok) {
            ans ~= k;
          }
        }
        writeln(ans.length);
        foreach (index, k; ans) {
          if (index > 0) write(" ");
          write(k);
        }
        writeln;
      }
    }
  } catch (EOFException e) {
  }
}