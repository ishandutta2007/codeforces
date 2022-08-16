#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll INF = 2e18;

const int N = 205;
ll dp[N][N];
int f[N], p[N], perm[N], c[N][N];
ll add(ll a, ll b){
	return min(a + b, INF);
}
ll findDP(int n){
	memset(dp, 0LL, sizeof dp);
	dp[0][0] = 1;
	for(int i = 1; i <= n; i++){
		for(int j = 0; j <= i; j++){
			if(f[i] == 0 || f[i] == 1){
				dp[i][j + 1] = add(dp[i - 1][j], dp[i][j + 1]);
			}

			if((f[i] == 0 || f[i] == -1) && j >= 1){
				dp[i][j - 1] = add(dp[i][j - 1], dp[i - 1][j]);
			}
		}
	}
	return dp[n][0];
}

bool cmp(int i, int j){
	return p[i] < p[j];
}

char sol[N];
int main(){
	int n, m;
	ll k;
	cin >> n >> m >> k;
	for(int i = 1; i <= n + m - 1; i++) p[i] = 1e9, perm[i] = i;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			cin >> c[i][j];
			p[i + j - 1] = min(p[i + j - 1], c[i][j]);
		}
	}
	int n1 = n;
	n += m - 1;

	sort(perm + 1, perm + n + 1, cmp);

	for(int i = 1; i <= n; i++){
		int ind = perm[i];
		f[ind] = 1;
		ll x = findDP(n);
		if(x >= k){
			sol[ind] = '(';
		}
		else{
			f[ind] = -1;
			k -= x;
			sol[ind] = ')';
		}
	}

	for(int i = 1; i <= n1; i++){
		for(int j = 1; j <= m; j++)
			cout << sol[i + j - 1];
		cout << endl;
	}

}