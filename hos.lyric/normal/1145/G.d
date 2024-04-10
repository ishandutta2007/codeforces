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


enum L = 10;

string Query(string me) {
  string result;
  foreach (i; 0 .. L) {
    writeln(me[i]);
    stdout.flush;
    result ~= readToken()[0];
  }
  return result;
}

string calc(string me, string ai) {
  string result;
  foreach (i; 0 .. L) {
    bool win;
    win = win || (me[i] == 'R' && ai[i] == 'S');
    win = win || (me[i] == 'S' && ai[i] == 'P');
    win = win || (me[i] == 'P' && ai[i] == 'R');
    result ~= win ? 'p' : 'a';
  }
  return result;
}

string beat(string ai) {
  string me;
  foreach (i; 0 .. L) {
    switch (ai[i]) {
      case 'R': me ~= 'P'; break;
      case 'S': me ~= 'R'; break;
      case 'P': me ~= 'S'; break;
      default: assert(false);
    }
  }
  return me;
}

void main() {
  try {
    enum me0 = "RRRRSSSPPP";
    string[] ais;
    ais ~= 'R'.repeat(L + L).array;
    ais ~= 'S'.repeat(L + L).array;
    ais ~= 'P'.repeat(L + L).array;
    ais ~= iota(L + L).map!(i => "RSP"[i % 3]).array;
    ais ~= iota(L + L).map!(i => "RPS"[i % 3]).array;
    ais ~= iota(L + L).map!(i => "SRP"[i % 3]).array;
    ais ~= iota(L + L).map!(i => "SPR"[i % 3]).array;
    ais ~= iota(L + L).map!(i => "PRS"[i % 3]).array;
    ais ~= iota(L + L).map!(i => "PSR"[i % 3]).array;
    debug {
      writeln("ais = ", ais);
    }
    
    const result0 = Query(me0);
    foreach (ai; ais) {
      debug {
        writeln(me0, " ", ai, " ", calc(me0, ai[0 .. L]));
      }
      if (result0[1 .. L] == calc(me0, ai[0 .. L])[1 .. L]) {
        const me1 = beat(ai[L .. L + L]);
        Query(me1);
        return;
      }
    }
    
    if (result0[1 .. L] == calc(me0, "RRRRRSSSPP")[1 .. L]) {
      Query("SRPSRPSRPS");
      return;
    }
    if (result0[1 .. L] == calc(me0, "RPPPPRRRSS")[1 .. L]) {
      Query("RSPRSPRSPR");
      return;
    }
    if (result0[1 .. L] == calc(me0, "RSSSSPPPRR")[1 .. L]) {
      Query("PPPPPPPPPP");
      return;
    }
    
    assert(false);
  } catch (EOFException e) {
  }
}