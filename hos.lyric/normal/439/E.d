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


immutable long MO = 1000000007;
immutable LIM = 200005;
int[] meb;
long[] inv, fac, fnv;

void main(string[] args) {
	meb = new int[LIM];
	meb[1] = 1;
	foreach (i; 1 .. LIM) for (int j = i * 2; j < LIM; j += i) meb[j] -= meb[i];
debug{
writeln("meb = ",meb[0..30]);
}
	inv = new long[LIM];
	inv[1] = 1;
	foreach (i; 2 .. LIM) {
		inv[i] = MO - MO / i * inv[cast(int)(MO % i)] % MO;
	}
	fac = new long[LIM];
	fnv = new long[LIM];
	fac[0] = fnv[0] = 1;
	foreach (i; 1 .. LIM) {
		fac[i] = fac[i - 1] * i % MO;
		fnv[i] = fnv[i - 1] * inv[i] % MO;
	}
	
	foreach (tc; 0 .. readInt) {
		const n = readInt;
		const f = readInt;
		long ans;
		void doIt(int d) {
			if (meb[d]) {
				const m = n / d;
				if (m >= f) {
					long tmp = 1;
					(tmp *= fac[m - 1]) %= MO;
					(tmp *= fnv[m - f]) %= MO;
					(tmp *= fnv[f - 1]) %= MO;
debug{
writeln(n," ",f,"  ",d," : ",meb[d]," ",tmp);
}
					ans += meb[d] * tmp;
				}
			}
		}
		for (int d = 1; d * d <= n; ++d) if (n % d == 0) {
			doIt(d);
			if (d != n / d) {
				doIt(n / d);
			}
		}
		ans = (ans % MO + MO) % MO;
		writeln(ans);
	}
}