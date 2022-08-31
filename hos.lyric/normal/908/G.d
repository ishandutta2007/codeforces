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

enum MO = 10^^9 + 7;
alias Mint = ModInt!MO;


enum LIM = 2020;
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


enum LIM_L = 705;

void main() {
  prepare;
  
  auto pw = new Mint[][](10 + 1, LIM);
  foreach (a; 0 .. 10 + 1) {
    pw[a][0] = 1;
    foreach (e; 1 .. LIM) {
      pw[a][e] = pw[a][e - 1] * a;
    }
  }
  
  auto top = new Mint[][](10, LIM_L);
  auto bot = new Mint[][](10, LIM_L);
  foreach (d; 0 .. 10) {
    foreach (l; 0 .. LIM_L) {
      // a small, (l - a - b) same, b large
      // \sum_* d (10^(l-a) - 10^b)
      foreach (a; 0 .. l + 1) {
        top[d][l] += binom(l, a) * pw[d][a] * pw[10 - d][l - a] * d * pw[10][l - a];
      }
      foreach (b; 0 .. l + 1) {
        bot[d][l] += binom(l, b) * pw[d + 1][l - b] * pw[9 - d][b] * d * pw[10][b];
      }
    }
  }
  
  debug {
    foreach (d; 0 .. 10) {
      foreach (l; 0 .. 3 + 1) {
        Mint sum;
        foreach (n; 0 .. 10^^l) {
          auto cs = format("%0*d", l, n).dup;
          foreach (_; 0 .. l - 1) {
            foreach (i; 0 .. l - 1) {
              if (cs[i] > cs[i + 1]) {
                swap(cs[i], cs[i + 1]);
              }
            }
          }
          foreach (i; 0 .. l) {
            if (cs[i] - '0' == d) {
              sum += d * pw[10][l - 1 - i];
            }
          }
        }
        writeln(d, " ", l, ": ", top[d][l], " ", bot[d][l], " ", sum);
        assert(((top[d][l] - bot[d][l]) / 9).x == sum.x);
      }
    }
  }
  
  try {
    for (; ; ) {
      const X = readToken();
      const L = cast(int)(X.length);
      
      Mint ans;
      foreach (d; 0 .. 10) {
        int same, large;
        foreach (i; 0 .. L) {
          const x = X[i] - '0';
          foreach (e; 0 .. 10) {
            if ((i == L - 1) ? (e <= x) : (e < x)) {
              int same1 = same, large1 = large;
              if (e == d) {
                ++same1;
              } else if (e > d) {
                ++large1;
              }
              const l = L - 1 - i;
              debug {
                writeln(d, " ", i, " ", e, ": ", same1, " ", large1, " ", l);
              }
              ans += (top[d][l] * pw[10][same1] - bot[d][l]) * pw[10][large1];
            }
          }
          if (x == d) {
            ++same;
          } else if (x > d) {
            ++large;
          }
        }
      }
      ans /= 9;
      writeln(ans);
    }
  } catch (EOFException e) {
  }
}