import std.conv, std.stdio, std.string;
import std.algorithm, std.array, std.bigint, std.container, std.math, std.range, std.regex, std.typecons;
import core.bitop, core.thread;

class EOFException : Throwable { this() { super("EOF"); } }
string[] tokens;
string readToken() { for (; tokens.empty; ) { if (stdin.eof) throw new EOFException; tokens = readln.split; } auto token = tokens[0]; tokens.popFront; return token; }
int readInt() { return readToken().to!int; }
long readLong() { return readToken().to!long; }
real readReal() { return readToken().to!real; }

void chmin(T)(ref T t, in T f) { if (t > f) t = f; }
void chmax(T)(ref T t, in T f) { if (t < f) t = f; }

int binarySearch(T)(in T[] as, in bool delegate(T) test) { int low = -1, upp = cast(int)(as.length); for (; low + 1 < upp; ) { int mid = (low + upp) >> 1; (test(as[mid]) ? low : upp) = mid; } return upp; }
int lowerBound(T)(in T[] as, in T val) { return as.binarySearch((T a) => (a < val)); }
int upperBound(T)(in T[] as, in T val) { return as.binarySearch((T a) => (a <= val)); }


// floor(a / m)
long floor(long a, long m) {
  return a / m - ((a % m < 0) ? 1 : 0);
}

// sum{ floor((a x + b) / m) | l <= x <= r }
// m > 0
long sumFloors(long m, long a, long b, long l, long r)
in (l > r || m > 0)
do {
  if (l > r) return 0;
  const q = floor(a, m);
  const aa = a - q * m;
  const ll = floor(aa * l + b, m) + 1;
  const rr = floor(aa * r + b, m);
  return q * ((r + 1) * r / 2 - l * (l - 1) / 2) + r * rr - (l - 1) * (ll - 1) + (rr - ll + 1) + sumFloors(aa, -m, b, ll, rr);
}
unittest {
  immutable long LIM = 10;
  foreach (m; 1 .. +LIM) foreach (a; -LIM .. +LIM) foreach (b; -LIM .. +LIM) foreach (l; -LIM .. +LIM) foreach (r; -LIM .. +LIM) {
    long expected;
    foreach (x; l .. r + 1) expected += floor(a * x + b, m);
    long received = sumFloors(m, a, b, l, r);
    assert(expected == received, format("sumFloors m=%s a=%s b=%s l=%s r=%s: Expected %s, Received %s", m, a, b, l, r, expected, received));
  }
}

immutable LIM = 10^^5 + 10;

int N;
int[] A;

void main() {
  try {
    for (; ; ) {
      N = readInt();
      A = new int[N];
      foreach (i; 0 .. N) {
        A[i] = readInt();
      }
      auto poss = new int[][LIM];
      foreach (i; 0 .. N) {
        for (int d = 1; d * d <= A[i]; ++d) {
          if (A[i] % d == 0) {
            poss[d] ~= i;
            if (d != A[i] / d) {
              poss[A[i] / d] ~= i;
            }
          }
        }
      }
      auto f = new long[LIM];
      foreach (d; 1 .. LIM) {
        const possLen = cast(int)(poss[d].length);
        for (int i = 0, j; i < possLen; i = j) {
          for (j = i; j < possLen && poss[d][j] == poss[d][i] + (j - i); ++j) {}
          f[d] += cast(long)(j - i) * cast(long)(j - i + 1) / 2;
        }
      }
      foreach_reverse (d; 1 .. LIM) {
        for (int e = d * 2; e < LIM; e += d) {
          f[d] -= f[e];
        }
      }
      Tuple!(long, long)[] ps;
      foreach (d; 1 .. LIM) {
        if (f[d] != 0) {
          ps ~= tuple!(long, long)(d, f[d]);
        }
      }
      // sentinel
      ps ~= tuple!(long, long)(LIM, 1);
      debug {
        writefln("ps = %s", ps);
      }
      
      auto psLen = cast(int)(ps.length);
      auto ps1Sum = new long[psLen + 1];
      auto ps01Sum = new long[psLen + 1];
      foreach (i; 0 .. psLen) {
        ps1Sum[i + 1] = ps1Sum[i] + ps[i][1];
        ps01Sum[i + 1] = ps01Sum[i] + ps[i][0] * ps[i][1];
      }
      long countLE(long val) {
        debug {
          writefln("countLE %s", val);
        }
        long ret;
        /*
        long[] b;
        foreach (i; 0 .. psLen - 1) {
          foreach (_; 0 .. ps[i][1]) {
            b ~= ps[i][0];
          }
        }
        foreach (x; 0 .. b.length) {
          long sum;
          foreach (y; x .. b.length) {
            sum += b[y];
            if (sum <= val) ++ret;
          }
        }
        debug {
          writefln("  ret = %s", ret);
        }
        return ret;
        //*/
        // min j s.t. ps[i][0] * ps[i][1] + ... + ps[j - 1][0] * ps[j - 1][1] > val
        auto js = new int[psLen + 1];
        for (int i = 0, j = 0; i <= psLen; ++i) {
          for (; j <= psLen && ps01Sum[j] - ps01Sum[i] <= val; ++j) {}
          js[i] = j;
        }
        debug {
          // writefln("  js = %s", js);
        }
        foreach (i; 0 .. psLen) {
          // (i, i)
          const numI = min(val / ps[i][0], ps[i][1] - 1);
          ret += ((ps[i][1] - 1) + (ps[i][1] - numI)) * numI / 2;
          // (i, i + 1), ..., (i, js[i] - 2)
          if (i + 1 <= js[i] - 2) {
            debug {
              // writefln("  (%s, %s), ..., (%s, %s)", i, i + 1, i, js[i] - 2);
            }
            ret += ps[i][1] * (ps1Sum[js[i] - 1] - ps1Sum[i + 1]);
          }
          foreach (j; max(js[i] - 1, i + 1) .. min(js[i + 1], psLen)) {
            /*
              ps[i][0] x + (ps01Sum[j] - ps01Sum[i + 1]) + ps[j][0] y <= val
              1 <= x <= ps[i][1]
              0 <= y <= ps[i][1] - 1
            */
            long sum;
            const s = val - (ps01Sum[j] - ps01Sum[i + 1]);
            const y0 = floor((s - ps[i][0] * ps[i][1]), ps[j][0]);
            const y1 = floor(s, ps[j][0]);
            if (0 <= y0) {
              sum += ps[i][1] * (min(y0, ps[j][1] - 1) - max(0, 0) + 1);
            }
            if (y0 + 1 <= y1) {
              sum += sumFloors(ps[i][0], -ps[j][0], s, max(y0 + 1, 0), min(y1, ps[j][1] - 1));
            }
            ret += sum;
            debug {
              int cnt;
              foreach (x; 1 .. ps[i][1] + 1) {
                foreach (y; 0 .. ps[j][1]) {
                  if (ps[i][0] * x + (ps01Sum[j] - ps01Sum[i + 1]) + ps[j][0] * y <= val) {
                    ++cnt;
                  }
                }
              }
              writefln("  (%s, %s): expected %s, received %s", i, j, cnt, sum);
              writefln("    s = %s, ps[i] = %s, ps[j] = %s", s, ps[i], ps[j]);
              writefln("    y0 = %s, y1 = %s", y0, y1);
              assert(cnt == sum);
            }
          }
        }
        debug {
          writefln("  ret = %s", ret);
        }
        return ret;
      }
      
      const bLen = cast(long)(N) * (cast(long)(N) + 1) / 2;
      const cLen = bLen * (bLen + 1) / 2;
      const medianPos = (cLen + 1) / 2;
      debug {
        writefln("medianPos = %s", medianPos);
      }
      long lo = 0, hi = ps01Sum[psLen];
      for (; lo + 1 < hi; ) {
        const mid = (lo + hi) / 2;
        ((countLE(mid) >= medianPos) ? hi : lo) = mid;
      }
      writeln(hi);
    }
  } catch (EOFException e) {
  }
}