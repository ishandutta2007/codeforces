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


// class Func = TX -> TY
//   for any f, g: Func, x -> sgn(g(x) - f(x)) must be monotone
class LiChaoTree(Func) {
  import std.algorithm : swap;
  alias TX = Func.TX;
  alias TY = Func.TY;
  const(TX) L, R;
  class Tree {
    Tree l, r;
    Func f;
    this(Func f) {
      this.f = f;
    }
  }
  Tree root;

  // [L, R)
  this(TX L, TX R) {
    assert(L <= R, "LiChaoTree: L <= R must hold");
    this.L = L;
    this.R = R;
  }
  // Add g to the whole [L, R)
  void add(Func g) {
    root = add(root, L, R, g);
  }
  // Add g to [a, b)
  void add(TX a, TX b, Func g) {
    root = add(root, L, R, a, b, g);
  }
  // Get max at a
  TY opCall(TX a) {
    TY mx = TY.min;
    TX l = L, r = R;
    for (Tree u = root; u; ) {
      if (u.f) {
        const fX = u.f(a);
        if (mx < fX) mx = fX;
      }
      const mid = l + (r - l) / 2;
      if (a < mid) {
        u = u.l; r = mid;
      } else {
        u = u.r; l = mid;
      }
    }
    return mx;
  }

 private:
  Tree add(Tree u0, TX l, TX r, Func g) {
    if (!u0) return new Tree(g);
    TY gL = g(l), gR = g(r);
    for (Tree u = u0; ; ) {
      TY fL = u.f ? u.f(l) : TY.min, fR = u.f ? u.f(r) : TY.min;
      if (fL >= gL && fR >= gR) return u0;
      if (fL <= gL && fR <= gR) { u.f = g; return u0; }
      const mid = l + (r - l) / 2;
      TY fMid = u.f(mid), gMid = g(mid);
      if (fMid < gMid) {
        swap(u.f, g);
        if (!g) return u0;
        if (gL < fL) {
          if (!u.l) { u.l = new Tree(g); return u0; }
          u = u.l; r = mid; gL = fL; gR = fMid;
        } else {
          if (!u.r) { u.r = new Tree(g); return u0; }
          u = u.r; l = mid; gL = fMid; gR = fR;
        }
      } else {
        if (fL < gL) {
          if (!u.l) { u.l = new Tree(g); return u0; }
          u = u.l; r = mid; gR = gMid;
        } else {
          if (!u.r) { u.r = new Tree(g); return u0; }
          u = u.r; l = mid; gL = gMid;
        }
      }
    }
  }
  Tree add(Tree u, TX l, TX r, TX a, TX b, Func g) {
    if (b <= l || r <= a) return u;
    if (a <= l && r <= b) return add(u, l, r, g);
    if (u && u.f && u.f(l) >= g(l) && u.f(r) >= g(r)) return u;
    if (!u) u = new Tree(null);
    const mid = l + (r - l) / 2;
    u.l = add(u.l, l, mid, a, b, g);
    u.r = add(u.r, mid, r, a, b, g);
    return u;
  }
}

// y = p x + q
class Line {
  alias TX = long;
  alias TY = long;
  long p, q;
  this(long p, long q) {
    this.p = p;
    this.q = q;
  }
  TY opCall(TX x) {
    return p * x + q;
  }
}


enum INF = 10L^^18;
enum LIM = 10^^5 + 10;

int N;
long[] A, B;
int[] U, V;

int[][] G;
long[] dp;
Line[][] liness;
LiChaoTree!Line[] lcts;

void dfs(int u, int p) {
  liness[u] = [];
  lcts[u] = new LiChaoTree!Line(-LIM, LIM);
  foreach (i; G[u]) {
    const v = U[i] ^ V[i] ^ u;
    if (v != p) {
      dfs(v, u);
      if (liness[u].length < liness[v].length) {
        swap(liness[u], liness[v]);
        swap(lcts[u], lcts[v]);
      }
      liness[u] ~= liness[v];
      foreach (l; liness[v]) {
        lcts[u].add(l);
      }
    }
  }
  if (liness[u]) {
    dp[u] = -lcts[u](A[u]);
  } else {
    // leaf
    dp[u] = 0;
  }
  auto l = new Line(-B[u], -dp[u]);
  liness[u] ~= l;
  lcts[u].add(l);
}

void main() {
  try {
    for (; ; ) {
      N = readInt();
      A = new long[N];
      foreach (u; 0 .. N) {
        A[u] = readLong();
      }
      B = new long[N];
      foreach (u; 0 .. N) {
        B[u] = readLong();
      }
      U = new int[N - 1];
      V = new int[N - 1];
      foreach (i; 0 .. N - 1) {
        U[i] = readInt() - 1;
        V[i] = readInt() - 1;
      }
      
      G = new int[][N];
      foreach (i; 0 .. N - 1) {
        G[U[i]] ~= i;
        G[V[i]] ~= i;
      }
      dp.length = N;
      liness.length = N;
      lcts.length = N;
      dfs(0, -1);
      foreach (u; 0 .. N) {
        if (u > 0) write(" ");
        write(dp[u]);
      }
      writeln();
    }
  } catch (EOFException e) {
  }
}