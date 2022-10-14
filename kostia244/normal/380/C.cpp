#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include<bits/stdc++.h>
#include<bits/extc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using vi = vector<ll>;
const ll mod = (119 * (1 << 23) + 1);
using oset = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string s;
	cin >> s;
	s = " " + s;
	vi st;
	vi ev[1000100];
	oset id;
	for(int i = 1; i < s.size(); i++) {
		if(s[i]==')') {
			if(st.empty()) continue;
			ev[st.back()].pb(i);
			id.insert(i);
			st.pop_back();
		} else
			st.push_back(i);
	}
	vector<pair<pair<int, int>, int>> qs;
	int q;
	cin >> q;
	qs.resize(q);
	int x = 0;
	for(auto &i : qs) cin >> i.first.first >> i.first.second, i.second = x++;
	sort(all(qs));
	int i = 0;
	vi ans(q, 0);
	for(int l = 1; i <qs.size() && l < s.size(); l++) {
		while(i<qs.size()&&qs[i].first.first==l) {
			ans[qs[i].second] = id.order_of_key(qs[i].first.second+1);
			i++;
		}
		for(auto i : ev[l]) id.erase(i);
	}
	for(auto i : ans)cout << (i<<1) << "\n";

}