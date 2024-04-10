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


long M;
int N;
long[] A, B;

void main() {
  try {
    for (; ; ) {
      M = readLong();
      N = readInt();
      A = new long[N];
      foreach (i; 0 .. N) {
        A[i] = readLong() % M;
      }
      B = new long[N];
      foreach (j; 0 .. N) {
        B[j] = readLong() % M;
      }
      
      auto as = new Tuple!(long, int)[N];
      auto bs = new Tuple!(long, int)[N];
      foreach (i; 0 .. N) {
        as[i] = tuple(A[i], i);
      }
      sort(as);
      foreach (j; 0 .. N) {
        bs[j] = tuple(B[j], j);
        for (; bs[j][0] < as[0][0] - M / 2; bs[j][0] += M) {}
        for (; bs[j][0] >= as[0][0] - M / 2 + M; bs[j][0] -= M) {}
      }
      sort(bs);
      bs.length = 2 * N;
      foreach (j; 0 .. N) {
        bs[j + N] = bs[j];
        bs[j + N][0] += M;
      }
      debug {
        // writeln("as[*][0] = ", as.map!"a[0]");
        // writeln("bs[*][0] = ", bs.map!"a[0]");
      }
      
      // exact 0: B - A
      Tuple!(int, long)[] events;
      foreach (i; 0 .. N) {
        /*
          as[i]
          paired with bs[i], bs[i + 1], ..., bs[i + N - 1]
          + -> -
        */
        const j = bs.lowerBound(tuple(as[i][0], -1));
        debug {
          // writeln("i = ", i, ": ", j);
        }
        events ~= tuple(0, as[i][0]);
        events ~= tuple(min(max(j - i, 0), N + 1), -2 * as[i][0]);
      }
      foreach (j; 0 .. N) {
        /*
          bs[j]
          paired with as[j], as[j - 1], ..., as[0]
          - -> +
          
          k = j + 1
          
          bs[j + N]
          paired with as[N - 1], as[N - 2], ..., as[j + 1], as[j]
          - -> +
        */
        const i0 = as.lowerBound(tuple(bs[j][0], N)) - 1;
        const i1 = as.lowerBound(tuple(bs[j + N][0], N)) - 1;
        debug {
          // writeln("j = ", j, ": ", i0, " ", i1);
        }
        events ~= tuple(0, -bs[j][0]);
        events ~= tuple(min(max(j - i0, 0), j + 1), 2 * bs[j][0]);
        events ~= tuple(j + 1, -bs[j][0] - bs[j + N][0]);
        events ~= tuple(min(max(j + N - i1, j + 1), N + 1), 2 * bs[j + N][0]);
      }
      sort(events);
      events ~= tuple(N + 1, 0L);
      debug {
        // writeln("events = ", events);
      }
      
      long ans = M * N;
      int km;
      long now;
      int pos;
      foreach (k; 0 .. N + 1) {
        for (; events[pos][0] <= k; ++pos) {
          now += events[pos][1];
        }
        debug {
          // writeln("k = ", k, ": ", now);
          long sum;
          foreach (i; 0 .. N) {
            sum += abs(as[i][0] - bs[i + k][0]);
          }
          assert(sum == now);
        }
        if (chmin(ans, now)) {
          km = k;
        }
      }
      
      auto ansId = new int[N];
      foreach (i; 0 .. N) {
        ansId[as[i][1]] = bs[i + km][1];
      }
      
      writeln(ans);
      foreach (i; 0 .. N) {
        if (i > 0) write(" ");
        write(ansId[i] + 1);
      }
      writeln();
      
      debug {
        auto perm = iota(N).array;
        long brt = M * N;
        do {
          long cost;
          foreach (i; 0 .. N) {
            long d = abs(A[i] - B[perm[i]]);
            if (d > M - d) {
              d = M - d;
            }
            cost += d;
          }
          chmin(brt, cost);
        } while (perm.nextPermutation);
        // writeln("brt = ", brt);
        assert(brt == ans);
      }
    }
  } catch (EOFException e) {
  }
}