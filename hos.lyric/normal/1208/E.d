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

int N, W;
int[] L;
long[][] A;

void main() {
  try {
    for (; ; ) {
      N = readInt();
      W = readInt();
      L = new int[N];
      A = new long[][N];
      foreach (i; 0 .. N) {
        L[i] = readInt();
        A[i] = new long[L[i]];
        foreach (j; 0 .. L[i]) {
          A[i][j] = readLong();
        }
      }
      
      auto ans = new long[W + 1];
      
      alias Entry = Tuple!(long, "val", int, "key");
      auto que = new Entry[W];
      int qb, qe;
      
      foreach (i; 0 .. N) {
        if (W >= 2 * L[i]) {
          // always empty ok
          auto ls = A[i].dup, rs = A[i].dup;
          foreach (j; 0 .. L[i] - 1) {
            chmax(ls[j + 1], ls[j]);
          }
          foreach_reverse (j; 1 .. L[i]) {
            chmax(rs[j - 1], rs[j]);
          }
          foreach (x; 0 .. L[i]) {
            long mx = ls[x];
            chmax(mx, 0);
            debug {
              writefln("long ans %s %s: %s", i, x, mx);
            }
            ans[x] += mx;
            ans[x + 1] -= mx;
          }
          foreach (x; W - L[i] .. W) {
            long mx = rs[x - (W - L[i])];
            chmax(mx, 0);
            debug {
              writefln("long ans %s %s: %s", i, x, mx);
            }
            ans[x] += mx;
            ans[x + 1] -= mx;
          }
          // [L[i], W - L[i])
          {
            long mx = rs[0];
            chmax(mx, 0);
            debug {
              writefln("long ans %s [%s, %s): %s", i, L[i], W - L[i], mx);
            }
            ans[L[i]] += mx;
            ans[W - L[i]] -= mx;
          }
        } else {
          qb = qe = 0;
          /*
            index j at position x
            <=> j <= x && L[i] - j <= W - x
            <=> x - (W - L[i]) <= j <= x
          */
          foreach (x; 0 .. W) {
            if (x < L[i]) {
              // push x
              for (; qe - qb >= 1 && que[qe - 1].val <= A[i][x]; --qe) {}
              que[qe++] = Entry(A[i][x], x);
            }
            for (; qe - qb >= 1 && !(x - (W - L[i]) <= que[qb].key); ++qb) {}
            assert(qe - qb >= 1);
            long mx = que[qb].val;
            if (x >= L[i] || W - 1 - x >= L[i]) {
              chmax(mx, 0);
            }
            debug {
              writefln("short ans %s %s: %s", i, x, mx);
            }
            ans[x] += mx;
            ans[x + 1] -= mx;
          }
        }
      }
      
      foreach (x; 0 .. W) {
        ans[x + 1] += ans[x];
      }
      assert(ans[W] == 0);
      
      foreach (x; 0 .. W) {
        if (x > 0) {
          write(" ");
        }
        write(ans[x]);
      }
      writeln();
    }
  } catch (EOFException e) {
  }
}