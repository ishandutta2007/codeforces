import std.conv, std.functional, std.stdio, std.string;
import std.algorithm, std.array, std.bigint, std.complex, std.container, std.math, std.numeric, std.range, std.regex, std.typecons;
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


long M;
int A, B;

void main() {
  try {
    for (; ; ) {
      M = readLong();
      A = readInt();
      B = readInt();
      
      const V = 2 * (A + B) + 10;
      alias Node = Tuple!(int, "c", int, "u");
      BinaryHeap!(Array!Node, "a > b") que;
      auto dist = new int[V];
      dist[] = V;
      dist[0] = 0;
      que.insert(Node(0, 0));
      for (; !que.empty; ) {
        const c = que.front.c;
        const u = que.front.u;
        que.removeFront;
        if (dist[u] == c) {
          foreach (v; [u + A, u - B]) {
            if (0 <= v && v < V) {
              const cc = max(c, v);
              if (dist[v] > cc) {
                dist[v] = cc;
                que.insert(Node(cc, v));
              }
            }
          }
        }
      }
      auto f = new int[V];
      foreach (u; 0 .. V) {
        if (dist[u] < V) {
          ++f[dist[u]];
        }
      }
      foreach (u; 1 .. V) {
        f[u] += f[u - 1];
      }
      debug {
        if (V <= 100) {
          writeln("dist = ", dist);
          writeln("f = ", f);
        }
      }
      
      const long g = gcd(A, B);
      const long q = (M + 1) / g, r = (M + 1) % g;
      long ans;
      ans += g * q * (q + 1) / 2;
      ans += (q + 1) * r;
      foreach (u; 0 .. V) {
        if (u <= M) {
          ans -= (u / g + 1);
          ans += f[u];
        }
      }
      writeln(ans);
    }
  } catch (EOFException e) {
  }
}