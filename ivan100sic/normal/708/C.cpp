#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <set>
#include <cstring>
using namespace std;

const int MAXN = 1 << 20;

inline int gc(){
	return getchar();
}

int getint(){
	int x = gc();
	while (x <= 32) x = gc();
	int a = x - 48;
	while (1){
		x = gc();
		if (x <= 32) return a;
		a = 10*a + x - 48;
	}
}	

int N, Nh;
vector<int> E[400005];
int P[400005], S[400005], L[400005], R[400005];

int dfs(int x, int p) {
	static int t = 0;
	L[x] = ++t;
	P[x] = p;
	S[x] = 1;
	for (int y : E[x]) {
		if (y != p) {
			S[x] += dfs(y, x);
		}
	}
	R[x] = ++t;
	return S[x];
}

int Tree[2 * MAXN];

void fill() {
	for (int x = 1; x <= N; x++) {
		if (S[x] <= Nh) Tree[L[x] + MAXN - 1] = S[x];
	}
	for (int x = MAXN - 1; x >= 1; x--) {
		Tree[x] = max(Tree[2*x], Tree[2*x+1]);
	}
}

inline bool contains(int l, int r, int low, int sl = 1, int sr = MAXN, int node = 1) {
	if (l <= sl && sr <= r) {
		return Tree[node] >= low;
	}
	if (r < sl || sr < l) return false;
	int mid = (sl + sr) >> 1;
	return contains(l, r, low, sl, mid, 2 * node)
		|| contains(l, r, low, mid + 1, sr, 2 * node + 1);
}

inline void update(int pos, int nu) {
	pos += MAXN - 1;
	Tree[pos] = nu;
	pos >>= 1;
	while (pos) {
		Tree[pos] = max(Tree[2*pos], Tree[2*pos+1]);
		pos >>= 1;
	}
}

char V[800005];

inline void process(int x, int p) {
	int yy = -1;
	V[2*x-2] = '0';
	for (int y : E[x]) {
		if (S[y] > Nh) yy = y;
	}
	if (yy == -1) {
		V[2*x-2] = '1';
	} else {
		if (yy != p) {
			// ne vece od Nh
			// ali ne manje od S[y] - Nh
			V[2*x-2] = contains(L[yy], R[yy], S[yy] - Nh) ? '1' : '0';
		} else {
			V[2*x-2] = (contains(1, L[x] - 1, S[yy] - Nh)
				|| contains(R[x] + 1, 2 * N, S[yy] - Nh)) ? '1' : '0';
		}
	}

	for (int y : E[x]) {
		if (y != p) {

			int old = S[x];
			int nu = N - S[y];

			S[x] = nu;
			if (nu <= Nh) update(L[x], nu);
			else update(L[x], 0);

			process(y, x);

			S[x] = old;
			if (old <= Nh) update(L[x], old);
			else update(L[x], 0);
		}
	}

	
}

int main() {
	N = getint();
	Nh = N / 2;
	for (int i = 1; i<N; i++) {
		int a, b;
		a = getint();
		b = getint();
		E[a].push_back(b);
		E[b].push_back(a);
	}
	
	memset(V, ' ', sizeof(V));
	V[2*N] = 0;

	dfs(1, 1);
	fill();
	process(1, 1);
	
	puts(V);

	return 0;
}