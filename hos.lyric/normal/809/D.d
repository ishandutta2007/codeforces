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

uint xrand() {
  static uint x = 314159265, y = 358979323, z = 846264338, w = 327950288;
  uint t = x ^ x << 11; x = y; y = z; z = w; return w = w ^ w >> 19 ^ t ^ t >> 8;
}

class Tree {
  Tree l, r;
  int size;
  int val, ad;
  this(int val) {
    l = r = null;
    size = 1;
    this.val = val;
    this.ad = 0;
  }
  void propagate() {
    if (l) l.ad += ad;
    if (r) r.ad += ad;
    val += ad;
    ad = 0;
  }
  Tree change(Tree l, Tree r) {
    this.l = l;
    this.r = r;
    size = (l ? l.size : 0) + 1 + (r ? r.size : 0);
    return this;
  }
}
Tree merge(Tree a, Tree b) {
  if (!a) return b;
  if (!b) return a;
  a.propagate();
  b.propagate();
  if (xrand() % (a.size + b.size) < a.size) {
    return a.change(a.l, merge(a.r, b));
  } else {
    return b.change(merge(a, b.l), b.r);
  }
}
Tuple!(Tree, Tree) splitGE(Tree a, int key) {
  if (!a) return tuple!(Tree, Tree)(null, null);
  a.propagate();
  if (key <= a.val) {
    auto l = splitGE(a.l, key);
    return tuple(l[0], a.change(l[1], a.r));
  } else {
    auto r = splitGE(a.r, key);
    return tuple(a.change(a.l, r[0]), r[1]);
  }
}
Tuple!(Tree, Tree) splitHead(Tree a) {
  assert(a);
  a.propagate();
  if (a.l) {
    auto l = splitHead(a.l);
    return tuple(l[0], a.change(l[1], a.r));
  } else {
    return tuple(a, a.r);
  }
}
string toStr(Tree a) {
  if (!a) return "";
  return format("<%s (%s+%s) %s>", toStr(a.l), a.val, a.ad, toStr(a.r));
}
int[] toSeq(Tree a, int ad = 0) {
  if (!a) return [];
  ad += a.ad;
  return toSeq(a.l, ad) ~ (a.val + ad) ~ toSeq(a.r, ad);
}

void main() {
  try {
    for (; ; ) {
      const N = readInt();
      auto L = new int[N];
      auto R = new int[N];
      foreach (i; 0 .. N) {
        L[i] = readInt();
        R[i] = readInt();
      }
      
      debug {
        // O~(\sum_i (R[i] - L[i] + 1))
        int[] lis;
        foreach (i; 0 .. N) {
          foreach_reverse (x; L[i] .. R[i] + 1) {
            const pos = lis.lowerBound(x);
            if (pos == lis.length) {
              lis ~= x;
            } else {
              lis[pos] = x;
            }
          }
          writeln(L[i], " ", R[i], " ", lis);
        }
        writeln("brute: ", lis.length);
      }
      
      Tree t = null;
      foreach (i; 0 .. N) {
        auto sp0 = t.splitGE(L[i]);
        auto sp1 = sp0[1].splitGE(R[i]);
        if (sp1[1]) {
          sp1[1] = sp1[1].splitHead[1];
        }
        if (sp1[0]) {
          sp1[0].ad += 1;
        }
        debug {
          writeln("  ", sp0[0].toSeq, " ", sp1[0].toSeq, " ", sp1[1].toSeq);
        }
        t = sp0[0].merge(new Tree(L[i])).merge(sp1[0]).merge(sp1[1]);
        debug {
          writeln(L[i], " ", R[i], " ", t.toSeq, " ", t.toStr);
        }
      }
      writeln(t.size);
    }
  } catch (EOFException e) {
  }
}