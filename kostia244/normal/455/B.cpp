//#pragma GCC optimize("trapv")
//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")
//#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;
using ll = long long;
using vi = vector<int>;
using pi = pair<int, int>;
using vpi = vector<pi>;
const int maxn = 1e5 + 5;
using oset = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;
int t[maxn][26], sz = 1;
void add(string &s) {
	int cur = 0;
	for(auto i : s) {
		i-='a';
		if(!t[cur][i]) t[cur][i] = sz++;
		cur = t[cur][i];
	}
}
pi dfs(int v = 0) {
	pi w = {0, 0};
	int LI = 1;
	for(int i = 0; i < 26; i++) {
		if(t[v][i]) {
			LI = 0;
			pi z = dfs(t[v][i]);
			if(!z.second)
				w.second = 1;
			if(!z.first)
				w.first = 1;
		}
	}
	if(LI)
		w.first = 1;
	return w;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll n, k;
	cin >> n >> k;
	string s;
	while(n--) {
		cin >> s;
		add(s);
	}
	pi t = dfs();
	if(t.second) {
		if(t.first) cout << "First";
		else {
		if(k&1) cout << "First";
		else cout << "Second";
		}
	} else {
		cout << "Second";
	}
}