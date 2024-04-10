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


enum INF = 10L^^18;

void main() {
  try {
    for (; ; ) {
      const N = readInt();
      auto A = new long[][](N, N);
      foreach (u; 0 .. N) foreach (v; u + 1 .. N) {
        A[u][v] = A[v][u] = readLong();
      }
      
      long mn = INF;
      int sm = -1, tm = -1;
      foreach (u; 0 .. N) foreach (v; u + 1 .. N) {
        if (chmin(mn, A[u][v])) {
          sm = u;
          tm = v;
        }
      }
      
      auto dist = new long[][](N, 2);
      auto vis = new bool[][](N, 2);
      foreach (u; 0 .. N) foreach (k; 0 .. 2) {
        dist[u][k] = INF;
      }
      dist[sm][0] = dist[tm][0] = 0;
      for (; ; ) {
        int um = -1, km = 0;
        foreach (u; 0 .. N) foreach (k; 0 .. 2) {
          if (!vis[u][k]) {
            if (um == -1 || dist[um][km] > dist[u][k]) {
              um = u;
              km = k;
            }
          }
        }
        if (um == -1) {
          break;
        }
        vis[um][km] = true;
        foreach (v; 0 .. N) {
          if (um != v) {
            chmin(dist[v][0], dist[um][km] + (A[um][v] - mn) * (km + 1));
            chmin(dist[v][1], dist[um][km]);
          }
        }
      }
      debug {
        writeln("dist = ", dist);
      }
      
      foreach (u; 0 .. N) {
        writeln(dist[u][0] + (N - 1) * mn);
      }
    }
  } catch (EOFException e) {
  }
}