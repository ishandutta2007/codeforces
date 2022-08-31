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
  long x;
  this(in ModInt a) { x = a.x; }
  this(in long a) { x = a % M; if (x < 0) x += M; }
  ModInt opUnary(string op)() if (op == "-") { return ModInt(-x); }
  ref ModInt opOpAssign(string op)(in ModInt a) {
    static if (op == "+") { x += a.x; if (x >= M) x -= M; }
    else static if (op == "-") { x -= a.x; if (x < 0) x += M; }
    else static if (op == "*") { x *= a.x; x %= M; }
    else static assert(false);
    return this;
  }
  ModInt opOpAssign(string op)(in long a) { return mixin("this " ~ op ~ "= ModInt(a)"); }
  ModInt opBinary(string op, T)(in T a) const { return mixin("ModInt(this) " ~ op ~ "= a"); }
  ModInt opBinaryRight(string op)(in long a) const { return mixin("ModInt(a) " ~ op ~ "= this"); }
  string toString() const { return x.to!string; }
}


enum long MO = 998244353;
alias Mint = ModInt!MO;

int N, M;
int[] C;

void main() {
  try {
    for (; ; ) {
      N = readInt();
      M = readInt();
      C = new int[M];
      foreach (i; 0 .. M) {
        C[i] = readInt();
      }
      
      auto dp = new Mint[][](N + 1, N + 1);
      foreach (i; 0 .. N + 1) {
        dp[i][i] = Mint(1);
      }
      foreach (w; 1 .. N + 1) {
        foreach (i; 0 .. N - w + 1) {
          const j = i + w;
          int km = i;
          foreach (k; i .. j) {
            if (C[km] > C[k]) {
              km = k;
            }
          }
          Mint sumL, sumR;
          foreach (k; i .. km + 1) {
            sumL += dp[i][k] * dp[k][km];
          }
          foreach (k; km + 1 .. j + 1) {
            sumR += dp[km + 1][k] * dp[k][j];
          }
          debug {
            writeln(i, " ", j, ": ", km, " ", sumL, " ", sumR);
          }
          dp[i][j] = sumL * sumR;
        }
      }
      writeln(dp[0][N]);
    }
  } catch (EOFException e) {
  }
}