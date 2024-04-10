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
  const N = readInt();
  if (N % 2 == 0) {
    writeln("First");
    stdout.flush;
    foreach (i; 0 .. 2 * N) {
      if (i > 0) write(" ");
      write(i % N + 1);
    }
    writeln;
    stdout.flush;
  } else {
    writeln("Second");
    stdout.flush;
    
    auto P = new int[2 * N];
    foreach (i; 0 .. 2 * N) {
      P[i] = readInt() - 1;
    }
    auto iss = new int[][N];
    foreach (i; 0 .. 2 * N) {
      iss[P[i]] ~= i;
    }
    
    auto vis = new bool[N];
    foreach (u; 0 .. N) {
      if (!vis[u]) {
        for (int v = u, x = u; !vis[v]; ) {
          vis[v] = true;
          const j = P[x];
          if (iss[j][0] != x) {
            swap(iss[j][0], iss[j][1]);
          }
          const vv = iss[j][1] % N;
          const xx = (iss[j][1] + N) % (2 * N);
          v = vv;
          x = xx;
        }
      }
    }
    debug {
      writeln("iss = ", iss);
    }
    
    long sum;
    foreach (j; 0 .. N) {
      sum += iss[j][0] + 1;
    }
    const s = (sum % (2 * N) == 0) ? 0 : 1;
    
    foreach (j; 0 .. N) {
      if (j > 0) write(" ");
      write(iss[j][s] + 1);
    }
    writeln;
    stdout.flush;
  }
}