#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include<bits/stdc++.h>
#include<bits/extc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using vi = vector<ll>;
const ll mod = (119*(1<<23) + 1);
int x[100100],l;
vi vis, a, ans;
vi cur;

void go(int x) {
	if(vis[x]) return;
	vis[x] = 1;
	l++;
	cur.pb(x);
	go(a[x]);
}

void solve() {
	int n;
	cin >> n;
	a.assign(n, 0);
	for(auto &i : a) cin >> i, i--;
	vis.assign(n, 0);
	ans.assign(n, 0);
	for(int i = 0; i < n; i++) {
		if(!vis[i]) {
			l=0;
			go(i);
			for(auto j : cur) ans[j] = l;
			cur.clear();
		}
	}
	for(auto i : ans) cout << i << " ";
	cout << '\n';
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while(t--) solve();
}