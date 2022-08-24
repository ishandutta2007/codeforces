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


immutable long ONE = 100_000_000;
immutable long INF = 1_000_000_000;

// int[] doIt(in int[] ds) {
	// int[] costs = INF ~ ds.dup ~ INF;
int[] doIt(int[] ds) {
	int[] costs = INF ~ ds ~ INF;
	const int n = costs.length;
	int[] lef = new int[n];
	int[] rig = new int[n];
	foreach (i; 0 .. n) {
		lef[i] = i - 1;
		rig[i] = i + 1;
	}
	// auto q = BinaryHeap!(Array!(Pair!(int, int)), "a.x > b.x")();
	auto q = BinaryHeap!(Pair!(int, int)[], "a.x > b.x")(new Pair!(int, int)[n + n / 2], 0);
	foreach (i; 0 .. n) {
		q.insert(Pair!(int, int)(costs[i], i));
	}
	int[] ret = [ 0 ];
	for (; !q.empty; ) {
		const c = q.front.x;
		const i = q.front.y;
		q.removeFront;
		if (lef[i] == -2 || rig[i] == -2) {
			continue;
		}
		if (c >= INF) {
			break;
		}
// writeln(c," ",i);
		ret ~= ret[$ - 1] + c;
		const li = lef[i];
		const ri = rig[i];
		lef[i] = lef[li];
		rig[i] = rig[ri];
		if (0 <= lef[i]) {
			rig[lef[i]] = i;
		}
		if (rig[i] < n) {
			lef[rig[i]] = i;
		}
		lef[li] = rig[li] = lef[ri] = rig[ri] = -2;
		if (0 <= lef[i] && rig[i] < n) {
			costs[i] = costs[li] + costs[ri] - costs[i];
			q.insert(Pair!(int, int)(costs[i], i));
		}
	}
	return ret;
}

long solve(in string s) {
debug{
writeln("s = ",s);
}
	const int n = s.length;
	long ret;
	
	//	even
	{
		int[] ds = [ 0 ];
		foreach (i, c; s) if (c != 'X') {
			const side = ("LR"[i % 2] == c) ? 0 : 1;
			for (; (ds.length - 1) % 2 != side; ) {
				ds ~= 0;
			}
			++ds[$ - 1];
		}
debug{
writeln("ds = ",ds);
}
		const int len = ds.length;
		const int dsSum = reduce!"a + b"(0, ds);
		ds = 0 ~ ds;
		if (n % 2 == 0) {
			if (len % 2 == 0) {
				//
			} else {
				ds ~= 0;
			}
		} else {
			if (len % 2 == 0) {
				ds ~= 0;
			} else {
				//
			}
		}
debug{
writeln("ds = ",ds);
}
		int[] res = doIt(ds);
debug{
writeln("doIt = ",res);
}
		foreach (k, cost; res) {
			//	k = number of batsu's
			const nmr = dsSum - cost;
			int dnm = n;
			int numPairs;
			if (n % 2 == 0) {
				if (len % 2 == 0) {
					numPairs = len / 2 - (k - 1);
					dnm += numPairs * 2;
				} else {
					numPairs = len / 2 - (k - 2);
					dnm += numPairs * 2;
				}
			} else {
				if (len % 2 == 0) {
					numPairs = len / 2 - 1 - (k - 2);
					dnm += numPairs * 2 + 1;
				} else {
					numPairs = len / 2 - (k - 1);
					dnm += numPairs * 2 + 1;
				}
			}
			if (numPairs >= 0) {
debug{
writeln("numPairs = ",numPairs," : ",nmr,"/",dnm," = ",nmr/cast(real)(dnm));
}
				chmax(ret, ONE * nmr / dnm);
			}
		}
	}
	
	//	odd
	{
		const nmr = s.count!"a != 'X'";
		int dnm = n;
		if (dnm % 2 == 0) {
			++dnm;
		}
		dnm *= 2;
		chmax(ret, ONE * nmr / dnm);
	}
	
	return ret;
}

string S;

void main(string[] args) {
	try {
	for (; ; ) {
		S = readToken;
// char[]cs=new char[1_000_000];for(int i=0;i<1_000_000;i+=4){cs[i]='L';cs[i+1]='X';cs[i+2]='R';cs[i+3]='X';}S=cs.to!string~"L";
		
		string s;
		foreach (i, c; S) {
			if (c != 'X' && !s.empty && s[$ - 1] == c) {
				s ~= 'X';
			}
			s ~= c;
		}
		
		long ans;
		if (s[0] != 'X' && s[0] == s[$ - 1]) {
			chmax(ans, solve('X' ~ s));
			chmax(ans, solve(s ~ 'X'));
		} else {
			chmax(ans, solve(s));
		}
		writefln("%.6f", ans / 1e+6);
		
	}
	} catch (EOFException) {}
}