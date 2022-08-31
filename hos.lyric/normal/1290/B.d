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
  debug {
    bool check(int[] as) {
      if (as.length == 1) {
        return true;
      }
      if (as[0] != as[$ - 1]) {
        return true;
      }
      if (as.dup.sort.group.array.length >= 3) {
        return true;
      }
      return false;
    }
    
    enum lim = 5;
    foreach (n; 1 .. lim + 1) {
      foreach (p; 0 .. lim^^n) {
        auto as = new int[n];
        foreach (i; 0 .. n) {
          as[i] = p / lim^^i % lim;
        }
        auto bs = as.dup;
        bs.sort;
        bool hasIrred;
        do {
          bool irred = true;
          foreach (i; 1 .. n) {
            irred = irred && (as[0 .. i].dup.sort != bs[0 .. i].dup.sort);
          }
          hasIrred = hasIrred || irred;
        } while (bs.nextPermutation);
        if (!hasIrred) {
          writeln(as);
        }
        assert(hasIrred == check(as));
      }
    }
  }
  
  try {
    for (; ; ) {
      const S = readToken();
      const Q = readInt();
      auto L = new int[Q];
      auto R = new int[Q];
      foreach (q; 0 .. Q) {
        L[q] = readInt() - 1;
        R[q] = readInt();
      }
      
      const N = cast(int)(S.length);
      auto cnt = new int[][](26, N + 1);
      foreach (a; 0 .. 26) {
        foreach (i; 0 .. N) {
          cnt[a][i + 1] = cnt[a][i] + ((S[i] - 'a' == a) ? 1 : 0);
        }
      }
      
      foreach (q; 0 .. Q) {
        bool ans;
        if (R[q] - L[q] == 1) {
          ans = true;
        }
        if (S[L[q]] != S[R[q] - 1]) {
          ans = true;
        }
        int num;
        foreach (a; 0 .. 26) {
          if (cnt[a][R[q]] - cnt[a][L[q]] > 0) {
            ++num;
          }
        }
        if (num >= 3) {
          ans = true;
        }
        writeln(ans ? "Yes" : "No");
      }
    }
  } catch (EOFException e) {
  }
}