#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e7 + 100;
const int MOD = 1e9 + 7;

#define ll long long
#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second

ll n, f[MAXN], g[MAXN];
int main(){
	fast_io;
	cin >> n;
	f[0] = 1;
	g[0] = 0;
	for(int i = 1; i <= n; i++){
		f[i] = (g[i - 1] * 3) % MOD;
		g[i] = (f[i - 1] + g[i - 1] * 2) % MOD;
	}
	cout << f[n];
	return 0;
}