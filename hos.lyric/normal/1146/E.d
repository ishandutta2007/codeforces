import std.conv, std.functional, std.stdio, std.string;
import std.algorithm, std.array, std.bigint, std.complex, std.container, std.math, std.numeric, std.range, std.regex, std.typecons;
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


enum IDENTITY = 0b10;

int comp(int f, int g) {
  return ((f >> ((g >> 0) & 1)) & 1) << 0 | ((f >> ((g >> 1) & 1)) & 1) << 1;
}

class SegmentTree {
  int n;
  int[] fun, add;
  this(int n_) {
    for (n = 1; n < n_; n <<= 1) {}
    fun = new int[n << 1];
    add = new int[n << 1];
    fun[] = IDENTITY;
    add[] = IDENTITY;
  }
  // [a, b)
  private int query(int u, int x, int y, int a, int b, int val) {
    chmax(a, x);
    chmin(b, y);
    if (a >= b) {
      return -1;
    }
    if (a == x && b == y) {
      fun[u] = comp(val, fun[u]);
      add[u] = comp(val, add[u]);
      return fun[u];
    }
    assert(u < n);
    const uL = u << 1 | 0;
    const uR = u << 1 | 1;
    const mid = (x + y) >> 1;
    if (add[u] != IDENTITY) {
      fun[uL] = comp(add[u], fun[uL]);
      fun[uR] = comp(add[u], fun[uR]);
      add[uL] = comp(add[u], add[uL]);
      add[uR] = comp(add[u], add[uR]);
      add[u] = IDENTITY;
    }
    const resL = query(uL, x, mid, a, b, val);
    const resR = query(uR, mid, y, a, b, val);
    fun[u] = fun[uL];
    return (resL != -1) ? resL : resR;
  }
  // [a, b]
  int query(int a, int b, int val) {
    return query(1, 0, n, a, b + 1, val);
  }
}


int N, Q;
int[] A;
string[] S;
int[] X;

void main() {
  debug {
    foreach (f; 0 .. 4) foreach (g; 0 .. 4) {
      writeln(f, " o ", g, " = ", comp(f, g));
    }
  }
  
  try {
    for (; ; ) {
      N = readInt();
      Q = readInt();
      A = new int[N];
      foreach (i; 0 .. N) {
        A[i] = readInt();
      }
      S = new string[Q];
      X = new int[Q];
      foreach (q; 0 .. Q) {
        S[q] = readToken();
        X[q] = readInt();
      }
      
      auto ps = new Tuple!(int, int)[N];
      foreach (i; 0 .. N) {
        ps[i] = tuple(A[i], i);
      }
      ps.sort;
      auto as = new int[N];
      foreach (i; 0 .. N) {
        as[i] = ps[i][0];
      }
      
      auto seg = new SegmentTree(N);
      foreach (q; 0 .. Q) {
        switch (S[q]) {
          case "<": {
            /*
              a < x <=> a < x
              -a < x <=> a > -x
            */
            const posP = as.lowerBound(+X[q]);
            const posM = as.upperBound(-X[q]);
            if (X[q] > 0) {
              // 0 -x] 01 [x 1
              seg.query(0, posM - 1, 0b11);
              seg.query(posM, posP - 1, 0b01);
              seg.query(posP, N - 1, 0b00);
            } else {
              // 0 [x  -x] 1
              seg.query(0, posP - 1, 0b11);
              seg.query(posM, N - 1, 0b00);
            }
          } break;
          case ">": {
            /*
              a > x <=> a > x
              -a > x <=> a < -x
            */
            const posP = as.upperBound(+X[q]);
            const posM = as.lowerBound(-X[q]);
            if (X[q] > 0) {
              // 1 [-x  x] 0
              seg.query(0, posM - 1, 0b00);
              seg.query(posP, N - 1, 0b11);
            } else {
              // 1 x] 01 [-x 0
              seg.query(0, posP - 1, 0b00);
              seg.query(posP, posM - 1, 0b01);
              seg.query(posM, N - 1, 0b11);
            }
          } break;
          default: assert(false);
        }
      }
      
      auto ans = new int[N];
      foreach (i; 0 .. N) {
        const f = seg.query(i, i + 1, IDENTITY);
        ans[ps[i][1]] = (((f >> 0) & 1) ? -1 : +1) * ps[i][0];
      }
      writeln(ans.to!string.replaceAll(regex(`[\[\],]`), ""));
    }
  } catch (EOFException e) {
  }
}