#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,ssse3,fma")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
using vi = vector<ll>;
using pi = pair<ll, ll>;
using vpi = vector<pi>;
const int maxn = 222, mod = 1e9 + 7;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	string s;
	vector<int> l(300, -1);
	cin >> n >> s;
	s+="69";
	vector<array<int, 2>> a;
	for(int i = 0; i < n; i++) {
		if(s[i] != '?') {
			a.push_back({l[s[i]], i-1});
		}
		l[s[i]] = i;
	}
	a.push_back({l['0'], n-1});
	a.push_back({l['1'], n-1});
	sort(all(a));
//	for(auto &i : a) cout << i[0] << " " << i[1] << endl;
	ll t= 0 ;
	for(auto &i : a) t += i[0]-i[1];
	for(int x = 1; x <= n; x++) {
		vector<array<int, 2>> b;b.reserve(a.size());
		for(auto &i : a) if(i[0] <= i[1] && i[1]-i[0]>=x) b.push_back(i);
		a.swap(b);
		int l = -1, ans = 0;
		for(auto i : a) {
			i[0] = max(i[0], l);
			if(i[0] >= i[1]) continue;
			int t = (i[1]-i[0])/x;
			ans += t;
			l = i[0]+t*x;
		}
		cout << ans << ' ';
	}
}