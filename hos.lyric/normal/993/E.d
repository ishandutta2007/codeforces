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

class Fft(int K) {
  // 1, 1/4, 1/8, 3/8, 1/16, 5/16, 3/16, 7/16, ...
  Complex!real[] g;
  this() {
    static assert(K >= 2, "Fft: K >= 2 must hold");
    g.length = 1 << (K - 1);
    g[0] = 1;
    g[1 << (K - 2)] = fromPolar(1.0L, (2.0L * PI) / (1 << K));
    for (int l = 1 << (K - 2); l >= 2; l >>= 1) {
      g[l >> 1] = g[l] * g[l];
    }
    for (int l = 2; l <= 1 << (K - 2); l <<= 1) {
      for (int i = 1; i < l; ++i) {
        g[l + i] = g[l] * g[i];
      }
    }
  }
  void fft(Complex!real[] x) const {
    const n = cast(int)(x.length);
    assert(!(n & (n - 1)) && n <= 1 << K);
    for (int l = n; l >>= 1; ) {
      for (int i = 0; i < (n >> 1) / l; ++i) {
        for (int j = (i << 1) * l; j < (i << 1 | 1) * l; ++j) {
          const t = g[i] * x[j + l];
          x[j + l] = x[j] - t;
          x[j] += t;
        }
      }
    }
    for (int i = 0, j = 0; i < n; ++i) {
      if (i < j) swap(x[i], x[j]);
      for (int l = n; (l >>= 1) && !((j ^= l) & l); ) {}
    }
  }
}
enum FFT_K = 19;
Fft!FFT_K FFT;



void main() {
  FFT = new Fft!FFT_K();
  
  try {
    for (; ; ) {
      const N = readInt();
      const X = readInt();
      auto A = new int[N];
      foreach (i; 0 .. N) {
        A[i] = readInt();
      }
      
      auto ss = new int[N + 1];
      foreach (i; 0 .. N) {
        ss[i + 1] = ss[i] + ((A[i] < X) ? 1 : 0);
      }
      debug {
        writeln("ss = ", ss);
      }
      
      auto fs = new Complex!real[1 << FFT_K];
      auto gs = new Complex!real[1 << FFT_K];
      fs[] = complex(0.0L, 0.0L);
      gs[] = complex(0.0L, 0.0L);
      foreach (i; 0 .. N + 1) {
        fs[ss[i]] += 1.0L;
        gs[N - ss[i]] += 1.0L;
      }
      FFT.fft(fs);
      FFT.fft(gs);
      foreach (j; 0 .. 1 << FFT_K) {
        fs[j] *= gs[j] / (1 << FFT_K);
      }
      fs[1 .. $].reverse;
      FFT.fft(fs);
      auto ans = new long[N + 1];
      foreach (k; 1 .. N + 1) {
        ans[k] = cast(long)(fs[N + k].re + 0.5L);
      }
      ans[0] = 1L * N * (N + 1) / 2 - ans[1 .. N + 1].sum;
      
      foreach (k; 0 .. N + 1) {
        if (k > 0) write(" ");
        write(ans[k]);
      }
      writeln();
    }
  } catch (EOFException e) {
  }
}