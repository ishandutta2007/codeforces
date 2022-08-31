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


immutable long MO = 1000000007;
immutable L = 20;
int N;
int[] A;

void main(string[] args) {
	long[] two = new long[1000005];
	two[0] = 1;
	foreach (i; 1 .. two.length) {
		two[i] = (two[i - 1] * 2) % MO;
	}
	int[] pop = new int[1 << L];
	foreach (p; 1 .. 1 << L) {
		pop[p] = 1 + pop[p & (p - 1)];
	}
	
	try {
	for (; ; ) {
		N = readInt;
		A = new int[N];
		foreach (i; 0 .. N) {
			A[i] = readInt;
		}
		
		int[] cnt = new int[1 << L];
		foreach (i; 0 .. N) {
			++cnt[((1 << L) - 1) ^ A[i]];
		}
		foreach (l; 0 .. L) {
			foreach (p; 0 .. 1 << L) if (!(p & 1 << l)) {
				cnt[p | 1 << l] += cnt[p];
			}
		}
// writeln("cnt = ",cnt[0..8]);
		long ans;
		foreach (p; 0 .. 1 << L) {
			(ans += ((pop[p] % 2 != 0) ? -1 : +1) * two[cnt[p]]) %= MO;
		}
		ans = (ans % MO + MO) % MO;
		writeln(ans);
	}
	} catch (EOFException) {}
}