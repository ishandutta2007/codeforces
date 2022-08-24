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


enum L = 100;

void main() {
  try {
    for (; ; ) {
      const numCases = readInt();
      foreach (caseId; 0 .. numCases) {
        const N = readInt();
        auto A = new int[N];
        foreach (u; 0 .. N) {
          A[u] = readInt() - 1;
        }
        
        auto indeg = new int[N];
        foreach (u; 0 .. N) {
          ++indeg[A[u]];
        }
        
        auto cyc = new bool[N];
        auto vis = new int[N];
        vis[] = -1;
        foreach (u; 0 .. N) {
          if (!~vis[u]) {
            int v;
            for (v = u; !~vis[v]; v = A[v]) {
              vis[v] = u;
            }
            if (vis[v] == u) {
              for (int w = v; ; ) {
                cyc[w] = true;
                w = A[w];
                if (w == v) {
                  break;
                }
              }
            }
          }
        }
        debug {
          writeln("cyc = ", cyc);
        }
        
        auto to = A.dup;
        foreach (u; 0 .. N) {
          if (cyc[u]) {
            if (indeg[A[u]] > 1) {
              --indeg[A[u]];
              to[u] = -1;
            }
          }
        }
        foreach (u; 0 .. N) {
          if (!cyc[u]) {
            if (indeg[A[u]] > 1) {
              --indeg[A[u]];
              to[u] = -1;
            }
          }
        }
        
        int[] us;
        foreach (u; 0 .. N) {
          if (indeg[u] == 0) {
            for (int v = u; ~v; v = to[v]) {
              us ~= v;
            }
          }
        }
        const usLen = cast(int)(us.length);
        foreach (j; 0 .. usLen) {
          to[us[j]] = us[(j + 1) % usLen];
        }
        
        int ans;
        foreach (u; 0 .. N) {
          if (A[u] == to[u]) {
            ++ans;
          }
        }
        writeln(ans);
        foreach (u; 0 .. N) {
          if (u > 0) write(" ");
          write(to[u] + 1);
        }
        writeln;
      }
    }
  } catch (EOFException e) {
  }
}