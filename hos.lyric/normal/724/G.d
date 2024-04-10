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


enum E = 60;
enum LIM = 300_010;

int N, M;
int[] U, V;
long[] T;

int[][] G;
int[] dep;
long[] pot;
int[] us;
long[] cycs;

void dfs(int u, int p) {
  dep[u] = (p == -1) ? 0 : (dep[p] + 1);
  us ~= u;
  foreach (i; G[u]) {
    const v = U[i] ^ V[i] ^ u;
    if (v != p) {
      if (dep[v] == -1) {
        pot[v] = pot[u] ^ T[i];
        dfs(v, u);
      } else if (dep[v] < dep[u]) {
        cycs ~= pot[u] ^ pot[v] ^ T[i];
      }
    }
  }
}

void main() {
  auto two = new Mint[LIM];
  two[0] = 1;
  foreach (i; 1 .. LIM) {
    two[i] = two[i - 1] * 2;
  }
  
  try {
    for (; ; ) {
      N = readInt();
      M = readInt();
      U = new int[M];
      V = new int[M];
      T = new long[M];
      foreach (i; 0 .. M) {
        U[i] = readInt() - 1;
        V[i] = readInt() - 1;
        T[i] = readLong();
      }
      
      G = new int[][N];
      foreach (i; 0 .. M) {
        G[U[i]] ~= i;
        G[V[i]] ~= i;
      }
      dep = new int[N];
      dep[] = -1;
      pot = new long[N];
      
      Mint ans;
      foreach (r; 0 .. N) {
        if (dep[r] == -1) {
          us = [];
          cycs = [];
          dfs(r, -1);
          long[] bases;
          foreach (cyc; cycs) {
            long x = cyc;
            foreach (base; bases) {
              chmin(x, x ^ base);
            }
            if (x) {
              bases ~= x;
            }
          }
          debug {
            writeln("us = ", us);
            writeln("pot = ", pot);
            writeln("cycs = ", cycs);
            writeln("bases = ", bases);
          }
          foreach (e; 0 .. E) {
            long[2] cntP, cntB;
            foreach (u; us) {
              ++cntP[(pot[u] >> e) & 1];
            }
            foreach (base; bases) {
              ++cntB[(base >> e) & 1];
            }
            Mint[2] numP, numB;
            numP[1] = cntP[0] * cntP[1];
            numP[0] = (cntP[0] + cntP[1]) * (cntP[0] + cntP[1] - 1) / 2 - numP[1];
            if (cntB[1] == 0) {
              numB[0] = two[cast(int)(cntB[0])];
              numB[1] = 0;
            } else {
              numB[0] = numB[1] = two[cast(int)(cntB[0] + cntB[1] - 1)];
            }
            debug {
              if (e <= 4) {
                writeln("e = ", e);
                writeln("  cntP = ", cntP, ", numP = ", numP);
                writeln("  cntB = ", cntB, ", numB = ", numB);
              }
            }
            ans += two[e] * (numP[0] * numB[1] + numP[1] * numB[0]);
          }
        }
      }
      writeln(ans);
    }
  } catch (EOFException e) {
  }
}