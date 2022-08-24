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
template<class T> void chmin(T &t, T f) { if (t > f) t = f; }
template<class T> void chmax(T &t, T f) { if (t < f) t = f; }
int in() { int x; scanf("%d", &x); return x; }

#define MAX 200010

int M, N, K;
int A[MAX], B[MAX];

bool solve() {
	int i, j;
	sort(A, A + M, greater<int>());
	sort(B, B + N, greater<int>());
	for (j = 0, i = 0; i < M; ++i) {
		for (; j < N && B[j] >= A[i]; ++j);
		if (i + 1 > j) {
// cout<<"A : ";pv(A,A+M);
// cout<<"B : ";pv(B,B+N);
// cout<<i+1<<" "<<j<<endl;
			return 1;
		}
	}
	return 0;
}

int main() {
	int i;
	
	for (; ~scanf("%d%d%d", &M, &N, &K); ) {
		memset(A, 0, sizeof(A));
		memset(B, 0, sizeof(B));
		for (i = 0; i < M; ++i) {
			A[i] = in();
		}
		for (i = 0; i < N; ++i) {
			B[i] = in();
		}
		bool res = solve();
		puts(res ? "YES" : "NO");
	}
	
	return 0;
}