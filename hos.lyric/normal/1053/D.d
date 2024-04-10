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

struct ModInt(uint M_) {
  import std.conv : to;
  alias M = M_;
  uint x;
  this(ModInt a) { x = a.x; }
  this(uint x_) { x = x_ % M; }
  this(ulong x_) { x = cast(uint)(x_ % M); }
  this(int x_) { x = ((x_ %= cast(int)(M)) < 0) ? (x_ + cast(int)(M)) : x_; }
  this(long x_) { x = cast(uint)(((x_ %= cast(long)(M)) < 0) ? (x_ + cast(long)(M)) : x_); }
  ref ModInt opAssign(T)(inout(T) a) if (is(T == uint) || is(T == ulong) || is(T == int) || is(T == long)) { return this = ModInt(a); }
  ref ModInt opOpAssign(string op, T)(T a) {
    static if (is(T == ModInt)) {
      static if (op == "+") { x = ((x += a.x) >= M) ? (x - M) : x; }
      else static if (op == "-") { x = ((x -= a.x) >= M) ? (x + M) : x; }
      else static if (op == "*") { x = cast(uint)((cast(ulong)(x) * a.x) % M); }
      else static if (op == "/") { this *= a.inv(); }
      else static assert(false);
      return this;
    } else static if (op == "^^") {
      if (a < 0) return this = inv()^^(-a);
      ModInt b = this, c = 1U;
      for (long e = a; e; e >>= 1) { if (e & 1) c *= b; b *= b; }
      return this = c;
    } else {
      return mixin("this " ~ op ~ "= ModInt(a)");
    }
  }
  ModInt inv() const {
    uint a = M, b = x; int y = 0, z = 1;
    for (; b; ) { const q = a / b; const c = a - q * b; a = b; b = c; const w = y - cast(int)(q) * z; y = z; z = w; }
    assert(a == 1); return ModInt(y);
  }
  ModInt opUnary(string op)() const {
    static if (op == "+") { return this; }
    else static if (op == "-") { ModInt a; a.x = x ? (M - x) : 0U; return a; }
    else static assert(false);
  }
  ModInt opBinary(string op, T)(T a) const { return mixin("ModInt(this) " ~ op ~ "= a"); }
  ModInt opBinaryRight(string op, T)(T a) const { return mixin("ModInt(a) " ~ op ~ "= this"); }
  bool opCast(T: bool)() const { return (x != 0U); }
  string toString() const { return x.to!string; }
}

enum MO = 10^^9 + 7;
alias Mint = ModInt!MO;


enum LIM = 2 * 10^^6 + 10;
int[] lpf;

void main() {
  lpf = iota(LIM).array;
  foreach (p; 2 .. LIM) if (lpf[p] == p) {
    for (int n = 2 * p; n < LIM; n += p) chmin(lpf[n], p);
  }
  debug {
    writeln("lpf = ", lpf[0 .. 31]);
  }
  
  try {
    for (; ; ) {
      const N = readInt;
      auto P = new int[N];
      foreach (i; 0 .. N) {
        P[i] = readInt;
      }
      P.sort;
      debug {
        writeln("P = ", P);
      }
      
      auto fs = new int[LIM];
      auto gs = new int[LIM];
      bool waf;
      int[] cands;
      foreach_reverse (i; 0 .. N) {
        if (fs[P[i]] == 0) {
          debug {
            writeln(P[i], ": P");
          }
          fs[P[i]] = 1;
          gs[P[i]] = 1;
        } else {
          int[] ps, es;
          for (int a = P[i] - 1; a > 1; ) {
            const p = lpf[a];
            int e;
            do {
              ++e;
              a /= p;
            } while (a % p == 0);
            ps ~= p;
            es ~= e;
          }
          const len = cast(int)(ps.length);
          bool any;
          foreach (j; 0 .. len) {
            any = any || (fs[ps[j]] < es[j]);
          }
          if (any) {
            debug {
              writeln(P[i], ": P-1; ", ps, " ", es);
            }
            cands ~= i;
            foreach (j; 0 .. len) {
              if (chmax(fs[ps[j]], es[j])) gs[ps[j]] = 0;
              if (fs[ps[j]] == es[j]) ++gs[ps[j]];
            }
          } else {
            debug {
              writeln(P[i], ": +1");
            }
            waf = true;
          }
        }
      }
      
      debug {
        writeln("fs = ", fs[0 .. 31]);
        writeln("waf = ", waf);
      }
      
      if (!waf) {
        foreach (i; cands) {
          int[] ps, es;
          for (int a = P[i] - 1; a > 1; ) {
            const p = lpf[a];
            int e;
            do {
              ++e;
              a /= p;
            } while (a % p == 0);
            ps ~= p;
            es ~= e;
          }
          const len = cast(int)(ps.length);
          bool any;
          foreach (j; 0 .. len) {
            any = any || (fs[ps[j]] == es[j] && gs[ps[j]] == 1);
          }
          if (!any) {
            debug {
              writeln(P[i], " was not needed");
            }
            waf = true;
          }
        }
      }
      
      Mint ans = 1;
      foreach (p; 2 .. LIM) if (fs[p]) {
        ans *= Mint(p)^^fs[p];
      }
      if (waf) {
        ans += 1;
      }
      writeln(ans);
    }
  } catch (EOFException e) {
  }
}