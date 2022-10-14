#pragma GCC optimize("Ofast")
#pragma GCC optimize("avx,avx2,sse,sse2,fma")
#include<bits/stdc++.h>
#include<bits/extc++.h>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
#define pb push_back
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long ;
using vi = vector<ll>;
using pi = pair<ll, ll>;
const int maxn = 2e5 + 33;
using oset = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string s;
	cin >> s;
	set<int> fr[2];
	vi nxt(s.size(), -1);
	int pos = 0;
	for(auto i : s) {
		if(i=='1') {
			if(fr[0].empty()) {
				return cout << -1, 0;
			}
			nxt[*fr[0].begin()] = pos;
			fr[0].erase(fr[0].begin());
			fr[1].insert(pos);
		} else {
			if(!fr[1].empty()) {
				nxt[*fr[1].begin()] = pos;
				fr[1].erase(fr[1].begin());
			}
			fr[0].insert(pos);
		}
		pos++;
	}
	for(int i = 0; i < s.size(); i++) {
		if(s[i]=='1'&&nxt[i] == -1) {
			return cout << -1, 0;
		}
	}
	vi vis(s.size(), 0);
	vector<vi> a;
	for(int i = 0; i < s.size(); i++) {
		if(vis[i]) continue;
		vi t;
		int s = i;
		while(s!=-1) {
			vis[s] = 1;
			t.pb(s);
			s = nxt[s];
		}
		a.pb(t);
	}
	cout << a.size() << "\n";
	for(auto &i : a) {
		cout << i.size() << " ";
		for(auto &j : i) cout << j+1 << " ";cout << "\n";
	}
}