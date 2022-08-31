#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <utility>
#include <numeric>
#include <algorithm>
#include <bitset>
#include <complex>

using namespace std;

typedef unsigned uint;
typedef long long Int;
typedef vector<int> vint;
typedef pair<int,int> pint;
#define mp make_pair

template<class T> void pv(T a, T b) { for (T i = a; i != b; ++i) cout << *i << " "; cout << endl; }
template<class T> void chmin(T &t, const T &f) { if (t > f) t = f; }
template<class T> void chmax(T &t, const T &f) { if (t < f) t = f; }
int in() { int x; scanf("%d", &x); return x; }

int N, M;
int X[1000010], Y[1000010];

int bitN;
int bit[2100010];

void bitAdd(int pos, int val) {
	for (int x = pos; x <= bitN; x += x & -x) bit[x] += val;
}
int bitLowerBound(int w) {
	if (w <= 0) return 0; 
	int x = 0; 
	for (int k = bitN; k > 0; k /= 2) { 
		if (x + k <= bitN && bit[x + k] < w) { 
			w -= bit[x + k]; 
			x += k; 
		} 
	} 
	return x + 1; 
}

int perm[1000010];
int ids[2000010];
bool used[1000010];

bool solve() {
	for (bitN = 2; bitN < M + N + 5; bitN <<= 1);
	memset(bit, 0, sizeof(bit));
	memset(perm, ~0, sizeof(perm));
	memset(ids, ~0, sizeof(ids));
	for (int j = 1; j <= N; ++j) {
		bitAdd(M + j, +1);
		ids[M + j] = j;
	}
	for (int i = 0; i < M; ++i) {
		const int pos = bitLowerBound(Y[i]);
		const int j = ids[pos];
// cout<<pos<<" "<<j<<endl;
		if (!~perm[j]) {
			perm[j] = X[i];
		}
		if (perm[j] != X[i]) {
			return false;
		}
		bitAdd(pos, -1);
		bitAdd(M - i, +1);
		ids[pos] = -1;
		ids[M - i] = j;
	}
// cout<<"perm : ";pv(perm+1,perm+N+1);
	memset(used, 0, sizeof(used));
	for (int j = 1; j <= N; ++j) if (~perm[j]) {
		if (used[perm[j]]) {
			return false;
		}
		used[perm[j]] = true;
	}
	int k = 1;
	for (int j = 1; j <= N; ++j) if (!~perm[j]) {
		for (; used[k]; ++k);
		perm[j] = k;
		used[k] = true;
	}
	return true;
}

int main() {
	
	
	for (; ~scanf("%d%d", &N, &M); ) {
		for (int i = 0; i < M; ++i) {
			X[i] = in();
			Y[i] = in();
		}
		bool res = solve();
		if (res) {
			for (int j = 1; j <= N; ++j) {
				if (j > 1) printf(" ");
				printf("%d", perm[j]);
			}
			puts("");
		} else {
			puts("-1");
		}
	}
	
	return 0;
}