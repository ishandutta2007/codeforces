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

int N, K;
int[] A;

void main() {
  try {
    for (; ; ) {
      N = readInt();
      K = readInt();
      A = new int[N];
      foreach (i; 0 .. N) {
        A[i] = readInt();
      }
      
      A.sort;
      Mint ans;
      
      auto dp = new Mint[N];
      auto dpSum = new Mint[N + 1];
      foreach (d; 1 .. (A[$ - 1] - A[0]) / (K - 1) + 1) {
        dp[] = Mint(1);
        foreach (k; 1 .. K) {
          foreach (i; 0 .. N) {
            dpSum[i + 1] = dpSum[i] + dp[i];
          }
          int j = 0;
          foreach (i; 0 .. N) {
            for (; j < N && A[i] - A[j] >= d; ++j) {}
            dp[i] = dpSum[j];
          }
        }
        foreach (i; 0 .. N) {
          ans += dp[i];
        }
      }
      
      writeln(ans);
    }
  } catch (EOFException e) {
  }
}