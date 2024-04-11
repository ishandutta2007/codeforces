#include<bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
using vi = vector<ll>;
using pi = pair<ll, ll>;
const int D = 30, C = 2606, mod = 1e9 + 7;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int dp[C][C], cnt[26];
pi p[C][C];
string s;
int f(int l, int r) {
	if(dp[l][r]!=-1) return dp[l][r];
	if(l>r) return 0;
	if(l==r) return dp[l][r] = 1;
	tie(dp[l][r], p[l][r]) = max({pair<int, pi>{f(l+1, r), pi{l+1, r}}, pair<int, pi>{f(l, r-1), pi{l, r-1}},pair<int, pi>{f(l+1,r-1)+2*(s[l]==s[r]),  pi{l+1, r-1}}});
	return dp[l][r];
}
string t;
void rec(int l, int r) {
	if(l>r) return;
	if((l!=r)&&(p[l][r].first==l||p[l][r].second==r)) {
		rec(p[l][r].first, p[l][r].second);
		return;
	}
	t+=s[l];
	rec(l+1, r-1);
	if(l!=r)
	t+=s[l];
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	memset(dp, -1, sizeof dp);
	cin >> s;
	if(s.size()<2600) {
		int xx = f(0, s.size()-1);
		rec(0, s.size()-1);
		if(t.size() > 100) {
			for(int i = 0; i < 50; i++)
				cout << t[i];
			for(int i = 50; i--;)
				cout << t[i];
			return 0;
		} else
		cout << t;
		return 0;
	}
	for(int i = 0; i < s.size(); i++) {
		if(++cnt[s[i]-'a']==100) {
			for(int j = 0; j < 100; j++)
				cout << s[i];
			return 0;
		}
	}
}