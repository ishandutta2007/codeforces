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


enum A = 26;

void main() {
  try {
    for (; ; ) {
      const M = readInt();
      const S = readToken();
      const L = cast(int)(S.length);
      
      auto freq = new int[A];
      foreach (i; 0 .. L) {
        ++freq[S[i] - 'a'];
      }
      
      string ans;
      foreach (a; 0 .. A) {
        debug {
          writeln("a = ", a);
        }
        bool ok = true;
        int cnt;
        int last = -1, save = -1;
        foreach (i; 0 .. L) {
          if (S[i] - 'a' < a) {
            last = i;
          } else if (S[i] - 'a' == a) {
            save = i;
          }
          if (i - last >= M) {
            if (last >= save) {
              debug {
                writeln("  ng; i = ", i);
              }
              ok = false;
              break;
            }
            ++cnt;
            last = save;
          }
        }
        if (ok) {
          debug {
            writeln("  ok; cnt = ", cnt);
          }
          foreach (b; 0 .. a) {
            foreach (_; 0 .. freq[b]) {
              ans ~= cast(char)('a' + b);
            }
          }
          foreach (_; 0 .. cnt) {
            ans ~= cast(char)('a' + a);
          }
          break;
        }
      }
      writeln(ans);
    }
  } catch (EOFException e) {
  }
}