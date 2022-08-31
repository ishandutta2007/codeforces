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


immutable INF = 1001001001;

immutable LIM = 59;
immutable PS = [ 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53 ];
int[] hits;

int N;
int[] A;

void main(string[] args) {
	hits = new int[LIM];
	foreach (x; 1 .. LIM) {
		foreach (k, p; PS) {
			if (x % p == 0) {
				hits[x] |= 1 << k;
			}
		}
	}
	
	try {
	for (; ; ) {
		N = readInt;
		A = new int[N];
		foreach (i; 0 .. N) {
			A[i] = readInt;
		}
		
		int[][] dp = new int[][](N + 1, 1 << PS.length);
		int[][] prv = new int[][](N + 1, 1 << PS.length);
		
		foreach (i; 0 .. N + 1) {
			dp[i][] = INF;
		}
		dp[0][0] = 0;
		foreach (i; 0 .. N) {
			foreach (s; 0 .. 1 << PS.length) {
				foreach (x; 1 .. LIM) if (!(s & hits[x])) {
					if (dp[i + 1][s | hits[x]] > dp[i][s] + abs(A[i] - x)) {
						dp[i + 1][s | hits[x]] = dp[i][s] + abs(A[i] - x);
						prv[i + 1][s | hits[x]] = x;
					}
				}
			}
		}
		
		int opt = INF;
		int sm = -1;
		foreach (s; 0 .. 1 << PS.length) {
			if (opt > dp[N][s]) {
				opt = dp[N][s];
				sm = s;
			}
		}
stderr.writeln("opt = ",opt);
		
		int[] ans = new int[N];
		{
			int s = sm;
			foreach_reverse (i; 0 .. N) {
				const x = prv[i + 1][s];
				ans[i] = x;
				s ^= hits[x];
			}
		}
		foreach (i; 0 .. N) {
			if (i > 0) write(" ");
			write(ans[i]);
		}
		writeln;
	}
	} catch (EOFException) {}
}