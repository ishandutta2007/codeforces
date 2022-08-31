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


/*
	A[0] = [ 0 ]
	A[1] = [ 0 1 ]
	       [ 0 1 ]
	A[2] = [ 0 1 2 1 ]
	       [ 1 0 1 2 ]
	       [ 2 1 0 1 ]
	       [ 1 2 1 0 ]
	A[m] = [ A[m-1]              A[m-1] + 2^(m-1) I ]
	       [ A[m-1] + 2^(m-1) I  A[m-1]             ]
	
	[ A + p I  A + q I ]^e [ X ]
	[ A + q I  A + p I ]   [ Y ]
	
	= (1/2) [  1   1 ] [ 2 A + (p + q) I            ]^e [  1   1 ] [ X ]
	        [  1  -1 ] [                  (p - q) I ]   [  1  -1 ] [ Y ]
	
	A[m] + r I = [ A[m-1] + r       I  A[m-1] + 2^(m-1) I ]
	             [ A[m-1] + 2^(m-1) I  A[m-1] + r       I ]
*/

immutable MO = 1051131;
immutable long INV2 = (1 + MO) / 2;

long power(long a, long e) {
	long x = a, y = 1;
	for (; e; e >>= 1, (x *= x) %= MO) if (e & 1) (y *= x) %= MO;
	return y;
}

int[] x;
long[] y;
void solve(int m, long p, long q, long e) {
// writeln(m," ",p," ",q," ",e);
	foreach (i; 0 .. 1 << m) {
		const t = x[i + (1 << m)];
		x[i + (1 << m)] = (x[i] - t) % MO;
		(x[i] += t) %= MO;
	}
	const r = ((p + q) * INV2) % MO;
	if (m == 0) {
		y[0] = (power(r, e) * x[0]) % MO;
	} else {
		solve(m - 1, r, 1 << (m - 1), e);
	}
	y[0 .. 1 << m] *= power(2, e);
	y[0 .. 1 << m] %= MO;
	// y[1 << m .. 1 << (m + 1)] = (x[1 << m .. 1 << (m + 1)] * power(p - q, e)) % MO;
	const c = power(p - q, e);
	foreach (i; 1 << m .. 1 << (m + 1)) {
		y[i] = (x[i] * c) % MO;
	}
	foreach (i; 0 .. 1 << m) {
		const t = y[i + (1 << m)];
		y[i + (1 << m)] = (y[i] - t) % MO;
		(y[i] += t) %= MO;
	}
	y[0 .. 1 << (m + 1)] *= INV2;
	y[0 .. 1 << (m + 1)] %= MO;
}

int M;
long T;
int S;

void main(string[] args) {
	try {
	for (; ; ) {
		M = readInt;
		T = readLong;
		S = readInt;
		
		x = new int[1 << M];
		foreach (i; 0 .. S) {
			x[i] = readInt;
		}
		foreach (i; S .. 1 << M) {
			x[i] = (101 * x[i - S] + 10007) % 1051131;
		}
		
		y = new long[1 << M];
		solve(M - 1, 1, 1 << (M - 1), T);
		
		foreach (i; 0 .. 1 << M) {
			y[i] = (y[i] % MO + MO) % MO;
		}
// if(M<=3)writeln(y);
		long ans;
		foreach (i; 0 .. 1 << M) {
			ans ^= y[i];
		}
		writeln(ans);
		
	}
	} catch (EOFException) {}
}