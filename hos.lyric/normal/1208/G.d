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




void main() {
  debug {
    // lcm(1, ..., 20) = 232792560
    foreach (n; 3 .. 21) {
      auto mns = new Tuple!(int, int)[n - 1];
      mns[] = tuple(n * n, -1);
      foreach (p; 0 .. 1 << (n - 2)) {
        bool[int] app;
        foreach (i; 0 .. n - 2) {
          if ((p >> i) & 1) {
            foreach (j; 0 .. 3 + i) {
              app[232792560 / (3 + i) * j] = true;
            }
          }
        }
        chmin(mns[popcnt(p)], tuple(cast(int)(app.keys.length), p));
      }
      // writeln(n, " ", mns);
      /*
      foreach (k; 0 .. n - 1) {
        writeln(n, " ", k, ": ", mns[k][0], " ",
                iota(n - 2).filter!(i => ((mns[k][1] >> i) & 1)).map!(i => 3 + i));
      }
      */
      foreach (k; 0 .. n - 2) {
        assert(popcnt(mns[k][1] ^ mns[k + 1][1]) == 1);
      }
      writeln(n, ": ", iota(n - 2).map!(k => 3 + bsf(mns[k][1] ^ mns[k + 1][1])));
    }
  }
  
  try {
    for (; ; ) {
      const N = readInt();
      const K = readInt();
      
      auto phi = iota(N + 1).array;
      foreach (i; 1 .. N + 1) {
        for (int j = 2 * i; j < N + 1; j += i) {
          phi[j] -= phi[i];
        }
      }
      
      auto ps = new Tuple!(int, int)[N - 2];
      foreach (i; 0 .. N - 2) {
        ps[i] = tuple(phi[3 + i], i);
      }
      sort(ps);
      
      long ans;
      bool has1, has2;
      foreach (i; 0 .. K) {
        if (!has1 && (3 + ps[i][1]) % 1 == 0) {
          has1 = true;
          ans += phi[1];
        }
        if (!has2 && (3 + ps[i][1]) % 2 == 0) {
          has2 = true;
          ans += phi[2];
        }
        ans += ps[i][0];
      }
      writeln(ans);
    }
  } catch (EOFException e) {
  }
}