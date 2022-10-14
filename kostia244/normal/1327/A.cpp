//#pragma GCC optimize("trapv")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC target("avx,avx2,sse,sse2,fma,tune=native")
#include<bits/stdc++.h>
#define rall(x) x.rbegin(), x.rend()
#define all(x) x.begin(), x.end()
#define pb push_back
#include <x86intrin.h>
#define pb push_back
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using vi = vector<ll>;
using ld = long double;
const int maxn = 2e6 + 55, mod = 1000000007, i2 = (mod+1)/2;
void solve() {
	ll n, k;
	cin >> n >> k;
	if((k^n)&1) {cout << "NO\n"; return;}
	if(n<k*k) {cout << "NO\n"; return;}
	cout << "YES\n";
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	//t = 1;
	while(t--) solve();
}