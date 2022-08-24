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
int[] P;

void main(string[] args) {
	try {
	for (; ; ) {
		N = readInt + 1;
		P = new int[N];
		P[0] = -1;
		foreach (u; 1 .. N) {
			P[u] = readInt - 1;
		}
		
		int[] ans = new int[N];
		int[] dp = new int[N];
		auto bests = new Pair!(int, int)[][](N, 2);
		
		foreach (u; 1 .. N) {
debug{
writeln("u = ",u);
writeln("dp = ",dp);
writeln("bests = ",bests);
}
			dp[u] = 1;
			bests[u][] = pair(0, -1);
			for (int v = u; v != 0; v = P[v]) {
				auto bp = bests[P[v]];
				foreach (j; 0 .. 2) {
					if (bp[j].y == v) {
						bp[j].x = -1;
					}
				}
				if (bp[0] < bp[1]) {
					swap(bp[0], bp[1]);
				}
				auto tmp = pair(dp[v], v);
				foreach (j; 0 .. 2) {
					if (bp[j] < tmp) {
						bp[j].swap(tmp);
					}
				}
				const nxt = max(bp[0].x, bp[1].x + 1);
				if (dp[P[v]] == nxt) {
					break;
				}
				dp[P[v]] = nxt;
			}
			ans[u] = bests[0][0].x;
		}
		
		writeln(ans[1 .. N].to!string.removechars("[],"));
	}
	} catch (EOFException) {}
}