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


immutable INF = 1_001_001_001;

int N;
int[] H, A, B;

void main(string[] args) {
	auto inp = File("input.txt", "r");
	auto outp = File("output.txt", "w");
	for (string line; (line = inp.readln) != null; ) {
		N = line.chomp.to!int;
		H = new int[N];
		A = new int[N];
		B = new int[N];
		foreach (i; 0 .. N) {
			auto tks = inp.readln.split;
			H[i] = tks[0].to!int;
			A[i] = tks[1].to!int;
			B[i] = tks[2].to!int;
		}
		
		int[] xs;
		xs ~= -INF;
		xs ~= +INF;
		foreach (i; 0 .. N) {
			xs ~= A[i];
			xs ~= B[i];
		}
		xs.sort();
		xs = xs.unique;
debug{
writeln("xs = ",xs);
}
		const int n = xs.length - 1;
		
		int[][] adds = new int[][n + 1];
		foreach (i; 0 .. N) {
			const j = xs.lowerBound(A[i]);
			adds[j] ~= i;
		}
		
		int[] ys = new int[n];
		auto q = BinaryHeap!(Array!(Pair!(int, int)))();
		q.insert(pair(0, INF));
		foreach (j; 0 .. n) {
			foreach (i; adds[j]) {
				q.insert(pair(H[i], B[i]));
			}
			for (; q.front.y <= xs[j]; ) {
				q.removeFront;
			}
			ys[j] = q.front.x;
		}
debug{
writeln("ys = ",ys);
}
		
		Pair!(int, int)[] ans;
		ans ~= pair(xs[1], 0);
		for (int j = 1, k; j < n - 1; j = k) {
			for (k = j; k < n - 1 && ys[j] == ys[k]; ++k) {}
			ans ~= pair(xs[j], ys[j]);
			ans ~= pair(xs[k], ys[j]);
		}
		ans ~= pair(xs[n - 1], 0);
		outp.writeln(ans.length);
		foreach (p; ans) {
			outp.writeln(p.x, " ", p.y);
		}
	}
}