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
  this(ulong x_) { x = x_ % M; }
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


int root(int[] uf, int u) {
  return (uf[u] < 0) ? u : (uf[u] = uf.root(uf[u]));
}
bool connect(int[] uf, int u, int v) {
  u = uf.root(u);
  v = uf.root(v);
  if (u == v) return false;
  if (uf[u] > uf[v]) swap(u, v);
  uf[u] += uf[v];
  uf[v] = u;
  return true;
}


void main() {
  debug {{
    enum lim = 10;
    foreach (m; 1 .. lim + 1) {
      foreach (n; 1 .. lim + 1) {
        int r;
        if (m % 2 != 0) {
          if (n % 2 != 0) {
            r = m * n - (m - 1) - (n - 1);
          } else {
            r = m * n - (n - 1);
          }
        } else {
          if (n % 2 != 0) {
            r = m * n - (m - 1);
          } else {
            r = m * n;
          }
        }
        write(r, " ");
      }
      writeln;
    }
    // return;
  }}
  
  try {
    for (; ; ) {
      const M = readInt;
      const N = readInt;
      auto A = new string[M];
      foreach (x; 0 .. M) {
        A[x] = readToken;
      }
      
      Mint ans;
      if (M % 2 != 0) {
        if (N % 2 != 0) {
          auto uf = new int[M + N];
          uf[] = -1;
          auto rows = new int[M];
          auto cols = new int[N];
          foreach (x; 0 .. M) foreach (y; 0 .. N) {
            if (A[x][y] == '?') {
              uf.connect(x, M + y);
            } else {
              rows[x] ^= (A[x][y] - '0');
              cols[y] ^= (A[x][y] - '0');
            }
          }
          auto es = new int[M + N];
          auto fs = new int[M + N];
          auto gs = new int[M + N];
          auto ss = new int[M + N];
          foreach (x; 0 .. M) foreach (y; 0 .. N) if (A[x][y] == '?') {
            const r = uf.root(x);
            ++es[r];
          }
          foreach (x; 0 .. M) {
            const r = uf.root(x);
            fs[r] ^= 1;
            ss[r] ^= rows[x];
          }
          foreach (y; 0 .. N) {
            const r = uf.root(M + y);
            gs[r] ^= 1;
            ss[r] ^= cols[y];
          }
          
          foreach (p; 0 .. 2) foreach (q; 0 .. 2) {
            bool ok = true;
            int e;
            foreach (r; 0 .. M + N) if (uf[r] < 0) {
              ok = ok && (((p & fs[r]) ^ (q & gs[r])) == ss[r]);
              e += (es[r] - ((-uf[r]) - 1));
            }
            if (ok) {
              ans += Mint(2)^^e;
            }
          }
        } else {
          Mint[2] nums;
          nums[0] = nums[1] = 1;
          foreach (y; 0 .. N) {
            int cnt, sum;
              foreach (x; 0 .. M) {
              if (A[x][y] == '?') {
                ++cnt;
              } else {
                sum ^= (A[x][y] - '0');
              }
            }
            if (cnt == 0) {
              nums[sum ^ 1] = 0;
            } else {
              const two = Mint(2)^^(cnt - 1);
              nums[0] *= two;
              nums[1] *= two;
            }
          }
          debug {
            writeln("nums = ", nums);
          }
          ans = nums[0] + nums[1];
        }
      } else {
        if (N % 2 != 0) {
          Mint[2] nums;
          nums[0] = nums[1] = 1;
          foreach (x; 0 .. M) {
            int cnt, sum;
            foreach (y; 0 .. N) {
              if (A[x][y] == '?') {
                ++cnt;
              } else {
                sum ^= (A[x][y] - '0');
              }
            }
            if (cnt == 0) {
              nums[sum ^ 1] = 0;
            } else {
              const two = Mint(2)^^(cnt - 1);
              nums[0] *= two;
              nums[1] *= two;
            }
          }
          debug {
            writeln("nums = ", nums);
          }
          ans = nums[0] + nums[1];
        } else {
          int cnt;
          foreach (x; 0 .. M) foreach (y; 0 .. N) if (A[x][y] == '?') {
            ++cnt;
          }
          ans = Mint(2)^^cnt;
        }
      }
      writeln(ans);
    }
  } catch (EOFException e) {
  }
}