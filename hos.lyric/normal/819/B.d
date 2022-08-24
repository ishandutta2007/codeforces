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




void main() {
  try {
    for (; ; ) {
      const N = readInt();
      auto P = new int[N];
      foreach (i; 0 .. N) {
        P[i] = readInt() - 1;
      }
      
      long ans = long.max;
      int km = -1;
      
      long now;
      long posi, nega;
      int offset;
      auto cnt = new int[4 * N + 1];
      void add(int val) {
        now += abs(offset + val);
        (offset + val >= 0) ? ++posi : ++nega;
        ++cnt[2 * N + val];
      }
      void rem(int val) {
        now -= abs(offset + val);
        (offset + val >= 0) ? --posi : --nega;
        --cnt[2 * N + val];
      }
      
      foreach (i; 0 .. N) {
        add(P[i] - i);
      }
      foreach (k; 0 .. N) {
        debug {
          writeln(k, ": ", now);
        }
        if (chmin(ans, now)) {
          km = k;
        }
        rem(P[N - 1 - k] - (N - 1 - k));
        posi -= cnt[2 * N - offset];
        nega += cnt[2 * N - offset];
        now -= posi;
        now += nega;
        --offset;
        add(P[N - 1 - k] - (N - 1 - k) + N);
      }
      writeln(ans, " ", km);
      
      debug {
        long brt = long.max;
        int brtkm = -1;
        foreach (k; 0 .. N) {
          long cost;
          foreach (i; 0 .. N) {
            cost += abs(P[i] - (k + i) % N);
          }
          debug {
            writeln("brt ", k, ": ", cost);
          }
          if (chmin(brt, cost)) {
            brtkm = k;
          }
        }
        writeln("brt: ", brt, " ", brtkm);
      }
    }
  } catch (EOFException e) {
  }
}