import core.thread;
import std.conv, std.stdio, std.string;
import std.algorithm, std.array, std.bigint, std.math, std.range;

//	Input
class EOFException : Throwable { this() { super("EOF"); } }
string[] tokens;
string readToken() { for (; tokens.empty; ) { tokens = readln.split; if (stdin.eof) throw new EOFException; } auto token = tokens[0]; tokens.popFront; return token; }
int readInt() { return to!int(readToken); }
long readLong() { return to!long(readToken); }
real readReal() { return to!real(readToken); }

//	chmin/chmax
void chmin(T)(ref T t, const T f) { if (t > f) t = f; }
void chmax(T)(ref T t, const T f) { if (t < f) t = f; }

//	Pair
struct Pair(S, T) {
	S x; T y;
	int opCmp(ref const Pair p) const { return (x < p.x) ? -1 : (x > p.x) ? +1 : (y < p.y) ? -1 : (y > p.y) ? +1 : 0; }
	string toString() const { return "(" ~ to!string(x) ~ ", " ~ to!string(y) ~ ")"; }
}
auto pair(S, T)(S x, T y) { return Pair!(S, T)(x, y); }

//	Array
int binarySearch(T)(T[] as, bool delegate(T) test) { int low = -1, upp = as.length; for (; low + 1 < upp; ) { int mid = (low + upp) >> 1; (test(as[mid]) ? low : upp) = mid; } return upp; }
int lowerBound(T)(T[] as, T val) { return as.binarySearch((T a) { return (a <  val); }); }
int upperBound(T)(T[] as, T val) { return as.binarySearch((T a) { return (a <= val); }); }
T[] unique(T)(T[] as) { T[] bs; foreach (a; as) if (bs.empty || bs[$ - 1] != a) bs ~= a; return bs; }



bool check(long n, long a, long b, long c) {
	long x = min(a, b, c);
	a -= x;
	b -= x;
	c -= x;
	long rem = n - a - b - c;
	return (rem >= 0 && rem % 3 == 0);
}

bool solve(long N, long K, long D1, long D2) {
	foreach (s; [ +1, -1 ]) foreach (t; [ +1, -1 ]) {
		if (check(K, D1 * s, 0, D2 * t) && check(N - K, D1 * -s, 0, D2 * -t)) {
			return true;
		}
	}
	return false;
}

void main(string[] args) {
	// try {
	for (int TC = readInt; TC--; ) {
		long N = readLong;
		long K = readLong;
		long D1 = readLong;
		long D2 = readLong;
		bool res = solve(N, K, D1, D2);
		writeln(res ? "yes" : "no");
	}
	// } catch (EOFException) {}
}