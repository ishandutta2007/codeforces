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

enum MO = 10^^9 + 7;
alias Mint = ModInt!MO;


int N;
int[] A, B, C;
Mint[] X;

int[][] G;
Mint ans;

void solveCentroidDecomp() {
  auto sz = new int[N];
  auto del = new bool[N];
  void dfsSz(int u, int p) {
    sz[u] = 1;
    foreach (i; G[u]) {
      const v = A[i] ^ B[i] ^ u;
      if (v != p) {
        dfsSz(v, u);
        sz[u] += sz[v];
      }
    }
  }
  dfsSz(0, -1);

  // r: centroid
  void solveSubtree(int r) {
    debug {
      string dfsDebug(int u, int p) {
        string ret = u.to!string;
        foreach (i; G[u]) {
          const v = A[i] ^ B[i] ^ u;
          if (!del[v] && v != p) {
            ret ~= "(" ~ dfsDebug(v, u) ~ ")";
          }
        }
        return ret;
      }
      writeln("solveSubtree ", dfsDebug(r, -1));
    }
    
    int[] Is;
    foreach (i; G[r]) {
      const v = A[i] ^ B[i] ^ r;
      if (!del[v]) {
        Is ~= i;
      }
    }
    const len = cast(int)(Is.length);
    
    /*
      y + y' <= 2 (x + x')
      x + x' <= 2 (y + y')
    */
    alias Entry = Tuple!(int, "a", int, "b", Mint, "z");
    Entry[] es;
    auto ess = new Entry[][len];
    void dfs(int j, int u, int p, int x, int y, Mint z) {
      const e = Entry(x - 2 * y, y - 2 * x, z);
      es ~= e;
      ess[j] ~= e;
      foreach (i; G[u]) {
        const v = A[i] ^ B[i] ^ u;
        if (!del[v] && v != p) {
          dfs(j, v, u, x + ((C[i] == 0) ? 1 : 0), y + ((C[i] != 0) ? 1 : 0), z * X[i]);
        }
      }
    }
    es ~= Entry(0, 0, Mint(1));
    foreach (j; 0 .. len) {
      const i = Is[j];
      const v = A[i] ^ B[i] ^ r;
      dfs(j, v, r, 0 + ((C[i] == 0) ? 1 : 0), 0 + ((C[i] != 0) ? 1 : 0), X[i]);
    }
    
    auto doIt(bool inv)(Entry[] fs) {
      const fsLen = cast(int)(fs.length);
      const as = fs.map!(f => f.a).array.sort.array;
      const bs = fs.map!(f => f.b).array.sort.array;
      foreach (ref f; fs) {
        int num = fsLen;
        num -= fsLen - as.upperBound(-f.a);
        num -= fsLen - bs.upperBound(-f.b);
        debug {
          writeln("  ", inv, " ", f, " ", num);
        }
        ans *= f.z^^(inv ? -num : num);
      }
    }
    
    doIt!false(es);
    foreach (j; 0 .. len) {
      doIt!true(ess[j]);
    }
  }

  void solveRec(int u) {
    for (; ; ) {
      int vm = -1;
      foreach (i; G[u]) {
        const v = A[i] ^ B[i] ^ u;
        if (!del[v]) {
          if (vm == -1 || sz[vm] < sz[v]) {
            vm = v;
          }
        }
      }
      if (vm == -1 || sz[u] >= 2 * sz[vm]) {
        solveSubtree(u);
        del[u] = true;
        foreach (i; G[u]) {
          const v = A[i] ^ B[i] ^ u;
          if (!del[v]) {
            solveRec(v);
          }
        }
        break;
      } else {
        sz[u] -= sz[vm];
        sz[vm] += sz[u];
        u = vm;
      }
    }
  }
  solveRec(0);
}


void main() {
  try {
    for (; ; ) {
      N = readInt();
      A = new int[N - 1];
      B = new int[N - 1];
      X = new Mint[N - 1];
      C = new int[N - 1];
      foreach (i; 0 .. N - 1) {
        A[i] = readInt() - 1;
        B[i] = readInt() - 1;
        X[i] = readInt();
        C[i] = readInt();
      }
      
      G = new int[][N];
      foreach (i; 0 .. N - 1) {
        G[A[i]] ~= i;
        G[B[i]] ~= i;
      }
      
      ans = 1;
      solveCentroidDecomp;
      writeln(ans);
    }
  } catch (EOFException e) {
  }
}