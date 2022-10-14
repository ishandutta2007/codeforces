#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,ssse3,tune=native")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
using vi = vector<int>;
using pi = pair<int, int>;
using vpi = vector<pi>;
const int maxn = 1<<21;
const int mod = 998244353, inv2 = (mod+1)/2, rt = 733596141;
ll n;
void solve() {
	ll x, y;
	cin >> x >> y;
	ll cnte = 0;
	cnte = (n*(x-1) + 1)/2;
	if(x&1) cnte += (y+1)/2;
	else cnte += y/2;
	if((x+y)&1) cnte = n*(x-1) + y - cnte, cnte += ( n * n + 1)/2;//, cout << "h";
	cout << cnte << '\n';
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> n >> t;
	while(t--) solve();
}
// 20998782977