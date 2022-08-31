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

enum MO = 10^^9 + 7;
alias Mint = ModInt!MO;


class Eertree(int size, char offset) {
  string s;
  int n;
  int[] us, len, fail, slink;
  int[] next;
  this(in string s) {
    this.s = s;
    n = cast(int)(s.length);
    us = new int[n + 3];
    len = new int[n + 3];
    fail = new int[n + 3];
    slink = new int[n + 3];
    next = new int[(n + 3) * size];
    us[1] = 1; len[1] = -1; fail[1] = 1; slink[1] = 1;
    us[2] = 2; len[2] =  0; fail[2] = 1; slink[2] = 1;
    foreach (i; 0 .. n) {
      const c = s[i] - offset;
      int u = us[i + 2];
      for (; !isSuffix(i, u); u = fail[u]) {}
      if (!next[u * size + c]) {
        next[u * size + c] = i + 3;
        len[i + 3] = len[u] + 2;
        if (u == 1) {
          fail[i + 3] = 2;
          slink[i + 3] = 2;
        } else {
          int v = fail[u];
          for (; !isSuffix(i, v); v = fail[v]) {}
          fail[i + 3] = next[v * size + c];
          slink[i + 3] = (len[i + 3] - len[fail[i + 3]] == len[fail[i + 3]] - len[fail[fail[i + 3]]]) ? slink[fail[i + 3]] : fail[i + 3];
        }
      }
      us[i + 3] = next[u * size + c];
    }
  }
  bool isSuffix(int i, int u) const {
    const j = i - 1 - len[u];
    return (j >= 0 && s[j] == s[i]);
  }
  void print() const {
    void dfs(int u, string prefix, int type) {
      writefln("%s%s%s %s %s", prefix, ["", "|-- ", "`-- "][type],
               (len[u] <= 0) ? ("(" ~ len[u].to!string ~ ")")
                             : s[u - 2 - len[u] .. u - 2],
               u, fail[u]);
      const vs = next[u * size .. (u + 1) * size].filter!(v => v).array;
      foreach (v; vs) {
        dfs(v, prefix ~ ["", "|   ", "    "][type], (v == vs[$ - 1]) ? 2 : 1);
      }
    }
    dfs(1, "", 0);
    dfs(2, "  ", 0);
  }
}


void main() {
  try {
    for (; ; ) {
      const S = readToken();
      const N = cast(int)(S.length) / 2;
      
      string T;
      foreach (i; 0 .. N) {
        T ~= S[i];
        T ~= S[2 * N - 1 - i];
      }
      const t = new Eertree!(26, 'a')(T);
      debug {
        t.print;
        writeln("T = ", T);
        writeln("us = ", t.us);
        writeln("fail = ", t.fail);
        writeln("slink = ", t.slink);
        writeln("diff = ", iota(t.n + 3).map!(u => t.len[u] - t.len[t.fail[u]]));
      }
      
      debug {
        auto brt = new Mint[N + 1];
        brt[0] = 1;
        foreach (i; 1 .. N + 1) {
          for (int u = t.us[2 * i + 2]; u > 2; u = t.fail[u]) {
            if (t.len[u] % 2 == 0) {
              debug {
                writeln(i, " ", u, " ", t.len[u]);
              }
              brt[i] += brt[i - t.len[u] / 2];
            }
          }
        }
        writeln("brt = ", brt);
      }
      
      auto dp = new Mint[t.n + 1];
      auto sdp = new Mint[t.n + 3];
      dp[0] = 1;
      foreach (i; 1 .. t.n + 1) {
        for (int u = t.us[i + 2]; u > 2; u = t.slink[u]) {
          sdp[u] = dp[i - t.len[u] + t.len[t.fail[u]] - t.len[t.slink[u]]];
          if (t.len[u] - t.len[t.fail[u]] == t.len[t.fail[u]] - t.len[t.fail[t.fail[u]]]) {
            sdp[u] += sdp[t.fail[u]];
          }
          dp[i] += sdp[u];
        }
        if (i % 2 != 0) {
          dp[i] = 0;
        }
      }
      debug {
        writeln("dp = ", dp);
        writeln("sdp = ", sdp);
      }
      writeln(dp[2 * N]);
    }
  } catch (EOFException e) {
  }
}