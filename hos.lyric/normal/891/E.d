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
      const N = readInt();
      const K = readLong();
      auto A = new long[N];
      foreach (i; 0 .. N) {
        A[i] = readLong();
      }
      
      const invN = Mint(N).inv;
      
      // \prod_i (A[i] - T)
      auto fs = [Mint(1)];
      foreach (i; 0 .. N) {
        auto gs = new Mint[i + 1 + 1];
        foreach (j; 0 .. i + 1) {
          gs[j + 0] += fs[j] * A[i];
          gs[j + 1] -= fs[j];
        }
        fs = gs;
      }
      
      auto gsSum = new Mint[N];
      foreach (i; 0 .. N) {
        auto gs = fs.dup;
        foreach_reverse (j; 0 .. N) {
          gs[j + 1] *= -1;
          gs[j] -= gs[j + 1] * A[i];
        }
        assert(!gs[0]);
        gs = gs[1 .. N + 1];
        debug {
          writeln("gs = ", gs);
        }
        gsSum[] += gs[];
      }
      
      debug {
        const M = N + 5;
        auto hs = new Mint[M];
        foreach (k; 0 .. M) {
          Mint coef = 1;
          foreach (s; 0 .. N) {
            hs[k] += coef * gsSum[s];
            coef *= (k - s);
            coef *= invN;
          }
          hs[k] *= invN;
        }
        writeln("hs = ", hs);
        if (K <= M) {
          writeln("hs[0 .. K].sum = ", hs[0 .. cast(int)(K)].sum);
        }
      }
      
      // \sum_{k=0}^{K-1} k (k - 1) ... (k - (s - 1))
      Mint ans;
      Mint coef = invN;
      foreach (s; 0 .. N) {
        coef *= (K - s);
        ans += coef / (s + 1) * gsSum[s];
        coef *= invN;
      }
      writeln(ans);
      
      debug {
        Mint brt;
        Mint eProd;
        foreach (p; 0 .. N^^K) {
          auto as = A.dup;
          Mint res;
          foreach (k; 0 .. K) {
            const i = cast(int)(p / N^^k % N);
            Mint prod = 1;
            foreach (j; 0 .. N) {
              if (j != i) {
                prod *= as[j];
              }
            }
            res += prod;
            --as[i];
          }
          brt += res;
          {
            Mint prod = 1;
            foreach (i; 0 .. N - 1) {
              prod *= as[i];
            }
            eProd += prod;
          }
        }
        brt /= N^^K;
        eProd /= N^^K;
        writeln("brt = ", brt);
        writeln("eProd = ", eProd);
        
        Mint eProd1;
        foreach (f; 0 .. 1 << (N - 1)) {
          const pop = popcnt(f);
          Mint tmp = (-1)^^pop;
          foreach (i; 0 .. N - 1) {
            if (!(f & 1 << i)) {
              tmp *= A[i];
            }
          }
          foreach (j; 0 .. pop) {
            tmp *= (K - j);
          }
          tmp *= Mint(N)^^(-pop);
          eProd1 += tmp;
        }
        writeln("eProd1 = ", eProd1);
      }
    }
  } catch (EOFException e) {
  }
}