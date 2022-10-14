//#pragma GCC optimize("O2")
//#pragma GCC target("avx,avx2,sse,fma,tune=native")
//#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#include<bits/extc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
using vi = vector<ll>;
using pi = pair<ll, ll>;
const int maxn = 1e5 + 666, mlg = 18, mod =1e9 + 7;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int n, z, k, dir, dp[222][60];
string t;
void movek() {
	k+=dir;
	if(k==1||k==n) dir*=-1;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> z >> k;
	getline(cin, t);
	getline(cin, t);
	dir = (t=="to head"?-1:1);
	cin >> t;
	dp[0][z]=1;
	for(int i = 0; i < t.size(); i++) {
		int ok = 0;
		if(t[i]=='0') {
		for(int j = 1; j <= n; j++) {
			dp[i+1][j]|=dp[i][j];
			dp[i+1][j+1]|=dp[i][j];
			dp[i+1][j-1]|=dp[i][j];
		}
		dp[i+1][k] = 0;
		movek();
		dp[i+1][k] = 0;
		} else {
			for(int j = 1; j <= n; j++)
				dp[i+1][j] = 1;
			movek();
			dp[i+1][k] = 0;
		}
//		cout << i << ":::\n";
		for(int j = 1; j <= n; j++){
			ok|=dp[i+1][j];
//			if(dp[i+1][j])cout << j << " " << dp[i+1][j] << "\n";
		}
		if(!ok) return cout << "Controller " << i+1, 0;
	}
	cout << "Stowaway";
	return 0;
}