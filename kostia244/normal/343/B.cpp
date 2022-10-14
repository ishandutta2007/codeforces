#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
const int maxn = 1<<19, mod = 1e9 + 7;

signed main() {
	cin.tie(0)->sync_with_stdio(0);
	string s;cin >> s;
	if(s.size()&1) return cout << "No\n", 0;
	string t= "f";
	for(auto &i : s) if(t.back() == i) t.pop_back();
		else t.push_back(i);
	cout << (t.size()==1 ? "Yes" : "No") << endl;
}