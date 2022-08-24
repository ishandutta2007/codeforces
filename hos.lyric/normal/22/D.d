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
int[] A, B;

struct Interval {
	int s, t;
	int id;
}

void main(string[] args) {
	try {
	for (; ; ) {
		N = readInt;
		A = new int[N];
		B = new int[N];
		foreach (i; 0 .. N) {
			A[i] = readInt;
			B[i] = readInt;
			if (A[i] > B[i]) {
				swap(A[i], B[i]);
			}
		}
		
		Interval[] as = new Interval[N];
		foreach (i; 0 .. N) {
			as[i] = Interval(A[i], B[i], i);
		}
		as.sort!((a, b) => (a.s != b.s) ? (a.s < b.s) : (a.t < b.t));
debug{
writeln(as);
}
		
		int[] dp = new int[N];
		foreach (i; 0 .. N) {
			dp[i] = 1;
			foreach (j; 0 .. i) {
				if (as[j].t < as[i].s) {
					chmax(dp[i], dp[j] + 1);
				}
			}
		}
debug{
writeln("dp = ",dp);
}
		
		const ans = reduce!max(0, dp);
		int[] ss = new int[ans + 1];
		int[] ts = new int[ans + 1];
		ss[] = int.min;
		ts[] = int.max;
		foreach (i; 0 .. N) {
			chmax(ss[dp[i]], as[i].s);
			chmin(ts[dp[i]], as[i].t);
		}
debug{
writeln(ss," ",ts);
}
		foreach (j; 1 .. ans + 1) {
			assert(ss[j] <= ts[j]);
		}
		
		writeln(ans);
		writeln(ss[1 .. $].to!string.removechars("[],"));
		
	}
	} catch (EOFException) {}
}