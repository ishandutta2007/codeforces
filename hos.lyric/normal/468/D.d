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


// T: monoid
// op: T * T -> T
// query(a, b): returns t_a ... t_{b-1}
class SegmentTree(T, alias op) {
  import std.functional : binaryFun;
  alias opFun = binaryFun!op;
  const(T) idT;

  int n;
  T[] ts;
  this(int n_, const(T) idT) {
    this.idT = idT;
    for (n = 1; n < n_; n <<= 1) {}
    ts = new T[n << 1];
    ts[] = idT;
  }
  this(inout(T)[] ts_, const(T) idT) {
    this.idT = idT;
    const n_ = cast(int)(ts_.length);
    for (n = 1; n < n_; n <<= 1) {}
    ts = new T[n << 1];
    ts[0 .. n] = idT;
    ts[n .. n + n_] = ts_[];
    ts[n + n_ .. n << 1] = idT;
    build();
  }
  ref T at(int a) {
    return ts[n + a];
  }
  void build() {
    foreach_reverse (a; 1 .. n) ts[a] = opFun(ts[a << 1], ts[a << 1 | 1]);
  }
  void set(int a, const(T) val) {
    ts[a += n] = val;
    for (; a >>= 1; ) ts[a] = opFun(ts[a << 1], ts[a << 1 | 1]);
  }
  void mulL(int a, const(T) val) {
    set(a, opFun(val, ts[a + n]));
  }
  void mulR(int a, const(T) val) {
    set(a, opFun(ts[a + n], val));
  }
  T query(int a, int b) const {
    T prodL = idT, prodR = idT;
    for (a += n, b += n; a < b; a >>= 1, b >>= 1) {
      if (a & 1) prodL = opFun(prodL, ts[a++]);
      if (b & 1) prodR = opFun(ts[--b], prodR);
    }
    return opFun(prodL, prodR);
  }

  // min b s.t. pred(prod of [a, b)) (or n + 1 if no such b)
  //   0 <= a <= n
  //   assume pred(prod of [a, b)) is non-decreasing in b
  int binarySearchR(int a, bool delegate(T) pred) const {
    if (pred(idT)) return a;
    if (a == n) return n + 1;
    T prod = idT;
    for (a += n; ; a >>= 1) {
      if (a & 1) {
        if (pred(opFun(prod, ts[a]))) {
          for (; a < n; ) {
            a <<= 1;
            if (!pred(opFun(prod, ts[a]))) {
              prod = opFun(prod, ts[a++]);
            }
          }
          return a - n + 1;
        }
        prod = opFun(prod, ts[a++]);
        if (!(a & a - 1)) return n + 1;
      }
    }
  }

  // max a s.t. pred(prod of [a, b)) (or -1 if no such a)
  //   0 <= b <= n
  //   assume pred(prod of [a, b)) is non-increasing in a
  int binarySearchL(int b, bool delegate(T) pred) const {
    if (pred(idT)) return b;
    if (b == 0) return -1;
    T prod = idT;
    for (b += n; ; b >>= 1) {
      if ((b & 1) || b == 2) {
        if (pred(opFun(prod, ts[b - 1]))) {
          for (; b <= n; ) {
            b <<= 1;
            if (!pred(opFun(prod, ts[b - 1]))) {
              prod = opFun(prod, ts[--b]);
            }
          }
          return b - n - 1;
        }
        prod = opFun(prod, ts[--b]);
        if (!(b & b - 1)) return -1;
      }
    }
  }
}


int N;
int[] A, B;
long[] C;

int[][] G;
int[] sz;

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

int[] rs;
long[] dist;

void dfsDist(int u, int p, int r, long d) {
  rs[u] = r;
  dist[u] = d;
  foreach (i; G[u]) {
    const v = A[i] ^ B[i] ^ u;
    if (v != p) {
      dfsDist(v, u, r, d + C[i]);
    }
  }
}

void main() {
  try {
    for (; ; ) {
      N = readInt();
      A = new int[N - 1];
      B = new int[N - 1];
      C = new long[N - 1];
      foreach (i; 0 .. N - 1) {
        A[i] = readInt() - 1;
        B[i] = readInt() - 1;
        C[i] = readLong();
      }
      
      G = new int[][N];
      foreach (i; 0 .. N - 1) {
        G[A[i]] ~= i;
        G[B[i]] ~= i;
      }
      sz = new int[N];
      dfsSz(0, -1);
      
      int rt;
      for (int u = 0; ; ) {
        int vm = -1;
        foreach (i; G[u]) {
          const v = A[i] ^ B[i] ^ u;
          if (vm == -1 || sz[vm] < sz[v]) {
            vm = v;
          }
        }
        if (vm == -1 || 2 * sz[vm] <= sz[u]) {
          rt = u;
          break;
        }
        sz[u] -= sz[vm];
        sz[vm] += sz[u];
        u = vm;
      }
      rs = new int[N];
      dist = new long[N];
      rs[rt] = rt;
      dist[rt] = 0;
      foreach (i; G[rt]) {
        const r = A[i] ^ B[i] ^ rt;
        dfsDist(r, rt, r, C[i]);
      }
      debug {
        writeln("rt = ", rt);
        writeln("rs = ", rs);
        writeln("dist = ", dist);
      }
      
      alias Pair = Tuple!(int, "x", int, "y");
      Pair cat(const(Pair) a, const(Pair) b) {
        int[] zs;
        foreach (z; [a.x, a.y, b.x, b.y]) {
          if (z != -1 && zs.count(z) == 0) {
            zs ~= z;
          }
        }
        zs ~= -1;
        zs ~= -1;
        return Pair(zs[0], zs[1]);
      }
      auto seg = new SegmentTree!(Pair, cat)(N, Pair(-1, -1));
      foreach (u; 0 .. N) {
        seg.at(u) = Pair(rs[u], -1);
      }
      seg.build;
      
      auto uss = new int[][N];
      foreach (u; 0 .. N) {
        uss[rs[u]] ~= u;
      }
      auto usLens = new int[N];
      auto poss = new int[N];
      // Hall: sz[v] + sz'[v] <= n
      alias Entry = Tuple!(int, "val", int, "r");
      auto set = new RedBlackTree!Entry;
      set.insert(Entry(-1, -1));
      void setInsert(int r) {
        if (r != rt) {
          set.insert(Entry(sz[r] + (usLens[r] - poss[r]), r));
        }
      }
      void setRemove(int r) {
        if (r != rt) {
          set.removeKey(Entry(sz[r] + (usLens[r] - poss[r]), r));
        }
      }
      foreach (r; 0 .. N) {
        usLens[r] = cast(int)(uss[r].length);
        if (r != rt && usLens[r] > 0) {
          set.insert(Entry(sz[r] + usLens[r], r));
        }
      }
      
      auto ans = new int[N];
      foreach (u; 0 .. N) {
        setRemove(rs[u]); --sz[rs[u]]; setInsert(rs[u]);
        int v = seg.binarySearchR(0, (const(Pair) a) {
          if (u == rt) {
            return (a.x != -1);
          } else {
            return ((a.x != -1 && a.x != rs[u]) || (a.y != -1 && a.y != rs[u]));
          }
        }) - 1;
        debug {
          writeln("u = ", u);
          writeln("  set = ", set);
          writeln("  attempt v = ", v);
        }
        assert(0 <= v); assert(v < N);
        assert(uss[rs[v]][poss[rs[v]]] == v);
        setRemove(rs[v]); ++poss[rs[v]]; setInsert(rs[v]);
        if (set.back.val > N - 1 - u) {
          const r0 = set.back.r;
          setRemove(rs[v]); --poss[rs[v]]; setInsert(rs[v]);
          v = uss[r0][poss[r0]];
          setRemove(rs[v]); ++poss[rs[v]]; setInsert(rs[v]);
        }
        debug {
          writeln("  chosen v = ", v);
        }
        ans[u] = v;
        seg.set(v, Pair(-1, -1));
      }
      
      writeln(2 * dist.sum);
      foreach (u; 0 .. N) {
        if (u > 0) write(" ");
        write(ans[u] + 1);
      }
      writeln;
    }
  } catch (EOFException e) {
  }
}