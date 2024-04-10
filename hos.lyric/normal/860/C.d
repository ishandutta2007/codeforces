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
      auto A = new string[N];
      auto B = new int[N];
      foreach (i; 0 .. N) {
        A[i] = readToken();
        B[i] = readInt();
      }
      
      bool[string] app;
      foreach (i; 0 .. N) {
        app[A[i]] = true;
      }
      string dummy;
      for (int a = 10^^5 + 1; ; ++a) {
        if (a.to!string !in app) {
          dummy = a.to!string;
          break;
        }
      }
      
      const E = B.sum;
      auto ss = new string[N];
      int[string] tr;
      foreach (u; 0 .. N) {
        ss[u] = (u + 1).to!string;
        tr[ss[u]] = u;
      }
      
      // 0: vacant, 1: done, 2: need change
      auto status = new int[N];
      auto iss = new int[][2];
      foreach (i; 0 .. N) {
        if (A[i] in tr) {
          const u = tr[A[i]];
          status[u] = ((B[i] == 1) == (u < E)) ? 1 : 2;
        } else {
          iss[B[i]] ~= i;
        }
      }
      debug {
        writeln("status = ", status);
        writeln("iss = ", iss);
      }
      
      auto vacant = new DList!int[2];
      auto change = new DList!int[2];
      foreach (u; 0 .. N) {
        const b = (u < E) ? 1 : 0;
        if (status[u] == 0) vacant[b] ~= u;
        if (status[u] == 2) change[b] ~= u;
      }
      
      string[][] ans;
      int b0 = -1;
      
      if (vacant[0].empty && vacant[1].empty) {
        foreach (b; 0 .. 2) {
          if (!change[b].empty) {
            const u = change[b].back;
            change[b].removeBack;
            vacant[b] ~= u;
            ans ~= [ss[u], dummy];
            b0 = b;
            break;
          }
        }
      }
      
      for (; ; ) {
        bool upd;
        foreach (b; 0 .. 2) {
          if (!change[b].empty) {
            const u = change[b].back;
            if (!vacant[b ^ 1].empty) {
              const v = vacant[b ^ 1].back;
              change[b].removeBack;
              vacant[b ^ 1].removeBack;
              vacant[b] ~= u;
              ans ~= [ss[u], ss[v]];
              upd = true;
              break;
            }
          }
        }
        if (!upd) {
          break;
        }
      }
      
      if (b0 != -1) {
        assert(!vacant[b0 ^ 1].empty);
        const v = vacant[b0 ^ 1].back;
        vacant[b0 ^ 1].removeBack;
        ans ~= [dummy, ss[v]];
      }
      
      foreach (b; 0 .. 2) {
        foreach (i; iss[b]) {
          assert(!vacant[b].empty);
          const v = vacant[b].back;
          vacant[b].removeBack;
          ans ~= [A[i], ss[v]];
        }
      }
      
      writeln(ans.length);
      foreach (row; ans) {
        writeln("move ", row[0], " ", row[1]);
      }
    }
  } catch (EOFException e) {
  }
}