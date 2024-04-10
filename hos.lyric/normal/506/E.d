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

enum MO = 10007;
alias Mint = ModInt!MO;


enum LIM = 1010;
Mint[] inv, fac, invFac;
void prepare() {
  inv = new Mint[LIM];
  fac = new Mint[LIM];
  invFac = new Mint[LIM];
  inv[1] = 1;
  foreach (i; 2 .. LIM) {
    inv[i] = -((Mint.M / i) * inv[cast(size_t)(Mint.M % i)]);
  }
  fac[0] = invFac[0] = 1;
  foreach (i; 1 .. LIM) {
    fac[i] = fac[i - 1] * i;
    invFac[i] = invFac[i - 1] * inv[i];
  }
}
Mint binom(long n, long k) {
  if (n < 0) {
    if (k >= 0) {
      return (-1)^^(k & 1) * binom(-n + k - 1, k);
    } else if (n - k >= 0) {
      return (-1)^^((n - k) & 1) * binom(-k - 1, n - k);
    } else {
      return Mint(0);
    }
  } else {
    if (0 <= k && k <= n) {
      assert(n < LIM);
      return fac[cast(size_t)(n)] * invFac[cast(size_t)(k)] * invFac[cast(size_t)(n - k)];
    } else {
      return Mint(0);
    }
  }
}


enum C = Mint(25) / Mint(26);
enum D = Mint(24) / Mint(26);

/*
  \sum_{x+y=m} multichoose(a, x) multichoose(b, y) 26^(m-x-y) 25^x 24^y
*/
Mint calcEQBrute(int a, int b, long m) {
  Mint ret;
  foreach (x; 0 .. m + 1) {
    const y = m - x;
    ret += binom(a + x - 1, x) * binom(b + y - 1, y) * Mint(25)^^x * Mint(24)^^y;
  }
  return ret;
}
Mint calcEQ(int a, int b, long m) {
  Mint ret;
  if (a == 0) {
    if (b == 0) {
      ret = (m == 0) ? 1 : 0;
    } else {
      /*
        binom(m + b - 1, b - 1) (24/26)^m
      */
      ret = D^^m;
      foreach (j; 0 .. b - 1) ret = ret * (m + b - 1 - j) * inv[1 + j];
    }
  } else {
    if (b == 0) {
      /*
        binom(m + a - 1, a - 1) (25/26)^m
      */
      ret = C^^m;
      foreach (i; 0 .. a - 1) ret = ret * (m + a - 1 - i) * inv[1 + i];
    } else {
      /*
        \sum_{x+y=m+a-1+b-1} p^x q^y
        = (p^(m+a+b-1) - q^(m+a+b-1)) / (p - q)
        
        ((p+25/26)^(m+a+b-1) - (q+24/26)^(m+a+b-1)) / (p - q + 1/26)
      */
      auto gss = new Mint[][](a + 1, b + 1);
      {
        Mint bn = 1;
        foreach (i; 0 .. a) {
          if (m + a + b - 1 - i >= 0) gss[i][0] += bn * C^^(m + a + b - 1 - i);
          bn = bn * (m + a + b - 1 - i) * inv[1 + i];
        }
      }
      {
        Mint bn = 1;
        foreach (j; 0 .. b) {
          if (m + a + b - 1 - j >= 0) gss[0][j] -= bn * D^^(m + a + b - 1 - j);
          bn = bn * (m + a + b - 1 - j) * inv[1 + j];
        }
      }
      foreach (i; 0 .. a) foreach (j; 0 .. b) {
        gss[i][j] *= 26;
        gss[i + 1][j] -= gss[i][j];
        gss[i][j + 1] += gss[i][j];
      }
      ret = gss[a - 1][b - 1];
    }
  }
  ret *= Mint(26)^^m;
  debug {
    const brt = calcEQBrute(a, b, m);
    assert(brt == ret, format("EQ %s %s %s: %s %s", a, b, m, brt, ret));
  }
  return ret;
}

/*
  \sum_{x+y<=m} multichoose(a, x) multichoose(b, y) 26^(m-x-y) 25^x 24^y
*/
Mint calcLEBrute(int a, int b, long m) {
  Mint ret;
  foreach (x; 0 .. m + 1) foreach (y; 0 .. m - x + 1) {
    ret += binom(a + x - 1, x) * binom(b + y - 1, y) * Mint(26)^^(m - x - y) * Mint(25)^^x * Mint(24)^^y;
  }
  return ret;
}
Mint calcLE(int a, int b, long m) {
  Mint ret;
  if (a == 0) {
    if (b == 0) {
      ret = 1;
    } else {
      /*
        \sum_{y<=m+b-1} q^y
        = (q^(m+b) - 1) / (q - 1)
        
        ((q+24/26)^(m+b) - 1) / (q - 2/26)
      */
      auto hs = new Mint[b + 1];
      Mint bn = 1;
      foreach (j; 0 .. b) {
        if (m + b - j >= 0) hs[j] += bn * D^^(m + b - j);
        bn = bn * (m + b - j) * inv[1 + j];
      }
      hs[0] -= 1;
      foreach (j; 0 .. b) {
        hs[j] *= -13;
        hs[j + 1] -= hs[j];
      }
      ret = hs[b - 1];
    }
  } else {
    if (b == 0) {
      /*
        \sum_{x<=m+a-1} p^x
        = (p^(m+a) - 1) / (q - 1)
        
        ((p+25/26)^(m+a) - 1) / (p - 1/26)
      */
      auto hs = new Mint[a + 1];
      Mint bn = 1;
      foreach (i; 0 .. a) {
        if (m + a - i >= 0) hs[i] += bn * C^^(m + a - i);
        bn = bn * (m + a - i) * inv[1 + i];
      }
      hs[0] -= 1;
      foreach (i; 0 .. a) {
        hs[i] *= -26;
        hs[i + 1] -= hs[i];
      }
      ret = hs[a - 1];
    } else {
      /*
        \sum_{x+y<=m+a-1+b-1} p^x q^y
        = ((p^(m+a+b) - p) / (p - 1) - (q^(n+a+b) - q) / (q - 1)) / (p - q)
        
        (((p+25/26)^(m+a+b) - p - 25/26) / (p - 1/26) - ((q+24/26)^(n+a+b) - q - 24/26) / (q - 2/26)) / (p - q + 1/26)
      */
      auto gss = new Mint[][](a + 1, b + 1);
      {
        auto hs = new Mint[a + 1];
        Mint bn = 1;
        foreach (i; 0 .. a) {
          if (m + a + b - i >= 0) hs[i] += bn * C^^(m + a + b - i);
          bn = bn * (m + a + b - i) * inv[1 + i];
        }
        hs[1] -= 1;
        hs[0] -= C;
        foreach (i; 0 .. a) {
          hs[i] *= -26;
          hs[i + 1] -= hs[i];
        }
        foreach (i; 0 .. a) gss[i][0] += hs[i];
      }
      {
        auto hs = new Mint[b + 1];
        Mint bn = 1;
        foreach (j; 0 .. b) {
          if (m + a + b - j >= 0) hs[j] += bn * D^^(m + a + b - j);
          bn = bn * (m + a + b - j) * inv[1 + j];
        }
        hs[1] -= 1;
        hs[0] -= D;
        foreach (j; 0 .. b) {
          hs[j] *= -13;
          hs[j + 1] -= hs[j];
        }
        foreach (j; 0 .. b) gss[0][j] -= hs[j];
      }
      foreach (i; 0 .. a) foreach (j; 0 .. b) {
        gss[i][j] *= 26;
        gss[i + 1][j] -= gss[i][j];
        gss[i][j + 1] += gss[i][j];
      }
      ret = gss[a - 1][b - 1];
    }
  }
  ret *= Mint(26)^^m;
  debug {
    const brt = calcLEBrute(a, b, m);
    assert(brt == ret, format("LE %s %s %s: %s %s", a, b, m, brt, ret));
  }
  return ret;
}

void main() {
  prepare;
  
  debug {
    enum lim = 10;
    foreach (a; 0 .. lim) foreach (b; 0 .. lim) foreach (m; 0 .. lim) {
      calcEQ(a, b, m);
      calcLE(a, b, m);
    }
  }
  
  try {
    for (; ; ) {
      const S = readToken();
      const N = readLong();
      const L = cast(int)(S.length);
      
      // a pairs, b singles, 1 remaining
      auto fs1 = new Mint[L + 1];
      foreach (a; 0 .. L + 1) {
        const b = L - 1 - 2 * a;
        if (b >= 0) {
          // one more 25-chance
          if (N - 1 - b >= 0) {
            fs1[a] += calcLE(a + 1, b, (N - 1 - b) / 2);
            if ((L + N) & 1) {
              fs1[a] *= 26;
            }
          }
          // 1 remaining for center
          if (N - b >= 0 && ((L + N) & 1)) {
            // fs1[a] += calcEQ(a + 1, b, (N - b) / 2);
            fs1[a] += calcLE(a + 1, b, (N - b) / 2) - 26 * calcLE(a + 1, b, (N - b) / 2 - 1);
          }
        }
      }
      debug {
        writeln("fs1 = ", fs1);
      }
      
      // a pairs, b singles, 0 remaining
      auto fs0 = new Mint[L + 1];
      foreach (a; 0 .. L + 1) {
        const b = L - 2 * a;
        if (b >= 0) {
          if (N - b >= 0) {
            fs0[a] += calcLE(a, b, (N - b) / 2);
            if ((L + N) & 1) {
              fs0[a] *= 26;
            }
          }
        }
      }
      debug {
        writeln("fs0 = ", fs0);
      }
      
      auto dp = new Mint[][][](L + 1, L + 1, L + 1);
      dp[0][L][0] = 1;
      foreach_reverse (w; 2 .. L + 1) {
        foreach (i; 0 .. L - w + 1) {
          const j = i + w;
          foreach (a; 0 .. L - w + 1) {
            if (S[i] == S[j - 1]) {
              dp[i + 1][j - 1][a + 1] += dp[i][j][a];
              // 25
            } else {
              dp[i + 1][j][a] += dp[i][j][a];
              dp[i][j - 1][a] += dp[i][j][a];
              // 24
            }
          }
        }
      }
      
      Mint ans;
      foreach (i; 0 .. L - 1 + 1) {
        foreach (a; 0 .. L - 1 + 1) {
          ans += dp[i][i + 1][a] * fs1[a];
        }
      }
      foreach (i; 0 .. L + 1) {
        foreach (a; 0 .. L + 1) {
          ans += dp[i][i][a] * fs0[a];
        }
      }
      writeln(ans);
      
      debug {
        if (L + N <= 8) {
          const n = cast(int)(L + N);
          int brt;
          foreach (p; 0 .. 26^^((n + 1) / 2)) {
            auto cs = new char[n];
            foreach (h; 0 .. (n + 1) / 2) {
              cs[h] = cast(char)('a' + p / 26^^h % 26);
            }
            foreach (h; (n + 1) / 2 .. n) {
              cs[h] = cs[n - 1 - h];
            }
            {
              int h;
              foreach (i; 0 .. L) {
                for (; h < n && cs[h] != S[i]; ++h) {}
                if (h == n) {
                  goto failed;
                }
                ++h;
              }
            }
            ++brt;
           failed:
          }
          writefln("brt = %s == %s", brt, Mint(brt));
          assert(Mint(brt) == ans);
        }
      }
    }
  } catch (EOFException e) {
  }
}