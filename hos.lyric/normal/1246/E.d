import std.conv, std.functional, std.range, std.stdio, std.string;
import std.algorithm, std.array, std.bigint, std.bitmanip, std.complex, std.container, std.math, std.numeric, std.regex, std.typecons;
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
  try {
    for (; ; ) {
      const N = readInt();
      const K = readInt();
      auto A = new int[N];
      foreach (i; 0 .. N) {
        A[i] = readInt();
      }
      
      auto ASum = new int[1 << N];
      foreach (i; 0 .. N) {
        foreach (h; 0 .. 1 << i) {
          ASum[h | 1 << i] = ASum[h] + A[i];
        }
      }
      
      auto dp = new BitArray[1 << N];
      foreach (h; 0 .. 1 << N) {
        dp[h] = BitArray(new bool[ASum[$ - 1] + 1]);
      }
      dp[0][0] = true;
      foreach (h; 0 .. 1 << N) {
        foreach_reverse (x; 1 .. ASum[h] / K + 1) {
          if (dp[h][x * K]) {
            dp[h][x] = true;
          }
        }
        foreach (i; 0 .. N) {
          if (!(h & 1 << i)) {
            auto f = dp[h].dup;
            f <<= A[i];
            dp[h | 1 << i] |= f;
          }
        }
      }
      debug {
        /*
        foreach (h; 0 .. 1 << N) {
          write(h, ":");
          foreach (x; 0 .. ASum[h] + 1) {
            if (dp[h][x]) {
              write(" ", x);
            }
          }
          writeln();
        }
        //*/
      }
      
      if (dp[$ - 1][1]) {
        auto fs = new int[N];
        fs[] = int.min;
        for (int h = (1 << N) - 1, x = 1; h; ) {
          foreach (i; 0 .. N) {
            if ((h & 1 << i) && x >= A[i] && dp[h ^ 1 << i][x - A[i]]) {
              fs[i] = 0;
              h ^= 1 << i;
              x -= A[i];
              goto found;
            }
          }
          x *= K;
          fs[] += 1;
         found:
        }
        debug {
          writeln("fs = ", fs);
        }
        BinaryHeap!(Array!(Tuple!(int, int)), "a > b") q;
        foreach (i; 0 .. N) {
          q.insert(tuple(fs[i], A[i]));
        }
        writeln("YES");
        foreach (j; 0 .. N - 1) {
          const e0 = q.front; q.removeFront;
          const e1 = q.front; q.removeFront;
          assert(e0[0] == e1[0]);
          writeln(e0[1], " ", e1[1]);
          int f = e0[0];
          int a = e0[1] + e1[1];
          for (; a % K == 0; ) {
            ++f;
            a /= K;
          }
          q.insert(tuple(f, a));
        }
      } else {
        writeln("NO");
      }
    }
  } catch (EOFException e) {
  }
}