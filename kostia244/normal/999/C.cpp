#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma,tune=native")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
#include <x86intrin.h>
#define pb push_back
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using vi = vector<ll>;
const int maxn = 4003, mod = 998244353;
void solve() {
	int n, k;
	string s;
	cin >> n >> k >> s;
	set<pi> a;
	for(int i = 0; i < s.size(); i++) a.insert({s[i]-'a', i});
	while(k--) a.erase(a.begin());
	for(int i = 0; i < s.size(); i++) if(a.count({s[i]-'a', i})) cout << s[i];
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
//	cin >> t;
	t = 1;
	while(t--) solve();
}