#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef long double ld;
typedef pair<ll, ll> pl;
typedef vector<ll> vl;

#define G(x) ll x; cin >> x;
#define F(i, l, r) for(ll i = l; i < (r); i++)
#define all(a) begin(a), end(a)
#define K first
#define V second

string compress(string s) {
	string ans = ""; ll bct = 0;
	for(char c : s) {
		if(c - 'B') ans.push_back(c); else bct++;
		if(ans.size() > 1 && ans.back() == ans[ans.size() - 2]) ans.pop_back(), ans.pop_back();
	}
	if(bct & 1) ans.push_back('B');
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	G(tc) while(tc--) {
		string u, v;
		cin >> u >> v;
		u = compress(u), v = compress(v);
		cout << (u == v ? "YES\n" : "NO\n");
	}
}