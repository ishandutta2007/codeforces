import std.conv, std.functional, std.range, std.stdio, std.string;
import std.algorithm, std.array, std.bigint, std.complex, std.container, std.math, std.numeric, std.regex, std.typecons;
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

struct ModInt(long M) {
  int x;
  this(ModInt a) { x = a.x; }
  this(long a) { x = cast(int)(a % M); if (x < 0) x += M; }
  ref ModInt opAssign(long a) { return (this = ModInt(a)); }
  ref ModInt opOpAssign(string op)(ModInt a) {
    static if (op == "+") { x += a.x; if (x >= M) x -= M; }
    else static if (op == "-") { x -= a.x; if (x < 0) x += M; }
    else static if (op == "*") { x = cast(int)((cast(long)(x) * a.x) % M); }
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
  ModInt opUnary(string op)() const if (op == "-") { return ModInt(-x); }
  ModInt opBinary(string op, T)(T a) const { return mixin("ModInt(this) " ~ op ~ "= a"); }
  ModInt opBinaryRight(string op)(long a) const { return mixin("ModInt(a) " ~ op ~ "= this"); }
  string toString() const { return x.to!string; }
}

enum MO = 10L^^9 + 7;
alias Mint = ModInt!MO;

enum E = 17;

int N;
long[] X;
int[] A, B;

int[][] G;
int[][] par;

void dfs(int u, int p) {
  par[0][u] = p;
  foreach (v; G[u]) {
    if (v != p) {
      dfs(v, u);
    }
  }
}

void main() {
  try {
    for (; ; ) {
      N = readInt();
      X = new long[N];
      foreach (u; 0 .. N) {
        X[u] = readLong();
      }
      A = new int[N - 1];
      B = new int[N - 1];
      foreach (i; 0 .. N - 1) {
        A[i] = readInt() - 1;
        B[i] = readInt() - 1;
      }
      
      G = new int[][N];
      foreach (i; 0 .. N - 1) {
        G[A[i]] ~= B[i];
        G[B[i]] ~= A[i];
      }
      par = new int[][](E, N + 1);
      dfs(0, N);
      par[0][N] = N;
      foreach (e; 0 .. E - 1) {
        foreach (u; 0 .. N + 1) {
          par[e + 1][u] = par[e][par[e][u]];
        }
      }
      
      auto ds = new long[][](E, N);
      foreach (u; 0 .. N) {
        const v = par[0][u];
        ds[0][u] = (v == N) ? 0 : X[v];
      }
      foreach (e; 0 .. E - 1) {
        foreach (u; 0 .. N) {
          const v = par[e][u];
          ds[e + 1][u] = (v == N) ? ds[e][u] : gcd(ds[e][u], ds[e][v]);
        }
      }
      debug {
        foreach (e; 0 .. 4) {
          writeln(par[e]);
          writeln(ds[e]);
        }
      }
      
      Mint ans;
      foreach (u; 0 .. N) {
        long g = X[u];
        int v = u;
        for (; ; ) {
          long sum;
          foreach_reverse (e; 0 .. E) {
            const w = par[e][v];
            if (w != N) {
              // gcd(g, ds[e][v]) == g
              if ((g == 0) ? (ds[e][v] == 0) : (ds[e][v] % g == 0)) {
                sum |= 1 << e;
                v = w;
              }
            }
          }
          ans += g * Mint(sum + 1);
          v = par[0][v];
          if (v == N) {
            break;
          }
          g = gcd(g, X[v]);
        }
      }
      writeln(ans);
    }
  } catch (EOFException e) {
  }
}