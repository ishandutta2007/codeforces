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


enum INF = 10^^9;

/*
  s[r-1] ... s[l] S = T
  S = s[l]^-1 ... s[r-1]^-1 T
  s[0]^-1 ... s[l-1]^-1 S = s[0]^-1 ... s[r-1]^-1 T
*/
void main() {
  try {
    for (; ; ) {
      const N = readInt();
      const M = readInt();
      const K = readInt();
      const S = readToken();
      const T = readToken();
      auto A = new int[N];
      auto B = new int[N];
      foreach (i; 0 .. N) {
        A[i] = readInt() - 1;
        B[i] = readInt() - 1;
      }
      
      auto dpS = new int[1 << K];
      auto dpT = new int[1 << K];
      dpS[] = +INF;
      dpT[] = -INF;
      auto perm = iota(K).array;
      foreach (i; 0 .. N + 1) {
        debug {
          writeln("perm = ", perm);
        }
        int s, t;
        foreach (k; 0 .. K) {
          s |= (S[k] - '0') << perm[k];
          t |= (T[k] - '0') << perm[k];
        }
        chmin(dpS[s], i);
        chmax(dpT[t], i);
        if (i == N) {
          break;
        }
        swap(perm[A[i]], perm[B[i]]);
      }
      
      foreach_reverse (p; 0 .. 1 << K) {
        foreach (k; 0 .. K) {
          if (!(p & 1 << k)) {
            chmin(dpS[p], dpS[p | 1 << k]);
            chmax(dpT[p], dpT[p | 1 << k]);
          }
        }
      }
      
      int mx = -1, lm, rm;
      foreach (p; 0 .. 1 << K) {
        if (dpT[p] - dpS[p] >= M) {
          debug {
            writeln(p, " ", dpS[p], " ", dpT[p]);
          }
          if (chmax(mx, popcnt(p))) {
            lm = dpS[p];
            rm = dpT[p];
          }
        }
      }
      int ans;
      ans += mx;
      ans += K - (S.count('1') + T.count('1') - mx);
      writeln(ans);
      writeln(lm + 1, " ", rm);
    }
  } catch (EOFException e) {
  }
}