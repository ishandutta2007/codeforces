import core.thread;
import std.conv, std.stdio, std.string;
import std.algorithm, std.array, std.bigint, std.container, std.math, std.range, std.regex;

//	Input
class EOFException : Throwable { this() { super("EOF"); } }
string[] tokens;
string readToken() { for (; tokens.empty; ) { tokens = readln.split; if (stdin.eof) throw new EOFException; } auto token = tokens[0]; tokens.popFront; return token; }
int readlong() { return to!int(readToken); }
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


//	min x >= 0 s.t. l <= ((a x) mod m) <= r
//	m > 0, a >= 0
/*
	take k s.t. a (k - 1) < l <= a k
	if a (k - 1) < l <= r < a k:
		l <= a x - m y <= r
		==> 0 < a k - r <= m y - a (x - k) <= a k - l < a
		x >= k ==> y >= (a x - r) / m >= (a k - r) / m > 0
		y >= 0 ==> x >= (m y + l) / a >= 0
*/
long modRange(long m, long a, long l, long r) {
	chmax(l, 0L);
	chmin(r, m - 1);
	if (l > r) return -1;
	a %= m;
	if (a == 0) return (l > 0) ? -1 : 0;
	const k = (l + a - 1) / a;
	if (a * k <= r) return k;
	const y = modRange(a, m, a * k - r, a * k - l);
	return (y == -1) ? -1 : ((m * y + r) / a);
}
long N, D, M, L;

void main(string[] args) {
	try {
	for (; ; ) {
		N = readLong;
		D = readLong;
		M = readLong;
		L = readLong;
		
		const rightEnd = (N - 1) * M + L;
		long ans = D * (rightEnd / D + 1);
		
		const res = modRange(M, D, L + 1, M - 1);
		if (res != -1) {
			chmin(ans, D * res);
		}
		
		writeln(ans);
		
	}
	} catch (EOFException) {}
}