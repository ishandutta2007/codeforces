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


immutable INF = 1_000_000_000_000_000_000;
long mul(long a, long b) {
	if (a == 0 || b == 0) return 0;
	int sa = +1, sb = +1;
	if (a < 0) { a *= -1; sa *= -1; }
	if (b < 0) { b *= -1; sb *= -1; }
	if (a > INF / b) return sa * sb * INF;
	return sa * sb * a * b;
}

immutable LIM_N = 20;
long[] BASES;

immutable L = 15 * 9 * 2 * 2;
int[long][] cache;

int calc(int n, long x) {
	if (n == 0) {
		return (x == 0) ? 0 : L;
	} else {
		const lim = L / n;
		if (abs(x) > mul(BASES[n], lim)) {
			return L;
		}
		if (x !in cache[n]) {
			int ret = L;
			foreach (k; -lim .. +lim + 1) {
				long made = mul(BASES[n], k);
				if (abs(made) < INF) {
debug{
// if(n==2&&x==10)writeln("k = ",k,", made = ",made);
}
					chmin(ret, abs(k) * n + calc(n - 1, x - made));
				}
			}
debug{
// if(n==2&&x==10)
// writeln(n," ",x," : ",ret);
}
			cache[n][x] = ret;
		}
		return cache[n][x];
	}
}

long N;

void main(string[] args) {
	BASES = new long[LIM_N];
	BASES[0] = 0;
	foreach (i; 1 .. LIM_N) {
		BASES[i] = BASES[i - 1] * 10 + 1;
	}
	
	cache = new int[long][LIM_N];
	
	try {
	for (; ; ) {
		N = readLong;
		
		auto res = calc(LIM_N - 1, N);
		writeln(res);
	}
	} catch (EOFException) {}
}