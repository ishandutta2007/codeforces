#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
//#include<bits/extc++.h>
//using namespace __gnu_pbds;
//using namespace __gnu_cxx;
#define pb push_back
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
using vi = vector<int>;
using pi = pair<ll, ll>;
using vpi = vector<pi>;
const int maxn = 1e5 + 33, mlg = 17, mod = 1e9 + 7;
void solve() {
	string s;
	cin >> s;
	if(s.size()&1) {
		string t;
		while(t.size()+2 < s.size()) t+="99";
		cout <<t << "\n";
		return;
	}
	int pref = 0;
	set<char> cur;
	for(int i = 0;i < s.size(); i++) {
		if(cur.size()+i<=s.size()&&((!cur.empty()&&*cur.begin()<s[i])||(cur.size()+i+2<=s.size()&&s[i]>'0'))) {
//			cout << i << " " << (!cur.empty()?*cur.begin():'0') << " " << s[i] << " " << (!cur.empty()&&*cur.begin()<s[i]) << (cur.size()+i+2<=s.size()&&s[i]>'0') << "\n";
			pref = i;
		}
		if(!cur.insert(s[i]).second) cur.erase(s[i]);
	}
	cur.clear();
	for(int i = 0;i < pref; i++)
		if(!cur.insert(s[i]).second) cur.erase(s[i]);
	if(pref==0&&s[pref]=='1') {
		string t;
		while(t.size()+2 < s.size()) t+="99";
		cout <<t << "\n";
		return;
	}
	vi add;
	if(pref+cur.size()+2<=s.size()&&!cur.count(s[pref]-1)) add.pb(s[pref]-'0'-1),add.pb(s[pref]-'0'-1);//, cout << "flag";
//	cout << add.size() << "add ";
	for(auto i : cur) add.pb(i-'0');
//	cout << add.size() << "add ";
	while(add.size()+pref+2 <= s.size()) {
		add.pb(9),add.pb(9);//, cout << "flag";
	}
	sort(all(add));
	int z = 0;
	while(z < add.size() && add[z] < s[pref]-'0') z++;
	z--;
	while(z > 0)
		swap(add[z], add[z-1]), z--;
	string t = s.substr(0, pref);
	t.pb(add[0]+'0');
	for(int i = add.size(); i-->1;)
		t.pb(add[i]+'0');
	cout << t << "\n";
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while(t--) solve();
}