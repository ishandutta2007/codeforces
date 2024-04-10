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

int segN;
int[] seg;
void segInit() {
  for (segN = 1; segN < M; segN <<= 1) {}
  seg = new int[2 * segN];
  foreach (i; 0 .. M) {
    seg[segN + i] = C[i];
  }
  foreach_reverse (a; 1 .. segN) {
    seg[a] = min(seg[a << 1], seg[a << 1 | 1]);
  }
}
int segRangeMin(int a, int b) {
  int ret = N;
  for (a += segN, b += segN; a < b; a >>= 1, b >>= 1) {
    if (a & 1) chmin(ret, seg[a++]);
    if (b & 1) chmin(ret, seg[--b]);
  }
  return ret;
}


int[][] poss;
int[] as, bs;

int xsLen;
int[] xs;

bool[][] mem0;
bool[] mem1;
bool[][] mem2;
Mint[][] dp0;
Mint[] dp1;
Mint[][] dp2;

Mint calc0(int e, int f) {
  if (!mem0[e][f]) {
    if (e == f) {
      dp0[e][f] = Mint(1);
    } else {
      const u = segRangeMin(xs[e], xs[f]);
      const g = xs.lowerBound(as[u]);
      const h = xs.lowerBound(bs[u]);
      debug {
        // writeln("  calc0 ", e, " ", f, ": ", u, " ", g, " ", h);
      }
      dp0[e][f] = calc2(e, g) * calc1(u) * calc2(h, f);
    }
    debug {
      writeln("calc0 ", e, " ", f, " = ", dp0[e][f]);
    }
    mem0[e][f] = true;
  }
  return dp0[e][f];
}
Mint calc1(int u) {
  if (!mem1[u]) {
    dp1[u] = Mint(1);
    foreach (k; 0 .. cast(int)(poss[u].length) - 1) {
      if (poss[u][k] + 1 < poss[u][k + 1]) {
        const e = xs.lowerBound(poss[u][k] + 1);
        const f = xs.lowerBound(poss[u][k + 1]);
        dp1[u] *= calc0(e, f);
      }
    }
    debug {
      writeln("calc1 ", u, " = ", dp1[u]);
    }
    mem1[u] = true;
  }
  return dp1[u];
}
Mint calc2(int e, int f) {
  if (!mem2[e][f]) {
    for (int g = e; ; ) {
      debug {
        // writeln("  calc2 ", e, " ", f, ": ", g);
      }
      dp2[e][f] += calc0(e, g) * calc0(g, f);
      if (g == f) {
        break;
      }
      g = xs.lowerBound(bs[C[xs[g]]]);
    }
    debug {
      writeln("calc2 ", e, " ", f, " = ", dp2[e][f]);
    }
    mem2[e][f] = true;
  }
  return dp2[e][f];
}

void main() {
  try {
    for (; ; ) {
      N = readInt();
      M = readInt();
      C = new int[M];
      foreach (i; 0 .. M) {
        C[i] = readInt() - 1;
      }
      debug {
        writeln("C = ", C);
      }
      
      segInit();
      
      poss = new int[][N];
      foreach (i; 0 .. M) {
        poss[C[i]] ~= i;
      }
      as = new int[N];
      bs = new int[N];
      foreach (u; 0 .. N) {
        assert(!poss[u].empty);
        as[u] = poss[u][0];
        bs[u] = poss[u][$ - 1] + 1;
      }
      bool ok = true;
      foreach (u; 0 .. N) foreach (v; u + 1 .. N) {
        if (max(as[u], as[v]) < min(bs[u], bs[v])) {
          debug {
            writeln("intersecting ", u, " ", v);
          }
          // ok = ok && (as[u] <= as[v] && bs[v] <= bs[u]);
          const k = poss[u].lowerBound(as[v]) - 1;
          ok = ok && (k >= 0 && poss[u][k] + 1 <= as[v] && bs[v] <= poss[u][k + 1]);
        }
      }
      
      if (ok) {
        xs = (as.dup ~ bs.dup).sort.uniq.array;
        xsLen = cast(int)(xs.length);
        debug {
          writeln("xs = ", xs);
        }
        
        debug {
          foreach (u; 0 .. N) {
            writeln(u, ": ", poss[u]);
            foreach (k; 0 .. cast(int)(poss[u].length) - 1) {
              if (poss[u][k] + 1 < poss[u][k + 1]) {
                const e = xs.lowerBound(poss[u][k] + 1);
                const f = xs.lowerBound(poss[u][k + 1]);
                assert(xs[e] == poss[u][k] + 1);
                assert(xs[f] == poss[u][k + 1]);
              }
            }
          }
        }
        
        dp0 = new Mint[][](xsLen, xsLen);
        dp1 = new Mint[N];
        dp2 = new Mint[][](xsLen, xsLen);
        mem0 = new bool[][](xsLen, xsLen);
        mem1 = new bool[N];
        mem2 = new bool[][](xsLen, xsLen);
        const ans = calc0(0, xsLen - 1);
        writeln(ans);
      } else {
        writeln(0);
      }
    }
  } catch (EOFException e) {
  }
}