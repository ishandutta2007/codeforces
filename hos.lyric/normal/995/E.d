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

struct ModInt {
  static int M;
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


enum L = 200;
enum N = 19;

void main() {
  try {
    for (; ; ) {
      const U = readLong();
      const V = readLong();
      const P = readLong();
      ModInt.M = cast(int)(P);
      
      alias Entry = Tuple!(long, "val", int, "key");
      Entry[] eus, evs;
      void dfs(ref Entry[] results, int pos, int key, ModInt x) {
        if (pos == N) {
          results ~= Entry(x.x, key);
          return;
        }
        const invU = (x.x == 0) ? ModInt(0) : x.inv;
        dfs(results, pos + 1, key, invU + 1);
        dfs(results, pos + 1, key | 1 << pos, invU - 1);
      }
      dfs(eus, 0, 0, ModInt(U));
      dfs(evs, 0, 0, ModInt(V));
      eus.sort;
      evs.sort;
      int[] ans;
      for (int i = 0, j = 0; i < eus.length && j < evs.length; ) {
        const diff = ModInt(evs[j].val - eus[i].val);
        if (0 <= diff.x && diff.x <= L - 4 * N) {
          foreach (k; 0 .. N) {
            ans ~= 3;
            ans ~= ((eus[i].key & 1 << k) ? 2 : 1);
          }
          foreach (_; 0 .. diff.x) {
            ans ~= 1;
          }
          foreach_reverse (k; 0 .. N) {
            ans ~= ((evs[j].key & 1 << k) ? 1 : 2);
            ans ~= 3;
          }
          goto found;
        }
        if (0 <= (-diff).x && (-diff).x <= L - 4 * N) {
          foreach (k; 0 .. N) {
            ans ~= 3;
            ans ~= ((eus[i].key & 1 << k) ? 2 : 1);
          }
          foreach (_; 0 .. (-diff).x) {
            ans ~= 2;
          }
          foreach_reverse (k; 0 .. N) {
            ans ~= ((evs[j].key & 1 << k) ? 1 : 2);
            ans ~= 3;
          }
          goto found;
        }
        (eus[i].val <= evs[j].val) ? ++i : ++j;
      }
      assert(false);
     found:
      
      writeln(ans.length);
      foreach (h; 0 .. ans.length) {
        if (h > 0) write(" ");
        write(ans[h]);
      }
      writeln();
      
      debug {
        ModInt x = U;
        foreach (h; 0 .. ans.length) {
          switch (ans[h]) {
            case 1: x += 1; break;
            case 2: x -= 1; break;
            case 3: x = (x.x == 0) ? ModInt(0) : x.inv; break;
            default: assert(false);
          }
        }
        assert(x.x == V);
      }
    }
  } catch (EOFException e) {
  }
}