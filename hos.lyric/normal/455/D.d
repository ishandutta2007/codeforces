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


immutable BLOCK_SIZE = 1000;

int N;
int[] A;

int numBlocks;
int[][] valss;
int[][] cntss;

void rotate(int l, int r) {
	const ql = l / BLOCK_SIZE, rl = l % BLOCK_SIZE;
	const qr = r / BLOCK_SIZE, rr = r % BLOCK_SIZE;
	int[] work;
	
	const a0 = valss[qr][$ - 1 - rr];
	valss[qr] = valss[qr][0 .. $ - 1 - rr] ~ valss[qr][$ - rr .. $];
	--cntss[qr][a0];
	
	valss[ql] = valss[ql][0 .. $ - rl] ~ a0 ~ valss[ql][$ - rl .. $];
	++cntss[ql][a0];
	
	foreach (j; ql .. qr) {
		const a = valss[j][0];
		valss[j] = valss[j][1 .. $];
		--cntss[j][a];
		valss[j + 1] ~= a;
		++cntss[j + 1][a];
	}
}

int count(int l, int r, int k) {
	const ql = l / BLOCK_SIZE, rl = l % BLOCK_SIZE;
	const qr = r / BLOCK_SIZE, rr = r % BLOCK_SIZE;
	
	int ret;
	if (ql == qr) {
		foreach (a; valss[ql][$ - 1 - rr .. $ - rl]) {
			if (a == k) {
				ret += 1;
			}
		}
	} else {
		foreach (a; valss[ql][0 .. $ - rl]) {
			if (a == k) {
				ret += 1;
			}
		}
		foreach (j; ql + 1 .. qr) {
			ret += cntss[j][k];
		}
		foreach (a; valss[qr][$ - 1 - rr .. $]) {
			if (a == k) {
				ret += 1;
			}
		}
	}
	return ret;
}

void main(string[] args) {
	try {
	for (; ; ) {
		N = readInt;
		A = new int[N];
		foreach (i; 0 .. N) {
			A[i] = readInt;
		}
		
		numBlocks = (N + BLOCK_SIZE - 1) / BLOCK_SIZE;
		valss = new int[][numBlocks];
		cntss = new int[][](numBlocks, N + 1);
		foreach_reverse (i; 0 .. N) {
			const qi = i / BLOCK_SIZE;
			valss[qi] ~= A[i];
			++cntss[qi][A[i]];
		}
		
		int lastans = 0;
		foreach (q; 0 .. readInt) {
debug{
writeln("valss = ",valss);
writeln("cntss = ",cntss);
}
			switch (readInt) {
				case 1: {
					int l_ = readInt;
					int r_ = readInt;
					int l = ((l_ + lastans - 1) % N) + 1;
					int r = ((r_ + lastans - 1) % N) + 1;
					if (l > r) {
						swap(l, r);
					}
debug{
writeln("**** rotate ",l," ",r," ****");
}
					--l;
					--r;
					if (l < r) {
						rotate(l, r);
					}
				} break;
				case 2: {
					int l_ = readInt;
					int r_ = readInt;
					int k_ = readInt;
					int l = ((l_ + lastans - 1) % N) + 1;
					int r = ((r_ + lastans - 1) % N) + 1;
					int k = ((k_ + lastans - 1) % N) + 1;
					if (l > r) {
						swap(l, r);
					}
debug{
writeln("**** count  ",l," ",r," ",k," ****");
}
					--l;
					--r;
					const res = count(l, r, k);
					writeln(res);
					lastans = res;
				} break;
				default: assert(false);
			}
		}
	}
	} catch (EOFException) {}
}