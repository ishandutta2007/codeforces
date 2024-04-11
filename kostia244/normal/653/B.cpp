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
const int maxn = 1e6 + 30;
using oset = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string s = "";
	int n, m;
	cin >> n >> m;
	map<string, string> t;
	string A, B;
	for(int i = 0; i < m; i++) {
		cin >>A >> B;
		t[A]=B;
	}
	int ans = 0;
	for(int i = 0; i < n; i++) s+='a';
	while(true) {
		string y = s;
		int ok = 1;
		while(y.size()>1&&ok) {
			string zz = y.substr(0, 2);
			if(!t.count(zz)) ok = 0;
			else {
				y = t[zz]+y.substr(2);
			}
		}
		if(y=="a") ans++;
		int add = 1;
		for(int i = 0; add&&i<s.size(); i++) {
			if(++s[i]>'f') s[i] = 'a';
			else add=0;
		}
		if(add) break;
	}
	cout << ans << "\n";
}