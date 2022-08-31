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
  /*
  debug {
    foreach (n; 1 .. 5 + 1) {
      auto as = iota(n).array;
      do {
        int[][] invs;
        foreach (i; 0 .. n) foreach (j; i + 1 .. n) {
          if (as[i] > as[j]) {
            invs ~= [i, j];
          }
        }
        const invsLen = cast(int)(invs.length);
        writeln(as);
        bool found;
        auto perm = iota(invsLen).array;
        do {
          auto bs = as.dup;
          foreach (k; 0 .. invsLen) {
            swap(bs[invs[perm[k]][0]], bs[invs[perm[k]][1]]);
          }
          if (bs == iota(n).array) {
            found = true;
            foreach (k; 0 .. invsLen) {
              write(" ", invs[perm[k]]);
            }
            writeln;
          }
        } while (perm.nextPermutation);
        if (!found) {
          writeln("no solution");
        }
      } while (as.nextPermutation);
    }
  }
  //*/
  
  try {
    for (; ; ) {
      const N = readInt();
      auto A = new int[N];
      foreach (i; 0 .. N) {
        A[i] = readInt();
      }
      
      Tuple!(int, int)[] ps;
      foreach (i; 0 .. N) {
        ps ~= tuple(A[i], i);
      }
      ps.sort;
      auto as = new int[N];
      foreach (i; 0 .. N) {
        as[ps[i][1]] = i;
      }
      debug {
        writeln("as = ", as);
      }
      
      auto poss = new int[N];
      foreach (i; 0 .. N) {
        poss[as[i]] = i;
      }
      int[][] ans;
      foreach (h; 0 .. N - 1) {
        foreach (a; 0 .. N - 1) {
          const i = poss[a];
          const j = poss[a + 1];
          if (i > j) {
            ans ~= [j, i];
            swap(as[i], as[j]);
            swap(poss[a], poss[a + 1]);
          }
        }
      }
      
      writeln(ans.length);
      foreach (p; ans) {
        writeln(p[0] + 1, " ", p[1] + 1);
      }
    }
  } catch (EOFException e) {
  }
}