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

// min pos s.t. pred(sum of [0, pos))
//   assume pred(sum of [0, pos)) is non-decreasing
int bBinarySearch(alias pred, T)(T[] bit) {
  import core.bitop : bsr;
  import std.functional : unaryFun;
  alias predFun = unaryFun!pred;
  if (predFun(0)) return 0;
  int pos = 0;
  T sum = 0;
  foreach_reverse (e; 0 .. bsr(bit.length) + 1) {
    const x = (pos | 1 << e) - 1;
    if (x < bit.length && !predFun(sum + bit[x])) {
      pos |= 1 << e;
      sum += bit[x];
    }
  }
  return pos + 1;
}


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
}

// t -> min(t + p, q);
alias Func = Tuple!(int, "p", int, "q");

enum IDENTITY = Func(0, 10^^9);

// g \circ f
Func mul(const(Func) f, const(Func) g) {
  return Func(f.p + g.p, min(f.q + g.p, g.q));
}


void main() {
  try {
    for (; ; ) {
      const N = readInt();
      auto A = new int[N];
      foreach (i; 0 .. N) {
        A[i] = readInt();
      }
      
      alias Entry = Tuple!(int, "a", int, "i");
      auto es = new Entry[N];
      foreach (i; 0 .. N) {
        es[i] = Entry(A[i], i);
      }
      es.sort;
      es ~= Entry(int.max, -1);
      auto poss = new int[N];
      foreach (j; 0 .. N) {
        poss[es[j].i] = j;
      }
      debug {
        writeln("es = ", es);
      }
      
      auto bitNum = new int[N];
      int get(int l) {
        const res = bitNum.bBinarySearch!(sum => (sum >= l + 1));
        return res - 1;
      }
      
      auto seg = new SegmentTree!(Func, mul)(N, IDENTITY);
      
      int k;
      foreach (n; 1 .. N + 1) {
        const i = n - 1;
        bitNum.bAdd(poss[i], 1);
        seg.set(poss[i], Func(1, A[i]));
        for (; k < n && -k > es[get(k)].a; ++k) {}
        debug {
          writefln("%s: %s", A[0 .. n].dup.sort, k);
        }
        const res = seg.query(get(k), N);
        const ans = min(-k + res.p, res.q);
        writeln(ans);
      }
      
      debug {
        auto brt = new int[N + 1];
        brt[] = -N;
        foreach (n; 0 .. N + 1) {
          auto perm = A[0 .. n].dup;
          perm.sort;
          do {
            int x;
            foreach (a; perm) {
              if (x < a) {
                ++x;
              } else if (x > a) {
                --x;
              }
            }
            chmax(brt[n], x);
          } while (perm.nextPermutation);
        }
        foreach (n; 0 .. N + 1) {
          auto perm = A[0 .. n].dup;
          perm.sort;
          do {
            int x;
            int[] ds;
            foreach (a; perm) {
              if (x < a) {
                ++x;
                ds ~= +1;
              } else if (x > a) {
                --x;
                ds ~= -1;
              } else {
                ds ~= 0;
              }
            }
            if (brt[n] == x) {
              // writeln(perm, " ", ds);
            }
          } while (perm.nextPermutation);
        }
        writeln("brt = ", brt);
      }
    }
  } catch (EOFException e) {
  }
}