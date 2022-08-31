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


int N, M;
int[] U, V;

void main() {
  try {
    for (; ; ) {
      const numCases = readInt();
      foreach (caseId; 0 .. numCases) {
        // !!!3N vertices!!!
        N = readInt();
        M = readInt();
        U = new int[M];
        V = new int[M];
        foreach (i; 0 .. M) {
          U[i] = readInt() - 1;
          V[i] = readInt() - 1;
        }
        debug {
          writeln("N = ", N, ", M = ", M);
          writeln("U = ", U);
          writeln("V = ", V);
        }
        
        int cnt;
        auto matching = new bool[M];
        auto used = new bool[3 * N];
        foreach (i; 0 .. M) {
          if (!used[U[i]] && !used[V[i]]) {
            ++cnt;
            matching[i] = true;
            used[U[i]] = true;
            used[V[i]] = true;
          }
        }
        
        int[] ans;
        if (cnt >= N) {
          writeln("Matching");
          foreach (i; 0 .. M) {
            if (matching[i]) {
              ans ~= i + 1;
            }
          }
        } else {
          writeln("IndSet");
          foreach (u; 0 .. 3 * N) {
            if (!used[u]) {
              ans ~= u + 1;
            }
          }
        }
        ans = ans[0 .. N];
        foreach (idx, a; ans) {
          if (idx > 0) {
            write(" ");
          }
          write(a);
        }
        writeln();
      }
    }
  } catch (EOFException e) {
  }
}