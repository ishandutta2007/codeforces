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


int N, K, P;
int[] A;

int[][] solve() {
	int[][] as = new int[][2];
	foreach (a; A) {
		as[a % 2] ~= a;
	}
	if (as[1].length < K - P) {
		return null;
	}
	int[][][] rets = new int[][][2];
	
	int[] rs;
	foreach (idx, a; as[1]) {
		if (idx < K - P) {
			rets[1] ~= [ a ];
		} else {
			rs ~= a;
		}
	}
	if (rs.length % 2 != 0) {
		return null;
	}
	
	int[][] groups;
	foreach (a; as[0]) {
		groups ~= [ a ];
	}
	for (int j = 0; j < rs.length; j += 2) {
		groups ~= rs[j .. j + 2];
	}
	if (groups.length < P) {
		return null;
	}
	foreach (idx, group; groups) {
		if (idx < P) {
			rets[0] ~= group;
		} else {
			rets[(0 < P) ? 0 : 1][0] ~= group;
		}
	}
	return rets[0] ~ rets[1];
}

void main(string[] args) {
	try {
	for (; ; ) {
		N = readInt;
		K = readInt;
		P = readInt;
		A = new int[N];
		foreach (i; 0 .. N) {
			A[i] = readInt;
		}
		
		if (auto res = solve) {
			writeln("YES");
			foreach (line; res) {
				writeln(line.length, " ", line.to!string.removechars("[],"));
			}
		} else {
			writeln("NO");
		}
	}
	} catch (EOFException) {}
}