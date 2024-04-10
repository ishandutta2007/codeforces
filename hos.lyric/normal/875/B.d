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


void bAdd(T)(T[] bit, int pos, T val)
in {
  assert(0 <= pos && pos < bit.length, "bAdd: 0 <= pos < |bit| must hold");
}
do {
  for (int x = pos; x < bit.length; x |= x + 1) {
    bit[x] += val;
  }
}

// sum of [0, pos)
T bSum(T)(T[] bit, int pos)
in {
  assert(0 <= pos && pos <= bit.length, "bSum: 0 <= pos <= |bit| must hold");
}
do {
  T ret = 0;
  for (int x = pos - 1; x >= 0; x = (x & (x + 1)) - 1) {
    ret += bit[x];
  }
  return ret;
}


// T, S: monoid
// opTT: T * T -> T
// opST: S * T * int -> T
//   (s t_a) ... (s t_{b-1}) = opST(s, t_a ... t_{b-1}, b - a)
// opSS: S * S -> S
// query(a, b, s): t_a <- s t_a, ..., t_{b-1} <- s t_{b-1};
//   returns t_a ... t_{b-1}
class SegmentTree(T, S, alias opTT, alias opST, alias opSS) {
  import std.functional : binaryFun;
  alias opTTFun = binaryFun!opTT;
  alias opSTFun = opST;
  alias opSSFun = binaryFun!opSS;
  const(T) idT;
  const(S) idS;

  int n;
  T[] ts;
  S[] ss;
  this(int n_, const(T) idT, const(S) idS) {
    this.idT = idT;
    this.idS = idS;
    for (n = 1; n < n_; n <<= 1) {}
    ts = new T[n << 1];
    ss = new S[n << 1];
    ts[] = idT;
    ss[] = idS;
  }
  ref T at(int a) {
    return ts[n + a];
  }
  void build() {
    foreach_reverse (a; 1 .. n) ts[a] = opTTFun(ts[a << 1], ts[a << 1 | 1]);
  }
  T query(int a, int b, const(S) s) {
    return query(1, 0, n, a, b, s);
  }

 private:
  T query(int u, int l, int r, int a, int b, const(S) s) {
    if (a < l) a = l;
    if (b > r) b = r;
    if (a >= b) return idT;
    if (a == l && b == r) {
      ts[u] = opSTFun(s, ts[u], r - l);
      ss[u] = opSSFun(s, ss[u]);
      return ts[u];
    }
    const int uL = u << 1, uR = u << 1 | 1;
    const int mid = (l + r) >> 1;
    // speed-up: if (ss[u] != idS)
    {
      ts[uL] = opSTFun(ss[u], ts[uL], mid - l);
      ts[uR] = opSTFun(ss[u], ts[uR], r - mid);
      ss[uL] = opSSFun(ss[u], ss[uL]);
      ss[uR] = opSSFun(ss[u], ss[uR]);
      ss[u] = idS;
    }
    const T resL = query(uL, l, mid, a, b, s);
    const T resR = query(uR, mid, r, a, b, s);
    ts[u] = opTTFun(ts[uL], ts[uR]);
    return opTTFun(resL, resR);
  }
}


enum INF = 10^^9;

void main() {
  try {
    for (; ; ) {
      const N = readInt();
      auto P = new int[N];
      foreach (i; 0 .. N) {
        P[i] = readInt() - 1;
      }
      
      auto bit = new int[N];
      auto seg = new SegmentTree!(int, int, max, (s, t, sz) => (s + t), "a + b")(N, -INF, 0);
      foreach (i; 0 .. N) {
        seg.at(i) = 0;
      }
      seg.build;
      
      auto ans = new int[N];
      foreach_reverse (i; 0 .. N) {
        const j = bit.bSum(P[i]);
        bit.bAdd(P[i], +1);
        const now = seg.query(P[i], P[i] + 1, 0);
        debug {
          writeln(i, " ", P[i], " ", j, " ", now);
        }
        seg.query(P[i], P[i] + 1, (P[i] - j) - now);
        seg.query(P[i] + 1, N, -1);
        ans[i] = max(seg.query(0, N, 0), 0);
      }
      
      foreach (i; 0 .. N) {
        write(ans[i] + 1, " ");
      }
      writeln(1);
    }
  } catch (EOFException e) {
  }
}