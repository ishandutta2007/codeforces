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

enum MO = 10^^9 + 403;
alias Mint = ModInt!MO;


int solve(int n, bool[][] adj) {
  debug {
    writeln("solve ", n, " ", adj);
  }
  auto as = new int[n];
  foreach (u; 0 .. n) foreach (v; 0 .. n) {
    if (adj[u][v]) {
      as[u] |= 1 << v;
    }
  }
  if (n == 0) {
    return 0;
  }
  if (as.all!"a == 0") {
    return 1;
  }
  auto ind = new long[1 << n];
  ind[0] = 1;
  foreach (u; 0 .. n) {
    foreach (p; 0 .. 1 << u) {
      ind[p | 1 << u] = ind[p] + ind[p &~ as[u]];
    }
  }
  debug {
    writeln("ind = ", ind);
  }
  int lo = 1, hi = n;
  auto fs = new Mint[1 << n];
  for (; lo + 1 < hi; ) {
    const mid = (lo + hi) / 2;
    foreach (p; 0 .. 1 << n) {
      fs[p] = Mint(ind[p])^^mid;
    }
    Mint sum;
    foreach (p; 0 .. 1 << n) {
      sum += (-1)^^(popcnt(p) & 1) * fs[p];
    }
    (sum ? hi : lo) = mid;
  }
  return hi;
}

void main() {
  try {
    for (; ; ) {
      const N = readInt();
      auto A = new string[N];
      foreach (u; 0 .. N) {
        A[u] = readToken();
      }
      
      auto uf = new int[N];
      uf[] = -1;
      foreach (u; 0 .. N) foreach (v; u + 1 .. N) {
        if (A[u][v] == 'A') {
          uf.connect(u, v);
        }
      }
      bool ok = true;
      foreach (u; 0 .. N) foreach (v; u + 1 .. N) {
        if (A[u][v] == 'X') {
          ok = ok && (uf.root(u) != uf.root(v));
        }
      }
      if (ok) {
        int n;
        auto ids = new int[N];
        ids[] = -1;
        foreach (r; 0 .. N) {
          if (uf[r] < 0) {
            if (-uf[r] >= 2) {
              ids[r] = n++;
            }
          }
        }
        auto adj = new bool[][](n, n);
        foreach (u; 0 .. N) foreach (v; u + 1 .. N) {
          if (A[u][v] == 'X') {
            const x = ids[uf.root(u)];
            const y = ids[uf.root(v)];
            if (x != -1 && y != -1) {
              adj[x][y] = adj[y][x] = true;
            }
          }
        }
        const res = solve(n, adj);
        writeln(N - 1 + res);
      } else {
        writeln(-1);
      }
    }
  } catch (EOFException e) {
  }
}