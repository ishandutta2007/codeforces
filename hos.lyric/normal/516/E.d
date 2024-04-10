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


Int mod(Int)(Int a, Int m) { if ((a %= m) < 0) a += m; return a; }
Int gcd(Int)(Int a, Int b) { return (b != 0) ? gcd(b, a % b) : a; }
Int lcm(Int)(Int a, Int b) { return a / gcd(a, b) * b; }
Int gojo(Int)(Int a, Int b, out Int x, out Int y) {
	if (b != 0) { Int g = gojo(b, a % b, y, x); y -= (a / b) * x; return g; }
	x = 1; y = 0; return a;
}
Int modInv(Int)(Int a, Int m) { Int x, y; gojo(a, m, x, y); return mod(x, m); }

immutable INF = 2 * 10L^^18 + 1;

int esLen;
int[] es;

int[] work;
int[] bkt;

void radixSort() {
	if (esLen < 0x10000) {
		es[0 .. esLen].sort();
	} else {
		bkt[] = 0;
		foreach (i; 0 .. esLen) ++bkt[es[i] & 0xFFFF];
		foreach (j; 0 .. 0xFFFF) bkt[j + 1] += bkt[j];
		foreach (i; 0 .. esLen) work[--bkt[es[i] & 0xFFFF]] = es[i];
		bkt[] = 0;
		foreach (i; 0 .. esLen) ++bkt[work[i] >> 16];
		foreach (j; 0 .. 0xFFFF) bkt[j + 1] += bkt[j];
		foreach_reverse (i; 0 .. esLen) es[--bkt[work[i] >> 16]] = work[i];
	}
}

bool check(int s, long m, long n, Pair!(long, int)[] xs, long[] ps, long l) {
debug{
writeln("check ",s," ",m," ",n," ",xs," ",ps," ",l);
}
	// Pair!(long, int)[] es;
	// long[] es;
	esLen = 0;
	foreach (i, x; xs) {
		/*
			x, x + m, x + 2 m, ... (mod n)
			while x + k m <= l
		*/
		const a = ps[i];
		const k = (x.x <= l) ? min((l - x.x) / m + 1, n) : (x.y != s) ? 1 : 0;
		if (a + k <= n) {
			// es ~= pair(a, +1);
			// es ~= pair(a + k, -1);
			// es ~= a << 1;
			// es ~= (a + k) << 1 | 1;
			es[esLen++] = cast(int)(a << 1);
			es[esLen++] = cast(int)((a + k) << 1 | 1);
		} else {
			// es ~= pair(a, +1);
			// es ~= pair(n, -1);
			// es ~= pair(0L, +1);
			// es ~= pair(a + k - n, -1);
			// es ~= a << 1;
			// es ~= n << 1 | 1;
			// es ~= 0 << 1;
			// es ~= (a + k - n) << 1 | 1;
			es[esLen++] = cast(int)(a << 1);
			es[esLen++] = cast(int)(n << 1 | 1);
			es[esLen++] = cast(int)(0 << 1);
			es[esLen++] = cast(int)((a + k - n) << 1 | 1);
		}
	}
	// es.sort();
	// es[0 .. esLen].sort();
	radixSort;
debug{
// writeln("  es = ",es);
writeln("  es = ",es[0..esLen]);
}
	long bef;
	int now;
	// foreach (e; es) {
	foreach (i; 0 .. esLen) {
		auto e = es[i];
		// if (bef < e.x) {
		if (bef < e >> 1) {
			if (now <= 0) {
debug{
// writeln("  fail ",bef,e.x);
writeln("  fail ",bef,e>>1);
}
				return false;
			}
		}
		// bef = e.x;
		// now += e.y;
		bef = e >> 1;
		now += (e & 1) ? -1 : +1;
	}
	if (bef < n) {
		return false;
	}
	return true;
}

long solve(long m, long n, Pair!(long, int)[] xs) {
debug{
writeln("solve ",m," ",n," ",xs);
}
	if (xs.empty) {
		return INF;
	}
	if (xs.length == m + n) {
		return -1;
	}
	auto ps = new long[xs.length];
	auto qs = new long[xs.length];
	foreach (i, x; xs) {
		ps[i] = (x.x * modInv(m, n)) % n;
		qs[i] = (x.x * modInv(n, m)) % m;
	}
	long lo = -1, ho = 2 * m * n;
	for (; lo + 1 < ho; ) {
		const mo = (lo + ho) / 2;
		(check(0, m, n, xs, ps, mo) && check(1, n, m, xs, qs, mo)) ? (ho = mo) : (lo = mo);
	}
debug{
assert(check(0, m, n, xs, ps, ho));
assert(check(1, n, m, xs, qs, ho));
}
	return ho;
}

long M, N;
long[] A, B;

long brute() {
	auto isA = new bool[cast(size_t)(M)];
	auto isB = new bool[cast(size_t)(N)];
	long cnt;
	foreach (a; A) {
		isA[cast(size_t)(a)] = true;
		++cnt;
	}
	foreach (b; B) {
		isB[cast(size_t)(b)] = true;
		++cnt;
	}
	if (cnt == M + N) {
		return -1;
	}
	foreach (x; 0 .. 1000) {
		const a = cast(size_t)(x % M);
		const b = cast(size_t)(x % N);
		if (isA[a] && !isB[b]) {
			isB[b] = true;
			++cnt;
		}
		if (isB[b] && !isA[a]) {
			isA[a] = true;
			++cnt;
		}
		if (cnt == M + N) {
			return x;
		}
	}
	return -1;
}

long solve() {
	const d = gcd(M, N);
	if (d > M + N) {
		return -1;
	}
	auto xss = new Pair!(long, int)[][cast(size_t)(d)];
	foreach (a; A) {
		xss[cast(size_t)(a % d)] ~= pair(a / d, 0);
	}
	foreach (b; B) {
		xss[cast(size_t)(b % d)] ~= pair(b / d, 1);
	}
	long ans = -1;
	foreach (r; 0 .. d) {
		auto res = solve(M / d, N / d, xss[cast(size_t)(r)]);
		if (res >= INF) {
			ans = INF;
		} else {
			chmax(ans, res * d + r);
		}
	}
	return (ans >= INF) ? -1 : ans;
}

void main(string[] args) {
	es = new int[8 * 10^^5 + 10];
	work = new int[8 * 10^^5 + 10];
	bkt = new int[0x10000];
	
	try {
	for (; ; ) {
		M = readLong;
		N = readLong;
		A = new long[readInt];
		foreach (ref a; A) {
			a = readLong;
		}
		B = new long[readInt];
		foreach (ref b; B) {
			b = readLong;
		}
		
		const res = solve;
debug{
const brt=brute;
if(brt!=res){
writeln(M," ",N," ",A," ",B," : ",brt," ",res);
stdout.flush;
assert(false);
}
}
		writeln(res);
		
	}
	} catch (EOFException) {}
}