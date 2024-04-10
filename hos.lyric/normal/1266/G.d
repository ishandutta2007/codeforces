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

struct SuffixArray(T) {
  import std.algorithm : sort;
  int n;
  T[] ts;
  int[] us, su, lcp;
  this(T)(T[] ts) {
    n = cast(int)(ts.length);
    this.ts = ts;
    us = new int[n + 1];
    su = new int[n + 1];
    foreach (i; 0 .. n + 1) us[i] = i;
    us.sort!((u, v) => (cmp(u, v) < 0));
    auto vals = new int[n + 1], cnt = new int[n + 1], tmp = new int[n + 1];
    foreach (i; 0 .. n) vals[i + 1] = vals[i] + ((cmp(us[i], us[i + 1]) < 0) ? 1 : 0);
    for (int h = 1; ; h <<= 1) {
      int ahead(int i) {
        return (us[i] + h <= n) ? su[us[i] + h] : 0;
      }
      foreach (i; 0 .. n + 1) su[us[i]] = vals[i];
      if (vals[n] == n) break;
      cnt[] = 0;
      foreach (i; 0 .. n + 1) ++cnt[ahead(i)];
      foreach (j; 0 .. n) cnt[j + 1] += cnt[j];
      foreach_reverse (i; 0 .. n + 1) tmp[--cnt[ahead(i)]] = us[i];
      cnt[] = 0;
      foreach (i; 0 .. n + 1) ++cnt[su[tmp[i]]];
      foreach (j; 0 .. n) cnt[j + 1] += cnt[j];
      foreach_reverse (i; 0 .. n + 1) us[--cnt[su[tmp[i]]]] = tmp[i];
      foreach (i; 0 .. n) vals[i + 1] = vals[i] + ((su[us[i]] < su[us[i + 1]] || ahead(i) < ahead(i + 1)) ? 1 : 0);
    }
    lcp = new int[n];
    int h;
    foreach (u; 0 .. n) {
      for (int v = us[su[u] - 1]; cmp(u + h, v + h) == 0; ++h) {}
      lcp[su[u] - 1] = h;
      if (h > 0) --h;
    }
  }
  int cmp(int u, int v) const {
    return (u == n) ? ((v == n) ? 0 : -1) : (v == n) ? +1 : (ts[u] < ts[v]) ? -1 : (ts[u] > ts[v]) ? +1 : 0;
  }
  void print() const {
    import std.math : log10;
    import std.stdio : writefln;
    const numDigits = cast(int)(log10(n)) + 1;
    foreach (i; 0 .. n + 1) {
      writefln("%*d %s", numDigits, us[i], ts[us[i] .. $]);
    }
  }
}

struct ModInt(int M_) {
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
      ModInt t2 = this, te = ModInt(1);
      for (long e = a; e; e >>= 1) {
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
  ModInt opUnary(string op)() const if (op == "-") { return ModInt(-x); }
  ModInt opBinary(string op, T)(T a) const { return mixin("ModInt(this) " ~ op ~ "= a"); }
  ModInt opBinaryRight(string op)(long a) const { return mixin("ModInt(a) " ~ op ~ "= this"); }
  string toString() const { return x.to!string; }
}

enum MO = 998244353;
alias Mint = ModInt!MO;

enum LIM = 10^^6 + 10;
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

void main() {
  prepare();
  
  debug {
    enum lim = 6;
    foreach (n; 1 .. lim + 1) {
      int[] ts;
      auto perm = iota(n).array;
      do {
        ts ~= perm;
      } while (perm.nextPermutation);
      const sa = new SuffixArray!int(ts);
      long ans;
      foreach (i; 0 .. sa.n) {
        ans += (sa.n - sa.us[i + 1] - sa.lcp[i]);
      }
      // writeln(sa.lcp);
      writeln(sa.lcp.dup.sort.group.map!"a[1]");
      writeln(sa.lcp.sum);
      writeln(ans);
      stdout.flush;
    }
    // return;
  }
  
  try {
    for (; ; ) {
      const N = readInt();
      Mint ans;
      if (N == 1) {
        ans = 1;
      } else if (N == 2) {
        ans = 8;
      } else {
        /*
          n = 3: [3, 5, 6, 3, 1];
        */
        Mint small = 6, smallSum = 2 * 6;
        Mint large = 0, largeSum = 0;
        foreach (n; 4 .. N + 1) {
          // (n - 1, 1)
          const head = Mint(n - 2)^^2 + 1;
          // (n - 1, n)
          Mint mid = Mint(n - 1) * fac[n - 1];
          mid -= Mint(n - 1);
          mid -= head;
          mid -= small;
          mid -= (fac[n - 1] - Mint(n - 1));
          mid -= large;
          debug {
            writefln("n = %s: head = %s, mid = %s", n, head, mid);
          }
          smallSum += 1 * small;
          smallSum += 2 * head;
          smallSum *= Mint(n);
          small += head;
          small *= Mint(n);
          largeSum += 2 * large;
          largeSum += Mint(n + 2) * mid;
          largeSum *= Mint(n);
          large += mid;
          large *= Mint(n);
          debug {
            writefln("n = %s: small = %s, smallSum = %s", n, small, smallSum);
            writefln("n = %s: large = %s, largeSum = %s", n, large, largeSum);
          }
        }
        {
          // (N, 1)
          const head = Mint(N - 1)^^2 + 1;
          // (N, N + 1)
          Mint mid = Mint(N) * fac[N];
          mid -= Mint(N);
          mid -= head;
          mid -= small;
          mid -= (fac[N] - Mint(N));
          mid -= large;
          debug {
            writefln("N: head = %s, mid = %s", head, mid);
          }
          Mint sum;
          sum += 0 * Mint(N);
          sum += 1 * head;
          sum += smallSum;
          sum += Mint(N) * (fac[N] - Mint(N));
          sum += Mint(N + 1) * mid;
          sum += largeSum;
          debug {
            writefln("N: sum = %s", sum);
          }
          const l = Mint(N) * fac[N];
          ans = l * (l + 1) * Mint(2).inv - sum;
        }
      }
      writeln(ans);
    }
  } catch (EOFException e) {
  }
}