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


int N;
int[] A;

void main(string[] args) {
	try {
	for (; ; ) {
		N = readInt;
		A = new int[N];
		foreach (i; 0 .. N) {
			A[i] = readInt;
		}
		
		int[] ps = new int[N];
		foreach (i; 0 .. N) {
			ps[i] = i;
		}
		ps.sort!((a, b) => (A[a] < A[b]));
debug{
writeln(ps);
}
		Pair!(int, int)[] poss;
		for (int i = 0, j; i < N; i = j) {
			for (; j < N && A[ps[i]] == A[ps[j]]; ++j) {}
			if (j - i >= 2) {
				poss ~= pair(i, j);
			}
		}
		int prod = 1;
		foreach (pos; poss) {
			prod *= (pos.y - pos.x);
			chmin(prod, 4);
		}
		if (prod < 3) {
			writeln("NO");
			continue;
		}
		writeln("YES");
		if (poss.count!(a => (a.y - a.x >= 3)) > 0) {
			foreach (i; 0 .. N) { if (i > 0) write(" "); write(ps[i] + 1); } writeln;
			foreach (pos; poss) if (pos.y - pos.x >= 3) {
				swap(ps[pos.x + 1], ps[pos.x + 2]);
				break;
			}
			foreach (i; 0 .. N) { if (i > 0) write(" "); write(ps[i] + 1); } writeln;
			foreach (pos; poss) if (pos.y - pos.x >= 3) {
				swap(ps[pos.x + 0], ps[pos.x + 1]);
				break;
			}
			foreach (i; 0 .. N) { if (i > 0) write(" "); write(ps[i] + 1); } writeln;
		} else {
			assert(poss.length >= 2);
			foreach (i; 0 .. N) { if (i > 0) write(" "); write(ps[i] + 1); } writeln;
			swap(ps[poss[0].x], ps[poss[0].x + 1]);
			foreach (i; 0 .. N) { if (i > 0) write(" "); write(ps[i] + 1); } writeln;
			swap(ps[poss[1].x], ps[poss[1].x + 1]);
			foreach (i; 0 .. N) { if (i > 0) write(" "); write(ps[i] + 1); } writeln;
		}
	}
	} catch (EOFException) {}
}