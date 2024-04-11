#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
using namespace std;
using ll = long long;
using vi = vector<ll>;
using pi = pair<int, int>;
const int maxn = 2e3 + 55, mod = 1e9 + 7;
string s;
vi a, b;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> s;
	vi res;
	for(int i = 0; i < s.size(); i++) {
		if(s[i]=='(') a.pb(i);
		else b.pb(i);
	}
	reverse(all(b));
	int j = -1;
	for(int i = 0; i < min(a.size(), b.size()); i++) {
		if(a[i]<b[i]) j = i;
	}
	for(int i = 0; i <= j; i++) res.pb(a[i]), res.pb(b[i]);
	sort(all(res));
	if(j==-1) return cout << 0, 0;
	cout << 1 << '\n' << res.size() << "\n";
	for(auto i : res) cout << 1+i << " ";
}