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


alias Value = int;
int root(int[] ps, Value[] qs, int u) {
  if (ps[u] < 0) {
    return u;
  } else {
    int r = root(ps, qs, ps[u]);
    // qs[u] += qs[ps[u]];
    qs[u] ^= qs[ps[u]];
    return (ps[u] = r);
  }
}
bool connect(int[] ps, Value[] qs, int u, int v, Value c) {
  int ru = root(ps, qs, u);
  int rv = root(ps, qs, v);
  // const Value cc = c + qs[u] - qs[v];
  const Value cc = c ^ qs[u] ^ qs[v];
  if (ru == rv) return (cc == 0);
  // if (ps[ru] > ps[rv]) { swap(ru, rv); cc *= -1; }
  if (ps[ru] > ps[rv]) { swap(ru, rv); }
  ps[ru] += ps[rv]; ps[rv] = ru; qs[rv] = cc;
  return true;
}


alias Card = Tuple!(int, "a", int, "b");

int N;
Card[] C;

int brute() {
  int ans = N + 1;
  foreach (p; 0 .. 1 << N) {
    foreach (u; 0 .. N) if (p & 1 << u) swap(C[u].a, C[u].b);
    bool ok = true;
    foreach (u; 0 .. N) foreach (v; 0 .. N) {
      if (C[u].a < C[v].a) {
        ok = ok && (C[u].b > C[v].b);
      }
    }
    if (ok) {
      chmin(ans, popcnt(p));
    }
    foreach (u; 0 .. N) if (p & 1 << u) swap(C[u].a, C[u].b);
  }
  return (ans > N) ? -1 : ans;
}

int solve() {
  auto ps = new int[2 * N];
  auto qs = new int[2 * N];
  ps[] = -1;
  
  C.sort!((c0, c1) => (min(c0.a, c0.b) < min(c1.a, c1.b)));
  foreach (u; 0 .. N) {
    if (C[u].a < C[u].b) {
      connect(ps, qs, u, N + u, 0);
    } else {
      swap(C[u].a, C[u].b);
      connect(ps, qs, u, N + u, 1);
    }
  }
  
  int minB = 2 * N + 1, maxA = 0;
  foreach (u; 0 .. N) {
    chmin(minB, C[u].b);
    chmax(maxA, C[u].a);
  }
  if (minB < maxA) {
    return -1;
  }
  
  int[] us, vs;
  foreach (u; 0 .. N) {
    if (us.empty || C[us[$ - 1]].b > C[u].b) {
      us ~= u;
    } else if (vs.empty || C[vs[$ - 1]].b > C[u].b) {
      vs ~= u;
    } else {
      return -1;
    }
  }
  const usLen = cast(int)(us.length);
  const vsLen = cast(int)(vs.length);
  debug {
    // writeln("C = ", C);
    // writeln("us = ", us);
    // writeln("vs = ", vs);
  }
  
  auto vals = new int[vsLen + 1];
  {
    int f;
    foreach (e; 0 .. usLen) {
      for (; f < vsLen && vs[f] < us[e]; ++f) {}
      int lo = f - 1, hi = vsLen;
      for (; lo + 1 < hi; ) {
        const mid = (lo + hi) / 2;
        ((C[us[e]].b < C[vs[mid]].b) ? lo : hi) = mid;
      }
      // e - [f, lo]
      if (f <= lo) {
        debug {
          // writefln("%s: [%s, %s]", e, f, lo);
        }
        if (!connect(ps, qs, us[e], vs[f], 1)) {
          return false;
        }
        ++vals[f];
        --vals[lo];
      }
    }
  }
  foreach (f; 0 .. vsLen) {
    vals[f + 1] += vals[f];
  }
  debug {
    // writeln("vals = ", vals);
  }
  foreach (f; 0 .. vsLen - 1) {
    if (vals[f] > 0) {
      debug {
        // writefln("connect0 %s %s", vs[f], vs[f + 1]);
      }
      if (!connect(ps, qs, vs[f], vs[f + 1], 0)) {
        return false;
      }
    }
  }
  
  auto cnt = new int[][](2 * N, 2);
  foreach (u; 0 .. N) {
    const r = root(ps, qs, N + u);
    ++cnt[r][qs[N + u]];
  }
  debug {
    // writeln("cnt = ", cnt);
    // writeln("ps = ", ps);
    // writeln("qs = ", qs);
  }
  int ans;
  foreach (r; 0 .. 2 * N) {
    ans += min(cnt[r][0], cnt[r][1]);
  }
  return ans;
}

void main() {
  try {
    for (; ; ) {
      N = readInt();
      C = new Card[N];
      foreach (u; 0 .. N) {
        C[u].a = readInt();
        C[u].b = readInt();
      }
      
      debug {
        const CSave = C.dup;
        const brt = brute();
      }
      
      const ans = solve();
      writeln(ans);
      
      debug {
        assert(brt == ans, format("%s: %s %s", CSave, brt, ans));
      }
    }
  } catch (EOFException e) {
  }
}