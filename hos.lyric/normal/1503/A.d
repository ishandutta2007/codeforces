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


bool isValid(char[] cs) {
  int now;
  foreach (c; cs) {
    if (c == '(') {
      ++now;
    } else if (c == ')') {
      if (--now < 0) {
        return false;
      }
    } else {
      assert(false);
    }
  }
  return (now == 0);
}

void main() {
  try {
    for (; ; ) {
      const numCases = readInt();
      foreach (caseId; 0 .. numCases) {
        const N = readInt();
        const S = readToken();
        
        auto as = new char[N];
        auto bs = new char[N];
        
        const cnt1 = cast(int)(S.count('1'));
        int pos0, pos1;
        foreach (i; 0 .. N) {
          if (S[i] == '0') {
            if (pos0 % 2 == 0) {
              as[i] = '(';
              bs[i] = ')';
            } else {
              as[i] = ')';
              bs[i] = '(';
            }
            ++pos0;
          } else {
            if (pos1 < cnt1 / 2) {
              as[i] = bs[i] = '(';
            } else {
              as[i] = bs[i] = ')';
            }
            ++pos1;
          }
        }
        debug {
          writeln("as = ", as);
          writeln("bs = ", bs);
        }
        
        bool ok = true;
        ok = ok && isValid(as);
        ok = ok && isValid(bs);
        if (ok) {
          writeln("YES");
          writeln(as);
          writeln(bs);
        } else {
          writeln("NO");
        }
      }
    }
  } catch (EOFException e) {
  }
}