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
      const K = readInt();
      auto S = new int[][](N, K);
      foreach (i; 0 .. N) {
        foreach (k; 0 .. K) {
          S[i][k] = readInt();
        }
      }
      
      class Component {
        int size;
        int[] mins, maxs;
        this(int[] s) {
          size = 1;
          mins = s.dup;
          maxs = s.dup;
        }
        void add(Component o) {
          size += o.size;
          foreach (k; 0 .. K) {
            chmin(mins[k], o.mins[k]);
            chmax(maxs[k], o.maxs[k]);
          }
        }
      }
      
      auto set = new RedBlackTree!(Component, "a.mins[0] < b.mins[0]");
      foreach (i; 0 .. N) {
        auto c = new Component(S[i]);
        for (; ; ) {
          {
            auto ran = set.lowerBound(c);
            if (!ran.empty) {
              auto cc = ran.back;
              bool ok;
              foreach (k; 0 .. K) {
                if (cc.maxs[k] >= c.mins[k]) {
                  ok = true;
                  break;
                }
              }
              if (ok) {
                c.add(cc);
                set.removeKey(cc);
                goto found;
              }
            }
          }
          {
            auto ran = set.upperBound(c);
            if (!ran.empty) {
              auto cc = ran.front;
              bool ok;
              foreach (k; 0 .. K) {
                if (c.maxs[k] >= cc.mins[k]) {
                  ok = true;
                  break;
                }
              }
              if (ok) {
                c.add(cc);
                set.removeKey(cc);
                goto found;
              }
            }
          }
          break;
         found:
        }
        set.insert(c);
        debug {
          foreach (cc; set) {
            writef("(%s, %s, %s) ", cc.size, cc.mins, cc.maxs);
          }
          writeln();
        }
        writeln(set.back.size);
      }
    }
  } catch (EOFException e) {
  }
}