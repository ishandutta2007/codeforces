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
      auto A = new long[N];
      foreach (i; 0 .. N) {
        A[i] = readLong();
      }
      auto T = new long[N];
      foreach (i; 0 .. N) {
        T[i] = readLong();
      }
      
      alias Entry = Tuple!(long, "a", int, "id");
      auto es = new Entry[N];
      foreach (i; 0 .. N) {
        es[i] = Entry(A[i], i);
      }
      es.sort;
      
      long ans;
      BinaryHeap!(Array!long) que;
      long sum;
      foreach (j; 0 .. N) {
        const i = es[j].id;
        que.insert(T[i]);
        sum += T[i];
        for (long a = A[i]; !que.empty; ++a) {
          if (j + 1 < N && a >= es[j + 1].a) {
            break;
          }
          const tmp = que.front;
          que.removeFront;
          sum -= tmp;
          debug {
            writefln("j = %s; %s -> %s: %s", j, a, a + 1, sum);
          }
          ans += sum;
        }
      }
      writeln(ans);
    }
  } catch (EOFException e) {
  }
}