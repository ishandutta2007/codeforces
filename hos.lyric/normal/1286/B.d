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
      auto C = new int[N];
      foreach (u; 0 .. N) {
        P[u] = readInt() - 1;
        C[u] = readInt();
      }
      
      auto desc = new bool[][](N, N);
      foreach (u; 0 .. N) {
        for (int v = u; v != -1; v = P[v]) {
          desc[v][u] = true;
        }
      }
      auto sz = new int[N];
      foreach (u; 0 .. N) {
        sz[u] = desc[u].count(true);
      }
      auto us = iota(N).array;
      us.sort!((u, v) => (sz[u] < sz[v]));
      
      bool ok = true;
      foreach (u; 0 .. N) {
        ok = ok && (C[u] < sz[u]);
      }
      if (ok) {
        int num;
        auto ans = new int[N];
        foreach (u; us) {
          int[] xs;
          foreach (v; 0 .. N) {
            if (u != v && desc[u][v]) {
              xs ~= ans[v];
            }
          }
          xs.sort;
          xs ~= ++num;
          foreach (v; 0 .. N) {
            if (u != v && desc[u][v]) {
              int pos = xs.lowerBound(ans[v]);
              if (pos >= C[u]) {
                ++pos;
              }
              ans[v] = xs[pos];
            }
          }
          ans[u] = xs[C[u]];
        }
        writeln("YES");
        foreach (u; 0 .. N) {
          if (u > 0) write(" ");
          write(ans[u]);
        }
        writeln();
        
        debug {
          foreach (u; 0 .. N) {
            int cnt;
            foreach (v; 0 .. N) {
              if (u != v && desc[u][v]) {
                if (ans[u] > ans[v]) {
                  ++cnt;
                }
              }
            }
            assert(C[u] == cnt);
          }
        }
      } else {
        writeln("NO");
      }
    }
  } catch (EOFException e) {
  }
}