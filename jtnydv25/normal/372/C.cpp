#include <bits/stdc++.h>
using namespace std;
#define sd(x) scanf("%d", &(x))
#define ll long long

const int N = 1.5e5 + 10;
const int M = 305;
int dp[N];
int t[N], a[N], b[N], n, m, d;
const int INF = 2e9;
int tree[N << 2];

int RMQ[20][N];
int floorlog[N];

inline void make(){
	for(int i = n; i >= 1; i--){
		RMQ[0][i] = dp[i];
		// 2^j <= n + 1 - i
		int mxj = floorlog[n + 1 - i];
		int pw = 1;
		for(int j = 1; j <= mxj; j++){
			RMQ[j][i] = min(RMQ[j - 1][i], RMQ[j - 1][i + pw]);
			pw <<= 1;
		}
	}
}

inline int get(int i, int j){
	// 2^k<= j + 1 - i
	int k = floorlog[j + 1 - i];
	return min(RMQ[k][i], RMQ[k][j - (1 << k) + 1]);
}
void go(int i){
	if(i == 0) return;
	make();
	for(int x = 1; x <= n; x++){
		int mnNxt = max(1LL, x - d * 1ll * (t[i + 1] - t[i]));
		int mxNxt = min((ll)n, x + d * 1ll * (t[i + 1] - t[i]));
		int cost = abs(x - a[i]);
		dp[x] = cost + get(mnNxt, mxNxt);
	}
	go(i - 1);
}

int main(){
	for(int i = 0; (1 << i) < N; i++)
		for(int j = (1 << i); j < N && j < (1 << (i + 1)); j++)
			floorlog[j] = i;
	sd(n); sd(m); sd(d);
	long long ans = 0;
	for(int i = 1; i <= m; i++){
		sd(a[i]);
		sd(b[i]);
		sd(t[i]);
		ans += b[i];
	}
	t[m + 1] = 2e9;
	go(m);
	int L = INF;
	for(int i = 1; i <= n; i++) L = min(L, dp[i]);
	ans -= L;
	printf("%lld\n", ans);
}