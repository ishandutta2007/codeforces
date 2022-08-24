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


class Node {
	Node l, r;
	long val;
	this(long val) {
		this.val = val;
	}
}

int N;
long[] A;

void main(string[] args) {
	try {
	for (; ; ) {
		N = readInt;
		A = new long[N];
		foreach (i; 0 .. N) {
			A[i] = readLong;
		}
		
		if (N <= 2) {
			writeln(0);
			continue;
		}
		
		Node[] nodes = new Node[N];
		foreach (i; 0 .. N) {
			nodes[i] = new Node(A[i]);
		}
		foreach (i; 0 .. N) {
			if (0 <= i - 1) {
				nodes[i].l = nodes[i - 1];
			}
			if (i + 1 < N) {
				nodes[i].r = nodes[i + 1];
			}
		}
		
		nodes.sort!"a.val < b.val";
		long ans;
		foreach (node; nodes[0 .. $ - 2]) {
debug{
Node[]ls;for(Node a=node.l;a;a=a.l)ls~=a;
foreach_reverse(a;ls)write(a.val," ");
for(Node a=node;a;a=a.r)write(a.val," ");
writeln;
}
			if (node.l is null && node.r is null) {
				//
			} else if (node.l is null) {
				ans += node.val;
				node.r.l = null;
			} else if (node.r is null) {
				ans += node.val;
				node.l.r = null;
			} else {
				ans += min(node.l.val, node.r.val);
				node.l.r = node.r;
				node.r.l = node.l;
			}
		}
		writeln(ans);
	}
	} catch (EOFException) {}
}