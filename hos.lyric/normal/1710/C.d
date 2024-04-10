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

enum MO = 998244353;
alias Mint = ModInt!MO;


void main() {
  debug {{
    foreach (n; 1 .. 8 + 1) {
      int cnt;
      foreach (a; 0 .. 1 << n) foreach (b; 0 .. 1 << n) foreach (c; 0 .. 1 << n) {
        const x = b ^ c;
        const y = c ^ a;
        const z = a ^ b;
        if (x > 0 && y > 0 && z > 0 && y + z > x && z + x > y && x + y > z) {
        } else {
          ++cnt;
          if (n <= 4) {
            writefln("%02d %02d %02d; %02d %02d %02d", a, b, c, x, y, z);
          }
          const okX = (x == y + z && !(y & z));
          const okY = (y == z + x && !(z & x));
          const okZ = (z == x + y && !(x & y));
          assert(okX || okY || okZ);
          if (n <= 4) {
            if ((okX ? 1 : 0) + (okY ? 1 : 0) + (okZ ? 1 : 0) >= 2) {
              stderr.writefln("%02d %02d %02d; %02d %02d %02d", a, b, c, x, y, z);
            }
          }
        }
      }
      stderr.writeln(n, ": ", cnt);
    }
  }}
  /*
1: 0
2: 0
3: 48
4: 960
5: 12480
6: 134400
7: 1306368
8: 11934720
  */
  
  Mint[8][8][2] trans;
  foreach (s; 0 .. 2) {
    foreach (p; 0 .. 8) {
      foreach (x; 0 .. 8) {
        bool ok = true;
        int q = p;
        foreach (j; 0 .. 3) {
          ok = ok && ((p >> j & 1) || ((x >> j & 1) <= s));
          if ((x >> j & 1) < s) {
            q |= 1 << j;
          }
        }
        const a = (x >> 0 & 1);
        const b = (x >> 1 & 1);
        const c = (x >> 2 & 1);
        ok = ok && ((b ^ c) == (c ^ a) + (a ^ b));
        if (ok) {
          debug {
            writeln(s, " ", p, " ", [a, b, c]);
          }
          trans[s][p][q] += 1;
        }
      }
    }
  }
  
  try {
    for (; ; ) {
      const S = readToken;
      const L = cast(int)(S.length);
      
      Mint n;
      foreach (i; 0 .. L) {
        n = n * 2 + (S[i] - '0');
      }
      debug {
        writeln("n = ", n);
      }
      
      // f1: smaller
      Mint[8] crt;
      crt[0] = 1;
      foreach (i; 0 .. L) {
        Mint[8] nxt;
        foreach (p; 0 .. 8) {
          foreach (q; 0 .. 8) {
            nxt[q] += crt[p] * trans[S[i] - '0'][p][q];
          }
        }
        crt = nxt;
      }
      
      Mint ans;
      foreach (p; 0 .. 8) {
        ans += crt[p];
      }
      debug {
        writeln("ans = ", ans);
      }
      ans *= 3;
      ans -= 3 * n * (n + 1);
      ans -= 2 * (n + 1);
      ans = (n + 1)^^3 - ans;
      writeln(ans);
    }
  } catch (EOFException e) {
  }
}