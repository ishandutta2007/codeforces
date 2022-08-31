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


void main() {
  try {
    for (; ; ) {
      const N = readInt();
      const M = readInt();
      auto A = new long[N];
      foreach (i; 0 .. N) {
        A[i] = readLong();
      }
      
      long[] bases;
      foreach (i; 0 .. N) {
        long a = A[i];
        foreach (base; bases) {
          chmin(a, a ^ base);
        }
        if (a) {
          bases ~= a;
        }
      }
      bases.sort!"a > b";
      const r = cast(int)(bases.length);
      foreach (j; 0 .. r) {
        foreach (k; j + 1 .. r) {
          chmin(bases[k], bases[k] ^ bases[j]);
        }
      }
      debug {
        foreach (base; bases) {
          writefln("%0*b", M, base);
        }
      }
      
      long[] ps, qs;
      foreach (j; 0 .. r) {
        if (bases[j] & ~((1L << (M / 2)) - 1)) {
          ps ~= bases[j];
        } else {
          qs ~= bases[j];
        }
      }
      debug {
        writeln("ps = ", ps);
        writeln("qs = ", qs);
      }
      const psLen = cast(int)(ps.length);
      const qsLen = cast(int)(qs.length);
      auto psSum = new long[1 << psLen];
      auto qsSum = new long[1 << qsLen];
      foreach (j; 0 .. psLen) {
        foreach (h; 0 .. 1 << j) {
          psSum[h | 1 << j] = psSum[h] ^ ps[j];
        }
      }
      foreach (j; 0 .. qsLen) {
        foreach (h; 0 .. 1 << j) {
          qsSum[h | 1 << j] = qsSum[h] ^ qs[j];
        }
      }
      auto xss = new Mint[][](M - M / 2 + 1, 1 << (M / 2));
      auto ys = new Mint[1 << (M / 2)];
      foreach (h; 0 .. 1 << psLen) {
        xss[popcnt(psSum[h] >> (M / 2))][cast(int)(psSum[h] & ((1L << (M / 2)) - 1))] += 1;
      }
      foreach (h; 0 .. 1 << qsLen) {
        ys[cast(int)(qsSum[h])] += 1;
      }
      
      foreach (e; 0 .. M / 2) {
        foreach (f; 0 .. 1 << (M / 2)) {
          if (!(f & 1 << e)) {
            const tmp = ys[f] - ys[f | 1 << e];
            ys[f] += ys[f | 1 << e];
            ys[f | 1 << e] = tmp;
          }
        }
      }
      const invTwo = Mint(2)^^(-(M / 2));
      auto ans = new Mint[M + 1];
      foreach (s; 0 .. M - M / 2 + 1) {
        foreach (e; 0 .. M / 2) {
          foreach (f; 0 .. 1 << (M / 2)) {
            if (!(f & 1 << e)) {
              const tmp = xss[s][f] - xss[s][f | 1 << e];
              xss[s][f] += xss[s][f | 1 << e];
              xss[s][f | 1 << e] = tmp;
            }
          }
        }
        xss[s][] *= ys[];
        xss[s][] *= invTwo;
        foreach (e; 0 .. M / 2) {
          foreach (f; 0 .. 1 << (M / 2)) {
            if (!(f & 1 << e)) {
              const tmp = xss[s][f] - xss[s][f | 1 << e];
              xss[s][f] += xss[s][f | 1 << e];
              xss[s][f | 1 << e] = tmp;
            }
          }
        }
        foreach (f; 0 .. 1 << (M / 2)) {
          ans[s + popcnt(f)] += xss[s][f];
        }
      }
      
      ans[] *= Mint(2)^^(N - r);
      foreach (s; 0 .. M + 1) {
        if (s > 0) write(" ");
        write(ans[s]);
      }
      writeln();
    }
  } catch (EOFException e) {
  }
}