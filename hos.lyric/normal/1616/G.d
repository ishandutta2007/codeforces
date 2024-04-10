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
      const numCases = readInt;
      foreach (caseId; 0 .. numCases) {
        int N = readInt;
        int M = readInt;
        auto A = new int[M];
        auto B = new int[M];
        foreach (i; 0 .. M) {
          A[i] = readInt;
          B[i] = readInt;
        }
        M += 2 * N;
        foreach (u; 1 .. N + 1) {
          A ~= 0;
          B ~= u;
          A ~= u;
          B ~= N + 1;
        }
        
        auto graph = new int[][N + 2];
        auto graphRev = new int[][N + 2];
        foreach (i; 0 .. M) {
          graph[A[i]] ~= B[i];
          graphRev[B[i]] ~= A[i];
        }
        
        auto fs = new int[N + 1];
        foreach (i; 0 .. M) {
          if (A[i] + 1 == B[i]) {
            fs[A[i]] = 1;
          }
        }
        auto fsSum = new int[N + 2];
        foreach (u; 0 .. N + 1) {
          fsSum[u + 1] = fsSum[u] + fs[u];
        }
        
        long ans;
        if (fsSum[N + 1] == N + 1) {
          ans = 1L * N * (N - 1) / 2;
        } else {
          int l = N + 1, r = 0;
          foreach (u; 0 .. N + 1) {
            if (!fs[u]) {
              chmin(l, u);
              chmax(r, u + 1);
            }
          }
          debug {
            writeln("fs = ", fs);
            writeln("l = ", l, ", r = ", r);
          }
          bool isGood(int u, int v) {
            return (u <= v && fsSum[v] - fsSum[u] == v - u);
          }
          
          // (u, u + 1) to (l, l + 1),  parity of # of steps
          auto visL = new bool[2][N + 1];
          visL[l][0] = true;
          foreach_reverse (u; 0 .. l + 1) {
            foreach (v; graphRev[u + 1]) {
              // v -> u + 1,  v + 1 -> u
              if (isGood(v + 1, u)) {
                if (visL[u][0]) visL[v][1] = true;
                if (visL[u][1]) visL[v][0] = true;
              }
            }
          }
          long[4] cntL;
          foreach (u; 0 .. l + 1) {
            int p;
            if (visL[u][0]) p |= 1 << 0;
            if (visL[u][1]) p |= 1 << 1;
            ++cntL[p];
          }
          
          // (l, l + 1) to (u, u + 1),  parity of # of steps
          auto visR = new bool[2][N + 1];
          visR[l][0] = true;
          foreach (u; l .. N + 1) {
            foreach (v; graph[u]) {
              // u -> v,  u + 1 -> v - 1
              if (isGood(u + 1, v - 1)) {
                if (visR[u][0]) visR[v - 1][1] = true;
                if (visR[u][1]) visR[v - 1][0] = true;
              }
            }
          }
          long[4] cntR;
          foreach (u; /*!!!*/r - 1 .. N + 1) {
            int p;
            if (visR[u][0]) p |= 1 << 0;
            if (visR[u][1]) p |= 1 << 1;
            ++cntR[p];
          }
          
          debug {
            writeln("visL = ", visL);
            writeln("cntL = ", cntL);
            writeln("visR = ", visR);
            writeln("cntR = ", cntR);
          }
          
          foreach (p; 0 .. 4) foreach (q; 0 .. 4) {
            if (p & q) {
              ans += cntL[p] * cntR[q];
            }
          }
          if (l + 1 == r) {
            ans -= 1;
          }
        }
        writeln(ans);
      }
    }
  } catch (EOFException e) {
  }
}