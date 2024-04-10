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
    for (int n = 3; n <= 7; n += 2) {
      writeln("n = ", n);
      int[string] vis;
      auto as = iota(n).array;
      void dfs(int last) {
        const key = as.to!string;
        if (key !in vis) {
          vis[key] = last;
          for (int m = 3; m <= n; m += 2) {
            as[0 .. m].reverse;
            dfs(m);
            as[0 .. m].reverse;
          }
        }
      }
      dfs(-1);
      foreach (key, val; vis) {
        writeln(key, " ", val);
      }
      writeln("|vis| = ", vis.length);
    }
  }
  
  try {
    for (; ; ) {
      const numCases = readInt();
      foreach (caseId; 0 .. numCases) {
        const N = readInt();
        auto A = new int[N];
        foreach (i; 0 .. N) {
          A[i] = readInt() - 1;
        }
        
        bool ok = true;
        foreach (i; 0 .. N) {
          ok = ok && ((A[i] - i) % 2 == 0);
        }
        if (ok) {
          auto as = A.dup;
          int[] ans;
          for (int n = N; n > 1; n -= 2) {
            int p = -1, q = -1;
            foreach (i; 0 .. n) {
              if (as[i] == n - 2) p = i;
              if (as[i] == n - 1) q = i;
            }
            
            void oper(int m) {
              assert(m % 2 != 0);
              ans ~= m;
              as[0 .. m].reverse;
              if (p < m) p = m - 1 - p;
              if (q < m) q = m - 1 - q;
            }
            oper(q + 1);
            oper(p);
            oper(n);
            oper(q + 1);
            oper(n);
            assert(p == n - 2);
            assert(q == n - 1);
          }
          
          const ansLen = cast(int)(ans.length);
          writeln(ansLen);
          foreach (i; 0 .. ansLen) {
            if (i > 0) write(" ");
            write(ans[i]);
          }
          writeln;
          assert(2 * ansLen <= 5 * N);
        } else {
          writeln(-1);
        }
      }
    }
  } catch (EOFException e) {
  }
}