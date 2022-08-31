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
#include <deque>
#include <set>
#include <map>
#include <utility>
#include <numeric>
#include <algorithm>
#include <bitset>
#include <complex>
#include <unordered_set>
#include <unordered_map>

using namespace std;

typedef unsigned uint;
typedef long long Int;
typedef vector<int> vint;
typedef pair<int,int> pint;
#define mp make_pair

template<typename T> void pv(T a, T b) { for (T i = a; i != b; ++i) cout << *i << " "; cout << endl; }
template<typename T> void chmin(T &t, const T &f) { if (t > f) t = f; }
template<typename T> void chmax(T &t, const T &f) { if (t < f) t = f; }
int in() { int x; scanf("%d", &x); return x; }

int M, N;
int A[1010][1010];
int dp0[1010][1010];
int dp1[1010][1010];
int dp2[1010][1010];
int dp3[1010][1010];

int main() {
	
	
	for (; ~scanf("%d%d", &M, &N); ) {
		for (int x = 1; x <= M; ++x) for (int y = 1; y <= N; ++y) {
			A[x][y] = in();
		}
		memset(dp0, 0, sizeof(dp0));
		memset(dp1, 0, sizeof(dp1));
		memset(dp2, 0, sizeof(dp2));
		memset(dp3, 0, sizeof(dp3));
		for (int x = 1; x <= M; ++x) for (int y = 1; y <= N; ++y) {
			chmax(dp0[x][y], dp0[x - 1][y] + A[x][y]);
			chmax(dp0[x][y], dp0[x][y - 1] + A[x][y]);
		}
		for (int x = 1; x <= M; ++x) for (int y = N; y >= 1; --y) {
			chmax(dp1[x][y], dp1[x - 1][y] + A[x][y]);
			chmax(dp1[x][y], dp1[x][y + 1] + A[x][y]);
		}
		for (int x = M; x >= 1; --x) for (int y = N; y >= 1; --y) {
			chmax(dp2[x][y], dp2[x + 1][y] + A[x][y]);
			chmax(dp2[x][y], dp2[x][y + 1] + A[x][y]);
		}
		for (int x = M; x >= 1; --x) for (int y = 1; y <= N; ++y) {
			chmax(dp3[x][y], dp3[x + 1][y] + A[x][y]);
			chmax(dp3[x][y], dp3[x][y - 1] + A[x][y]);
		}
// for(int x=1;x<=M;++x)pv(dp0[x]+1,dp0[x]+N+1);cout<<endl;
// for(int x=1;x<=M;++x)pv(dp1[x]+1,dp1[x]+N+1);cout<<endl;
// for(int x=1;x<=M;++x)pv(dp2[x]+1,dp2[x]+N+1);cout<<endl;
// for(int x=1;x<=M;++x)pv(dp3[x]+1,dp3[x]+N+1);cout<<endl;
		int ans = 0;
		for (int x = 2; x <= M - 1; ++x) for (int y = 2; y <= N - 1; ++y) {
			chmax(ans, dp0[x - 1][y] + dp1[x][y + 1] + dp2[x + 1][y] + dp3[x][y - 1]);
			chmax(ans, dp1[x - 1][y] + dp2[x][y + 1] + dp3[x + 1][y] + dp0[x][y - 1]);
		}
		printf("%d\n", ans);
	}
	
	return 0;
}