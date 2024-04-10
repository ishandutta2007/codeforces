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


immutable BLOCK_SIZE = 400;

int N;

bool[] unis;
int[][] as;
long[][] vals;
long[] adds;
long[] sums;

void paint(int l, int r, int x) {
	const jl = l / BLOCK_SIZE, kl = l % BLOCK_SIZE;
	const jr = r / BLOCK_SIZE, kr = r % BLOCK_SIZE;
	foreach (j; [ jl, jr ].unique) {
		if (unis[j]) {
			unis[j] = false;
			as[j][] = as[j][0];
		}
		foreach (k; 0 .. as[j].length) {
			const i = j * BLOCK_SIZE + k;
			if (l <= i && i <= r) {
				const long tmp = abs(as[j][k] - x);
				vals[j][k] += tmp;
				sums[j] += tmp;
				as[j][k] = x;
			}
		}
	}
	foreach (j; jl + 1 .. jr) {
		if (unis[j]) {
			const long tmp = abs(as[j][0] - x);
			adds[j] += tmp;
			sums[j] += tmp * as[j].length;
		} else {
			foreach (k; 0 .. as[j].length) {
				const long tmp = abs(as[j][k] - x);
				vals[j][k] += tmp;
				sums[j] += tmp;
				as[j][k] = x;
			}
		}
		unis[j] = true;
		as[j][0] = x;
	}
}

long getSum(int l, int r) {
	const jl = l / BLOCK_SIZE, kl = l % BLOCK_SIZE;
	const jr = r / BLOCK_SIZE, kr = r % BLOCK_SIZE;
	long ret;
	foreach (j; [ jl, jr ].unique) {
		foreach (k; 0 .. as[j].length) {
			const i = j * BLOCK_SIZE + k;
			if (l <= i && i <= r) {
				ret += vals[j][k];
				ret += adds[j];
			}
		}
	}
	foreach (j; jl + 1 .. jr) {
		ret += sums[j];
	}
	return ret;
}

void main(string[] args) {
	try {
	for (; ; ) {
		N = readInt;
		
debug{
int[] cs=new int[N];
long[] vs=new long[N];
}
		const numBlocks = (N + BLOCK_SIZE - 1) / BLOCK_SIZE;
		unis = new bool[numBlocks];
		as = new int[][numBlocks];
		vals = new long[][numBlocks];
		adds = new long[numBlocks];
		sums = new long[numBlocks];
		
		foreach (i; 0 .. N) {
			const jl = i / BLOCK_SIZE;
			as[jl] ~= (i + 1);
			vals[jl] ~= 0;
debug{
cs[i]=i+1;
vs[i]=0;
}
		}
		
		const QRY = readInt;
		foreach (q; 0 .. QRY) {
debug{
writeln("**** cs = ",cs," ****");
writeln("**** vs = ",vs," ****");
writeln("unis = ",unis);
writeln("as = ",as);
writeln("vals = ",vals);
writeln("adds = ",adds);
writeln("sums = ",sums);
}
			switch (readInt) {
				case 1: {
					const l = readInt - 1;
					const r = readInt - 1;
					const x = readInt;
					paint(l, r, x);
debug{
foreach(i;l..r+1){vs[i]+=abs(cs[i]-x);cs[i]=x;}
}
				} break;
				case 2: {
					const l = readInt - 1;
					const r = readInt - 1;
					const res = getSum(l, r);
debug{
writeln("brute = ",reduce!"a+b"(0L,vs[l..r+1]));
}
					writeln(res);
				} break;
				default: assert(false);
			}
		}
	}
	} catch (EOFException) {}
}