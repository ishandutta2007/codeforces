//Author: Heltion
//Date: 2019-06-06
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 240000;
constexpr LL mod = 998244353;
LL f[maxn], d[maxn];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cout<<fixed<<setprecision(12);
	int n;
	cin >> n;
	for(int i = 0; i <= n + 10; i += 1) f[i] = i ? f[i - 1] * i % mod : 1LL;
	for(int i = 1; i < n; i += 1){
		int u, v;
		cin >> u >> v;
		d[u] += 1;
		d[v] += 1;
	}
	LL ans = 1;
	for(int i = 1; i <= n; i += 1) ans = ans * f[d[i]] % mod;
	cout << ans * n % mod;
	return 0;
}