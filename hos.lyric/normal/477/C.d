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


int M, N;
string S, T;

void main(string[] args) {
	try {
	for (; ; ) {
		S = readToken;
		T = readToken;
		
		M = S.length;
		N = T.length;
		int[][] dp = new int[][](M + 1, M + 1);
		foreach (i; 0 .. M + 1) {
			dp[i][] = -1;
		}
		dp[0][0] = 0;
		foreach (i; 0 .. M)	{
			{
				bool ok = true;
				int ii = i;
				foreach (j; 0 .. N) {
					for (; ii < M && S[ii] != T[j]; ++ii) {}
					if (ii < M) {
						++ii;
					} else {
						ok = false;
						break;
					}
				}
				if (ok) {
					const dk = (ii - i) - N;
					foreach (k; 0 .. M + 1) if (k + dk <= M) {
						if (dp[i][k] >= 0) {
							chmax(dp[ii][k + dk], dp[i][k] + 1);
						}
					}
				}
			}
			foreach (k; 0 .. M + 1) {
				if (dp[i][k] >= 0) {
					chmax(dp[i + 1][k], dp[i][k]);
				}
			}
			foreach (k; 0 .. M + 1) if (k + 1 <= M) {
				if (dp[i][k] >= 0) {
					chmax(dp[i + 1][k + 1], dp[i][k]);
				}
			}
		}
		writeln(dp[M].to!string.removechars("[],"));
	}
	} catch (EOFException) {}
}