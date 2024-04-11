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
	string s;
	cin >> s;
	s+='\0';
	char p = s[0];
	map<char, int> x;
	int l = 1;
	for(int i = 1; i < s.size(); i++) {
		if(p!=s[i]) {
			x[p]|=1<<(l&1);
			l=0;
		}
		p=s[i];
		l++;
	}
	for(auto i : x)
		if((i.second&2)&&i.first!='\0')
			cout << i.first;
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