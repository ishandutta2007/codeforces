#pragma comment(linker, "/stack:200000000")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#include<bits/extc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vector<ll>>;
const ll mod = 696969569;
using oset = tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
struct qq {
	int l, r, i;
	bool operator<(const qq& x) const {
		return r<x.r;
	}
};
const int C = 350;
int n, q, a[100100], b[100100], sz = 0, realvl[100100], ans[100100], freq[100100];
vector<qq> queries[400];
map<int, int> x;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> q;
	for(int t, i = 1; i <= n; i++) {
		cin >> a[i];
		if(!x.count(a[i])) x[a[i]] = sz, realvl[sz] = a[i], sz++;
		a[i] = x[a[i]];
	}
	for(int l, r, i = 0; i < q; i++) {
		cin >> l >> r;
		queries[l/C].pb({l, r, i});
	}
	for(int i = 0; i < C; i++) {
		memset(freq, 0, sizeof freq);
		sort(all(queries[i]));
		int cur = 0;
		int l = max(1, i*C), r;r=l-1;
		for(auto z : queries[i]) {
			while(l < z.l) {
				if(freq[a[l]]==realvl[a[l]]) cur--;
				freq[a[l]]--;
				if(freq[a[l]]==realvl[a[l]]) cur++;
				l++;
			}
			while(l > z.l) {
				l--;
				if(freq[a[l]]==realvl[a[l]]) cur--;
				freq[a[l]]++;
				if(freq[a[l]]==realvl[a[l]]) cur++;
			}
			while(r < z.r) {
				r++;
				if(freq[a[r]]==realvl[a[r]]) cur--;
				freq[a[r]]++;
				if(freq[a[r]]==realvl[a[r]]) cur++;
			}
			ans[z.i] = cur;
		}
	}
	for(int i = 0; i < q; i++)
		cout << ans[i] << "\n";
}