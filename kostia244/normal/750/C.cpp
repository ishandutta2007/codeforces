#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2")
#include<bits/stdc++.h>
#define pow loli
#define all(x) x.begin(), x.end()
#define pb push_back
using namespace std;
using ll = long long;
using ld = long double;
const int maxn = 1<<20;
ll n, loM = -(1ll<<30), loX = 1<<30, d[maxn], c[maxn];
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	ll cur = 0;
	for(int i = n; i--;) {
		cin >> c[i] >> d[i];
		if(d[i] == 1) loM = max(loM, 1900-cur);//min allowed bias
		else loX = min(loX, 1899-cur);//max allowed bias
		cur += c[i];
	}
	if(loX < loM) return cout << "Impossible\n", 0;
	cur = loX;
	for(int i = n; i--;) {
		cur += c[i];
	}
	
	if(cur > (1ll<<27)) return cout << "Infinity\n", 0;
	cout << cur << '\n';
	return 0;
}