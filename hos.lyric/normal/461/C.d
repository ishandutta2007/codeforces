import core.thread;
import std.conv, std.stdio, std.string;
import std.algorithm, std.array, std.bigint, std.container, std.math, std.range, std.regex;

//	Input
class EOFException : Throwable { this() { super("EOF"); } }
string[] tokens;
string readToken() { for (; tokens.empty; ) { tokens = readln.split; if (stdin.eof) throw new EOFException; } auto token = tokens[0]; tokens.popFront; return token; }
int readInt() { return to!int(readToken); }
long readLong() { return to!long(readToken); }
real readReal() { return to!real(readToken); }

//	chmin/chmax
void chmin(T)(ref T t, in T f) { if (t > f) t = f; }
void chmax(T)(ref T t, in T f) { if (t < f) t = f; }

//	Pair
struct Pair(S, T) {
	S x; T y;
	int opCmp(    const Pair p) const { return (x < p.x) ? -1 : (x > p.x) ? +1 : (y < p.y) ? -1 : (y > p.y) ? +1 : 0; }
	int opCmp(ref const Pair p) const { return (x < p.x) ? -1 : (x > p.x) ? +1 : (y < p.y) ? -1 : (y > p.y) ? +1 : 0; }
	string toString() const { return "(" ~ to!string(x) ~ ", " ~ to!string(y) ~ ")"; }
}
auto pair(S, T)(inout(S) x, inout(T) y) { return Pair!(S, T)(x, y); }

//	Array
int binarySearch(T)(in T[] as, in bool delegate(T) test) { int low = -1, upp = as.length; for (; low + 1 < upp; ) { int mid = (low + upp) >> 1; (test(as[mid]) ? low : upp) = mid; } return upp; }
int lowerBound(T)(in T[] as, in T val) { return as.binarySearch((T a) { return (a <  val); }); }
int upperBound(T)(in T[] as, in T val) { return as.binarySearch((T a) { return (a <= val); }); }
T[] unique(T)(in T[] as) { T[] bs; foreach (a; as) if (bs.empty || bs[$ - 1] != a) bs ~= a; return bs; }


void bitAdd(long[] bit, int pos, long val) {
	for (int x = pos; x < bit.length; x |= x + 1) bit[x] += val;
}
long bitSum(long[] bit, int pos) {
	long ret;
	for (int x = pos - 1; x >= 0; x = (x & (x + 1)) - 1) ret += bit[x];
	return ret;
}

int N, Q;

void main(string[] args) {
	try {
	for (; ; ) {
		N = readInt;
		Q = readInt;
		
		long[] a = new long[N];
		a[] = 1;
		long[] bit = new long[N];
		foreach (x; 0 .. N) {
			bit.bitAdd(x, +1);
		}
		bool rev = false;
		int head = 0, tail = N;
		
		void foldL(int p) {
debug{
writeln("  L ",p);
}
			foreach (x; head .. head + p) {
				const y = (head + p) + (head + p - 1) - x;
				a[y] += a[x];
				bit.bitAdd(y, a[x]);
			}
			head += p;
		}
		void foldR(int p) {
debug{
writeln("  R ",p);
}
			foreach (x; tail - p .. tail) {
				const y = (tail - p) + (tail - p - 1) - x;
				a[y] += a[x];
				bit.bitAdd(y, a[x]);
			}
			tail -= p;
		}
		
		foreach (q; 0 .. Q) {
debug{
writeln(a[head..tail]," ",rev);
}
			switch (readInt) {
				case 1: {
					const p = readInt;
					const pp = (tail - head) - p;
					if (rev) {
						if (p <= pp) {
							foldR(p);
						} else {
							foldL(pp);
							rev = !rev;
						}
					} else {
						if (p <= pp) {
							foldL(p);
						} else {
							foldR(pp);
							rev = !rev;
						}
					}
				} break;
				case 2: {
					const l = readInt;
					const r = readInt;
					long res;
					if (rev) {
						res = bit.bitSum(tail - l) - bit.bitSum(tail - r);
					} else {
						res = bit.bitSum(head + r) - bit.bitSum(head + l);
					}
					writeln(res);
				} break;
				default: assert(false);
			}
		}
	}
	} catch (EOFException) {}
}