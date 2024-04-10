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

enum MO = 1000000007;
alias Mint = ModInt!MO;


void main() {
  try {
    for (; ; ) {
      const S = readToken();
      const L = cast(int)(S.length);
      
      Mint ans;
      if (S.all!"a == '0'") {
        ans = L;
      } else {
        int a, b;
        for (; a < L && S[a] == '0'; ++a) {}
        for (; b < L && S[L - 1 - b] == '0'; ++b) {}
        debug {
          writeln("a = ", a, ", b = ", b);
        }
        const l = L - a - b;
        const s = S[a .. L - b];
        auto dp = new Mint[][](2, l + 1);
        auto dpSum = new Mint[][](2, l + 1 + 1);
        dp[0][0] = 1;
        dpSum[0][1] = 1;
        int zero;
        auto last0 = new int[l + 1];
        last0[] = -1;
        int last1 = -1;
        foreach (i; 0 .. l) {
          if (s[i] == '0') {
            ++zero;
            debug {
              writefln("0: [%s, %s) -> %s", last0[zero] + 1, i + 1, i + 1);
              assert(last0[zero] + 1 <= i + 1);
            }
            dp[0][i + 1] += dpSum[1][i + 1] - dpSum[1][last0[zero] + 1];
            last0[zero] = i + 1 - zero;
          } else {
            zero = 0;
            debug {
              writefln("1: [%s, %s) -> %s", last1 + 1, i + 1, i + 1);
              assert(last1 + 1 <= i + 1);
            }
            dp[1][i + 1] += dpSum[0][i + 1] - dpSum[0][last1 + 1];
            dp[1][i + 1] += dpSum[1][i + 1] - dpSum[1][last1 + 1];
            last1 = i;
          }
          foreach (h; 0 .. 2) {
            dpSum[h][i + 1 + 1] = dpSum[h][i + 1] + dp[h][i + 1];
          }
        }
        debug {
          writeln("dp = ", dp);
          writeln("dpSum = ", dpSum);
        }
        ans = dpSum[1][l + 1];
        ans *= (a + 1);
        ans *= (b + 1);
      }
      writeln(ans);
      
      debug {
        string ss = S;
        if (!ss.all!"a == '0'") {
          int a, b;
          for (; ss[0] == '0'; ss = ss[1 .. $]) ++a;
          for (; ss[$ - 1] == '0'; ss = ss[0 .. $ - 1]) ++b;
          const ssLen = cast(int)(ss.length);
          auto brtDp = new Mint[][](ssLen + 1, 2);
          brtDp[0][0] = 1;
          foreach (i; 0 .. ssLen) {
            // 0
            foreach (k; 1 .. ssLen + 1) {
              foreach (j; i .. ssLen - k + 1) {
                if (ss[j .. j + k].all!"a == '0'") {
                  // writefln("0: %s -> %s", i, j + k);
                  brtDp[j + k][0] += brtDp[i][1];
                  break;
                }
              }
            }
            // 1
            foreach (j; i .. ssLen) {
              if (ss[j] == '1') {
                // writefln("1: %s -> %s", i, j + 1);
                brtDp[j + 1][1] += brtDp[i][0];
                brtDp[j + 1][1] += brtDp[i][1];
                break;
              }
            }
          }
          Mint brt;
          foreach (i; 1 .. ssLen + 1) {
            brt += brtDp[i][1];
          }
          brt *= (a + 1);
          brt *= (b + 1);
          writeln("ss = ", ss);
          writeln("brtDp = ", brtDp);
          writeln("brt = ", brt);
        }
      }
      
      debug {
        if (S.length <= 16) {
          bool[string] vis;
          void dfs(string s) {
            if (s !in vis) {
              vis[s] = true;
              const len = cast(int)(s.length);
              foreach (i; 0 .. len - 1) {
                dfs(s[0 .. i] ~ max(s[i], s[i + 1]) ~ s[i + 2 .. len]);
              }
            }
          }
          dfs(S);
          writeln("|vis| = ", vis.length);
          assert(ans.x == vis.length);
        }
      }
    }
  } catch (EOFException e) {
  }
}