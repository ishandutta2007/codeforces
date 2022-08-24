import core.thread;
import std.conv, std.stdio, std.string;
import std.algorithm, std.array, std.bigint, std.container, std.math, std.range, std.regex;

//	Input
class EOFException : Throwable { this() { super("EOF"); } }
string[] tokens;
string readToken() { for (; tokens.empty; ) { if (stdin.eof) throw new EOFException; tokens = readln.split; } auto token = tokens[0]; tokens.popFront; return token; }
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


immutable INF = 10L^^18 + 1;

int N, Q;
long[] D, H;
long[] DSum;

int segN;
Pair!(long, int)[] seg0, seg1;

Pair!(long, int) rangeMax(Pair!(long, int)[] seg, int a, int b) {
	Pair!(long, int) ret = pair(-INF, -1);
	for (a += segN, b += segN; a <= b; a >>= 1, b >>= 1) {
		if (  a & 1 ) chmax(ret, seg[a++]);
		if (!(b & 1)) chmax(ret, seg[b--]);
	}
	return ret;
}

long solve(int a, int b) {
debug{
writeln("solve ",a," ",b);
}
	long ret = -INF;
	const res0 = seg0.rangeMax(a, b);
	chmax(ret, res0.x + max(seg1.rangeMax(a, res0.y - 1).x, seg1.rangeMax(res0.y + 1, b).x));
	const res1 = seg1.rangeMax(a, b);
	chmax(ret, res1.x + max(seg0.rangeMax(a, res1.y - 1).x, seg0.rangeMax(res1.y + 1, b).x));
debug{
writeln("  ",res0," ",res1);
}
	return ret;
}

void main(string[] args) {
	try {
	for (; ; ) {
		N = readInt;
		Q = readInt;
		D = new long[N];
		foreach (i; 0 .. N) {
			D[i] = readLong;
		}
		H = new long[N];
		foreach (i; 0 .. N) {
			H[i] = readLong;
		}
		
		DSum = new long[N * 3];
		foreach (i; 0 .. N * 3 - 1) {
			DSum[i + 1] = DSum[i] + D[i % N];
		}
		H.length = N * 3;
		foreach (i; N .. N * 3) {
			H[i] = H[i % N];
		}
		
		for (segN = 1; segN < N * 3; segN <<= 1) {}
		seg0 = new Pair!(long, int)[segN * 2];
		seg1 = new Pair!(long, int)[segN * 2];
		foreach (i; 0 .. N * 3) {
			seg0[segN + i] = pair(2 * H[i] + DSum[i], i);
			seg1[segN + i] = pair(2 * H[i] - DSum[i], i);
		}
		foreach_reverse (a; 1 .. segN) {
			seg0[a] = max(seg0[a << 1], seg0[a << 1 | 1]);
			seg1[a] = max(seg1[a << 1], seg1[a << 1 | 1]);
		}
debug{
writeln("seg0 = ",seg0);
writeln("seg1 = ",seg1);
}
		
		foreach (q; 0 .. Q) {
			const a = readInt - 1;
			const b = readInt - 1;
			const res = (a <= b) ? solve(b + 1, a - 1 + N) : solve(b + 1, a - 1);
			writeln(res);
		}
		
	}
	} catch (EOFException) {}
}