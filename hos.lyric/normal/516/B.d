import core.thread;
import std.conv, std.stdio, std.string;
import std.algorithm, std.array, std.bigint, std.container, std.math, std.range, std.regex;

//	Input
class EOFException : Throwable { this() { super("EOF"); } }
string[] tokens;
string readToken() { for (; tokens.empty; ) { if (stdin.eof) throw new EOFException; tokens = readln.split; } auto token = tokens[0]; tokens.popFront; return token; }
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


immutable DX = [ +1, 0, -1, 0, ];
immutable DY = [ 0, +1, 0, -1, ];

int M, N;
char[][] A;

bool solve() {
	int[][] deg = new int[][](M, N);
	foreach (x; 0 .. M) foreach (y; 0 .. N) if (A[x][y] == '.') {
		foreach (dir; 0 .. 4) {
			const xx = x + DX[dir];
			const yy = y + DY[dir];
			if (0 <= xx && xx < M && 0 <= yy && yy < N) {
				if (A[xx][yy] == '.') {
					++deg[x][y];
				}
			}
		}
	}
	Pair!(int, int)[] q;
	foreach (x; 0 .. M) foreach (y; 0 .. N) if (A[x][y] == '.') {
		if (deg[x][y] == 1) {
			q ~= pair(x, y);
		}
	}
	for (; !q.empty; ) {
debug{
writeln;
foreach(x;0..M)writeln(A[x].to!string);
}
		const x = q.front.x;
		const y = q.front.y;
		q.popFront;
		if (A[x][y] == '.' && deg[x][y] == 1) {
debug{
writeln(x," ",y);
}
			foreach (dir; 0 .. 4) {
				const xx = x + DX[dir];
				const yy = y + DY[dir];
				if (0 <= xx && xx < M && 0 <= yy && yy < N) {
					if (A[xx][yy] == '.') {
						A[x][y]   = "^<v>"[dir];
						A[xx][yy] = "v>^<"[dir];
						foreach (dir1; 0 .. 4) {
							const xxx = xx + DX[dir1];
							const yyy = yy + DY[dir1];
							if (0 <= xxx && xxx < M && 0 <= yyy && yyy < N) {
								if (A[xxx][yyy] == '.') {
									if (--deg[xxx][yyy] == 1) {
										q ~= pair(xxx, yyy);
									}
								}
							}
						}
						break;
					}
				}
			}
		}
	}
	foreach (x; 0 .. M) foreach (y; 0 .. N) {
		if (A[x][y] == '.') {
			return false;
		}
	}
	foreach (x; 0 .. M) {
		writeln(A[x].to!string);
	}
	return true;
}

void main(string[] args) {
	try {
	for (; ; ) {
		M = readInt;
		N = readInt;
		A = new char[][M];
		foreach (x; 0 .. M) {
			A[x] = readToken.to!(char[]);
		}
		
		const res = solve;
		if (!res) {
			writeln("Not unique");
		}
		
	}
	} catch (EOFException) {}
}