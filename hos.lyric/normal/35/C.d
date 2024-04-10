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


int M, N, K;
int[] X, Y;

void main(string[] args) {
	auto inp = File("input.txt", "r");
	auto outp = File("output.txt", "w");
	for (string line; (line = inp.readln) != null; ) {
		{
			auto tks = line.split;
			M = tks[0].to!int;
			N = tks[1].to!int;
		}
		K = inp.readln.chomp.to!int;
		X = new int[K];
		Y = new int[K];
		{
			auto tks = inp.readln.split;
			foreach (i; 0 .. K) {
				X[i] = tks[i * 2 + 0].to!int;
				Y[i] = tks[i * 2 + 1].to!int;
			}
		}
		
		int opt = -1;
		int xm = -1, ym = -1;
		foreach (x; 1 .. M + 1) foreach (y; 1 .. N + 1) {
			int tmp = M + N;
			foreach (i; 0 .. K) {
				chmin(tmp, abs(x - X[i]) + abs(y - Y[i]));
			}
			if (opt < tmp) {
				opt = tmp;
				xm = x;
				ym = y;
			}
		}
		outp.writeln(xm, " ", ym);
	}
}