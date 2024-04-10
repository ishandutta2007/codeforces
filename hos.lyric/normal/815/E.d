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


long[long][long] cache;
long calc(long d, long m) {
  long ret;
  if (d !in cache) {
    long[long] tmp;
    cache[d] = tmp;
  }
  cache[d].update(m, {
    if (m > 1) {
      const half = m / 2;
      if (half >= d) {
        ret += 1;
        ret += calc(d, m / 2);
        ret += calc(d, m - m / 2);
      }
    }
    debug {
      writefln("calc %s %s = %s", d, m, ret);
    }
    return ret;
  }, (ref long r) {
    return ret = r;
  });
  return ret;
}

long solve(long d, long a, long b, long k) {
  assert(1 <= k);
  assert(k <= calc(d, b - a));
  long ret;
  const mid = (a + b) / 2;
  if (k == 1) {
    ret = mid;
  } else {
    assert(b - a > 1);
    const resL0 = calc(d, mid - a);
    const resR1 = calc(d + 1, b - mid);
    assert(k > 0);
    if (k <= 1 + resL0 + resR1) {
      ret = solve(d, a, mid, k - 1 - resR1);
    } else {
      ret = solve(d, mid, b, k - 1 - resL0);
    }
  }
  debug {
    writefln("solve %s %s %s %s = %s", d, a, b, k, ret);
  }
  return ret;
}

void main() {
  try {
    for (; ; ) {
      const N = readLong();
      const K = readLong();
      debug {
        writefln("==== N = %s, K = %s ====", N, K);
        cache.clear;
      }
      
      long ans;
      if (K == 1) {
        ans = 1;
      } else if (K == 2) {
        ans = N;
      } else {
        long lo = 0, hi = N;
        for (; lo + 1 < hi; ) {
          const mid = (lo + hi) / 2;
          ((2 + calc(mid, N - 1) >= K) ? lo : hi) = mid;
        }
        debug {
          writeln("lo = ", lo);
          cache.clear;
        }
        ans = solve(lo, 1, N, K - 2);
      }
      writeln(ans);
      
      debug {
        if (N <= 300) {
          auto used = new bool[N + 1];
          foreach (k; 1 .. K + 1) {
            long mx;
            long im = -1;
            foreach (i; 1 .. N + 1) {
              if (!used[i]) {
                long score = N;
                foreach (j; 1 .. N + 1) {
                  if (used[j]) {
                    chmin(score, abs(j - i));
                  }
                }
                if (chmax(mx, score)) {
                  im = i;
                }
              }
            }
            used[im] = true;
            if (k == K) {
              writeln("brt = ", im);
              assert(im == ans, format("WA %s %s: %s %s", N, K, im, ans));
            }
          }
        }
      }
    }
  } catch (EOFException e) {
  }
}