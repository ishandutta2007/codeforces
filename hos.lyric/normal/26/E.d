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


int N, W;
int[] A;

int[] solve() {
	int[] ret;
	const sumA = reduce!"a + b"(0, A);
	if (!(1 <= W && W <= sumA)) {
		return null;
	}
	if (N == 1) {
		if (W != A[0]) {
			return null;
		}
		ret.length = A[0] * 2;
		ret[] = 0;
		return ret;
	}
	int im = -1;
	foreach (i; 0 .. N) {
		if (A[i] == 1) {
			im = i;
		}
	}
	if (im != -1) {
		int[] kills = new int[N];
		int need = sumA - W;
		foreach (i; 0 .. N) {
			kills[i] = min(need, A[i] - ((i == im) ? 1 : 0));
			need -= kills[i];
		}
debug{
writeln("kills = ",kills);
}
		ret ~= im;
		foreach (i; 0 .. N) {
			foreach (_; 0 .. kills[i]) {
				ret ~= i;
				ret ~= i;
			}
		}
		ret ~= im;
		foreach (i; 0 .. N) {
			foreach (_; 0 .. A[i] - ((i == im) ? 1 : 0) - kills[i]) {
				ret ~= i;
				ret ~= i;
			}
		}
		return ret;
	} else {
		if (W == 1) {
			return null;
		}
		int[] kills = new int[N];
		int need = sumA - W;
		foreach (i; 0 .. N) {
			kills[i] = min(need, A[i] - ((i < 2) ? 1 : 0));
			need -= kills[i];
		}
debug{
writeln("kills = ",kills);
}
		ret ~= 0;
		foreach (i; 1 .. N) {
			foreach (_; 0 .. kills[i]) {
				ret ~= i;
				ret ~= i;
			}
		}
		ret ~= 0;
		ret ~= 1;
		foreach (j; 0 .. kills[0]) {
			ret ~= 0;
			ret ~= 0;
		}
		ret ~= 1;
		foreach (i; 0 .. N) {
			foreach (_; 0 .. A[i] - ((i < 2) ? 1 : 0) - kills[i]) {
				ret ~= i;
				ret ~= i;
			}
		}
		return ret;
	}
}

int judge(int[] xs) {
	int y;
	int[] ys = new int[N];
	bool[] toSet = new bool[N];
	foreach (i; xs) {
		if (toSet[i]) {
			y = ys[i] + 1;
		} else {
			ys[i] = y;
		}
		toSet[i] = !toSet[i];
	}
	return y;
}

void main(string[] args) {
	try {
	for (; ; ) {
		N = readInt;
		W = readInt;
		A = new int[N];
		foreach (i; 0 .. N) {
			A[i] = readInt;
		}
		
		if (auto res = solve) {
			writeln("Yes");
			foreach (idx, i; res) {
				if (idx > 0) {
					write(" ");
				}
				write(i + 1);
			}
			writeln;
debug{
assert(W==res.judge);
}
		} else {
			writeln("No");
		}
	}
	} catch (EOFException) {}
}