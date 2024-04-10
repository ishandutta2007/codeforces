#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld double
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define pii pair<int,int>
#define vll vector<ll >
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1)
#define all(a) (a).begin(), (a).end()
#define print(s) cerr<<#s<<" : ";for(auto i:(s))cerr<<i<<" ";cerr<<"\n";
#define sd(t) scanf("%d",&(t))
#define pd(t) printf("%d\n",(t))
#define endl "\n"
const int N = 1e6 + 10;
int A[N];
const int INF = 1e9;

bool dp[45][N];
int ans(int h, int w, int a, int b, int n){
	memset(dp, 0, sizeof dp);
	if(h >= a && w >= b) return 0;
	int ret = INF;
	int mn = (a - 1) / h + 1;
	int mn2 = (b - 1) / w + 1;
	dp[0][1] = 1;
	ll P = 1;
	for(int i = 1; i <= n; i++){
		int x = A[i - 1];
		P *= x;
		for(int j = 1; j < N; j++){
			if(dp[i - 1][j]){
				dp[i][j] = 1;
				if(j * 1ll * x < N) dp[i][j * x] = 1;
			}
		}
		for(int j = mn; j < N; j++){
			if(dp[i][j]){
				if(P / j >= mn2) return i;
			}
		}
	}

	return INF;
}
int main(){
	int t = 1, n, h, w, a, b;
	while(t--){
		sd(a), sd(b), sd(h), sd(w), sd(n);
		for(int i = 0; i < n; i++) sd(A[i]);
		sort(A, A + n);
		reverse(A, A + n);
		n = min(n, 40);
		int x = min(ans(h, w, a, b, n), ans(w, h, a, b, n));
		if(x == INF) x = -1;
		printf("%d", x);
	}
}