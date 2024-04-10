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

enum MO = 10^^9 + 403;
alias Mint = ModInt!MO;


struct Point(T) {
  T x, y;
  Pt opBinary(string op)(Pt a) const {
    static if (op == "+") return Pt(x + a.x, y + a.y);
    else static if (op == "-") return Pt(x - a.x, y - a.y);
    else static assert(false);
  }
  Pt opBinary(string op)(T k) const {
    static if (op == "*") return Pt(x * k, y * k);
    else static if (op == "/") return Pt(x / k, y / k);
    else static assert(false);
  }
  T dot(Pt a) const { return x * a.x + y * a.y; }
  T det(Pt a) const { return x * a.y - y * a.x; }
  int opCmp(Pt a) const { return (x < a.x) ? -1 : (x > a.x) ? +1 : (y < a.y) ? -1 : (y > a.y) ? +1 : 0; }
  string toString() const { return "(" ~ x.to!string ~ ", " ~ y.to!string ~ ")"; }
}

alias Pt = Point!long;
long tri(Pt a, Pt b, Pt c) {
  return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

Pt[] convexHull(Pt[] ps) {
  auto qs = new Pt[ps.length + 1];
  ps.sort!((a, b) => ((a.x != b.x) ? (a.x < b.x) : (a.y < b.y)));
  int m = 0;
  foreach (p; ps) {
    for (; m > 1 && sgn(tri(qs[m - 2], qs[m - 1], p)) <= 0; --m) {}
    qs[m++] = p;
  }
  const r = m;
  foreach_reverse (p; ps) {
    for (; m > r && sgn(tri(qs[m - 2], qs[m - 1], p)) <= 0; --m) {}
    qs[m++] = p;
  }
  return qs[0 .. m - 1];
}


enum BASES = [20209, 1209, 21479];

void main() {
  try {
    for (; ; ) {
      auto N = new int[2];
      foreach (h; 0 .. 2) {
        N[h] = readInt();
      }
      auto P = new Pt[][2];
      foreach (h; 0 .. 2) {
        P[h] = new Pt[N[h]];
        foreach (i; 0 .. N[h]) {
          P[h][i].x = readLong();
          P[h][i].y = readLong();
        }
      }
      
      auto seqs = new long[][2];
      foreach (h; 0 .. 2) {
        const qs = convexHull(P[h]);
        const qsLen = cast(int)(qs.length);
        auto edges = new Pt[qsLen];
        foreach (j; 0 .. qsLen) {
          edges[j] = qs[(j + 1) % qsLen] - qs[j];
        }
        foreach (j; 0 .. qsLen) {
          seqs[h] ~= edges[j].dot(edges[j]);
          seqs[h] ~= edges[j].dot(edges[(j + 1) % qsLen]);
        }
        debug {
          writeln("P[h] = ", P);
          writeln("qs = ", qs);
          writeln("seqs[h] = ", seqs[h]);
        }
      }
      
      bool ans;
      const len = cast(int)(seqs[0].length);
      if (len == seqs[1].length) {
        auto bb = new Mint[][](BASES.length, len + 1);
        foreach (g; 0 .. BASES.length) {
          bb[g][0] = 1;
          foreach (j; 1 .. len + 1) {
            bb[g][j] = bb[g][j - 1] * BASES[g];
          }
        }
        auto ss = new Mint[][][](2, BASES.length, len + 1);
        foreach (h; 0 .. 2) foreach (g; 0 .. BASES.length) {
          foreach (j; 0 .. len) {
            ss[h][g][j + 1] = ss[h][g][j] + bb[g][j] * seqs[h][j];
          }
        }
        debug {
          writeln("ss = ", ss);
        }
        foreach (shift; 0 .. len) {
          if (shift % 2 == 0) {
            bool ok = true;
            foreach (g; 0 .. BASES.length) {
              ok = ok && ((bb[g][shift] * ss[0][g][len]).x == (ss[1][g][len] + (bb[g][len] - 1) * ss[1][g][shift]).x);
            }
            if (ok) {
              debug {
                writeln("shift = ", shift);
              }
              foreach (j; 0 .. len) {
                if (seqs[0][j] != seqs[1][(j + shift) % len]) {
                  ok = false;
                  break;
                }
              }
              if (ok) {
                ans = true;
                break;
              }
            }
          }
        }
      }
      writeln(ans ? "YES" : "NO");
    }
  } catch (EOFException e) {
  }
}