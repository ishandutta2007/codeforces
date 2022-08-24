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
      auto C = new int[N];
      foreach (i; 0 .. N) {
        C[i] = readInt() - 1;
      }
      
      auto cs = C.dup;
      int[][] dss;
      int cnt;
      foreach (i; 0 .. N) {
        if (cs[i] != i) {
          foreach (j; 0 .. N) {
            if (cs[j] == i) {
              int[] ds;
              foreach (k; 0 .. i) {
                ds ~= 1;
              }
              ds ~= (j + 1) - i;
              foreach (k; j + 1 .. N) {
                ds ~= 1;
              }
              if (cnt % 2 != 0) {
                ds.reverse;
              }
              ++cnt;
              if (ds.length > 1) {
                dss ~= ds;
              }
              cs[i .. j + 1].reverse;
              break;
            }
          }
        }
      }
      if (cnt % 2 != 0) {
        int[] ds;
        foreach (i; 0 .. N) {
          ds ~= 1;
        }
        ds.reverse;
        if (ds.length > 1) {
          dss ~= ds;
        }
      }
      
      writeln(dss.length);
      foreach (ds; dss) {
        write(ds.length);
        foreach (d; ds) {
          write(" ", d);
        }
        writeln;
      }
      
      debug {
        cs = C.dup;
        foreach (ds; dss) {
          int[][] blocks;
          int i;
          foreach (d; ds) {
            blocks ~= cs[i .. i + d];
            i += d;
          }
          assert(i == N);
          blocks.reverse;
          cs = [];
          foreach (block; blocks) {
            cs ~= block;
          }
        }
        assert(cs == iota(N).array, format("C = %s, cs = %s", C, cs));
      }
    }
  } catch (EOFException e) {
  }
}