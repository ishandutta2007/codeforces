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


void main() {
  try {
    for (; ; ) {
      const M = readInt();
      const N = readInt();
      auto A = new string[M];
      foreach (x; 0 .. M) {
        A[x] = readToken();
      }
      
      if (M == 1 && N == 1) {
        writeln(1);
        continue;
      }
      
      auto rows = new int[][](M, N + 1);
      auto cols = new int[][](N, M + 1);
      foreach (x; 0 .. M) {
        foreach (y; 0 .. N) {
          rows[x][y + 1] = rows[x][y] + ((A[x][y] == 'R') ? 1 : 0);
        }
      }
      foreach (y; 0 .. N) {
        foreach (x; 0 .. M) {
          cols[y][x + 1] = cols[y][x] + ((A[x][y] == 'R') ? 1 : 0);
        }
      }
      
      bool checkRow(int x, int y0, int y1) {
        return (rows[x][y1 + 1] - rows[x][y0 + 1] <= (N - (y1 + 1)) - (rows[x][N] - rows[x][y1 + 1]));
      }
      bool checkCol(int y, int x0, int x1) {
        return (cols[y][x1 + 1] - cols[y][x0 + 1] <= (M - (x1 + 1)) - (cols[y][M] - cols[y][x1 + 1]));
      }
      
      auto dp0Sum = new Mint[][](M, N + 1);
      auto dp1Sum = new Mint[][](N, M + 1);
      dp0Sum[0][1] = 1;
      dp1Sum[0][1] = 1;
      auto xs = new int[N];
      auto ys = new int[M];
      foreach (x; 0 .. M) foreach (y; 0 .. N) {
        if (x + y > 0) {
          for (; !checkCol(y, xs[y], x); ++xs[y]) {}
          dp0Sum[x][y + 1] = dp0Sum[x][y] + (dp1Sum[y][x] - dp1Sum[y][xs[y]]);
          for (; !checkRow(x, ys[x], y); ++ys[x]) {}
          dp1Sum[y][x + 1] = dp1Sum[y][x] + (dp0Sum[x][y] - dp0Sum[x][ys[x]]);
        }
      }
      Mint ans;
      ans += dp0Sum[M - 1][N] - dp0Sum[M - 1][N - 1];
      ans += dp1Sum[N - 1][M] - dp1Sum[N - 1][M - 1];
      writeln(ans);
    }
  } catch (EOFException e) {
  }
}