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


enum INF = 10L^^18;
alias Entry = Tuple!(long, "val", int, "key");

class SegmentTree {
  int n;
  Entry[] mx;
  long[] add;
  this(long[] ini) {
    const n_ = cast(int)(ini.length);
    for (n = 1; n < n_; n <<= 1) {}
    mx = new Entry[n << 1];
    add = new long[n << 1];
    mx[] = Entry(-INF, -1);
    add[] = 0;
    foreach (i; 0 .. n_) {
      mx[n + i] = Entry(ini[i], i);
    }
    foreach_reverse (a; 1 .. n) {
      mx[a] = max(mx[a << 1], mx[a << 1 | 1]);
    }
  }
  // [a, b)
  private Entry query(int u, int x, int y, int a, int b, long val) {
    chmax(a, x);
    chmin(b, y);
    if (a >= b) {
      return Entry(-INF, -1);
    }
    if (a == x && b == y) {
      mx[u].val += val;
      add[u] += val;
      return mx[u];
    }
    assert(u < n);
    const uL = u << 1 | 0;
    const uR = u << 1 | 1;
    const mid = (x + y) >> 1;
    if (add[u] != 0) {
      mx[uL].val += add[u];
      mx[uR].val += add[u];
      add[uL] += add[u];
      add[uR] += add[u];
      add[u] = 0;
    }
    const resL = query(uL, x, mid, a, b, val);
    const resR = query(uR, mid, y, a, b, val);
    mx[u] = max(mx[uL], mx[uR]);
    return max(resL, resR);
  }
  // [a, b)
  Entry query(int a, int b, long val) {
    return query(1, 0, n, a, b, val);
  }
}


int N;
long[] S;

void main() {
  try {
    for (; ; ) {
      N = readInt();
      S = new long[N];
      foreach (i; 0 .. N) {
        S[i] = readLong();
      }
      
      S[] *= -1;
      debug {
        writeln("S = ", S);
      }
      auto seg = new SegmentTree(S);
      auto ans = new int[N];
      
      foreach (x; 1 .. N + 1) {
        const e = seg.query(0, N, 0);
        debug {
          writefln("x = %s: e = %s", x, e);
        }
        assert(e.val == 0);
        ans[e.key] = x;
        seg.query(e.key, e.key + 1, -INF);
        seg.query(e.key + 1, N, x);
      }
      
      foreach (i; 0 .. N) {
        if (i > 0) {
          write(" ");
        }
        write(ans[i]);
      }
      writeln();
    }
  } catch (EOFException e) {
  }
}