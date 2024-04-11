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
using vvi = vector<vector<ll>>;
const ll mod = (119 * (1 << 23) + 1);
using oset = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;

void solve() {
	string t[2];
	string s;
	cin >> s;
	for(int i = 0; i < s.size(); i++)
		t[s[i]&1].pb(s[i]);
	int i, j;
	while(t[0].size()<s.size())t[0]+=char('9'+3);
	while(t[1].size()<s.size())t[1]+=char('9'+3);
	i = j = 0;
	for(int k = 0; k < s.size(); k++){
		cout << min(t[0][i], t[1][j]);
		if(min(t[0][i], t[1][j])==t[0][i])i++;
		else j++;
	}
	cout << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--)
		solve();
}