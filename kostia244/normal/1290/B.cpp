//#pragma GCC optimize("trapv")
//#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
using vi = vector<ll>;
using pi = pair<ll, ll>;
const int maxn = 2e5 + 55;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int t, a[maxn][26];
string s;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> s;
	for(int i = 0; i < s.size(); i++) {
		a[i][s[i]-'a']++;
		for(int j = 0; i && j < 26; j++) {
			a[i][j] += a[i-1][j];
		}
	}
	cin >> t;
	int l, r;
	while(t--) {
		cin >> l >> r, l--, r--;
		int ok = 0;
		for(int i = 0; i < 26; i++) {
			int g = a[r][i]-(l?a[l-1][i]:0);
			ok += g>0;
		}
		if(ok>2) ok = 1;
		else ok = 0;
		if(r-l==0) ok = 1;
		if(s[l]!=s[r]) ok = 1;
		cout << (ok?"Yes":"No") << "\n";
	}
}