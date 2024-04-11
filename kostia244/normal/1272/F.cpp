#define _GLIBCXX_DEBUG
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
using vi = vector<ll>;
using pi = pair<ll, ll>;
string s, t;
short dp[232][232][232];
char go[232][232][232];
#define nxt(i, s, X) (i+(i<s.size()&&s[i]==X))
void bt(int i, int j, int k) {
	if(i==s.size()&&j==t.size()) while(k--) cout << ')';
	else {
	cout << go[i][j][k];
	bt(nxt(i, s, go[i][j][k]), nxt(j, t, go[i][j][k]), k+(go[i][j][k]=='('?1:-1));
	}
}
short f(int i, int j, int bal) {
	if(bal < 0||bal>202) return 1<<12;
	if(dp[i][j][bal] != -1) return dp[i][j][bal];
	if(i==s.size()&&j==t.size()) return bal;
	dp[i][j][bal] = 1 + min(f(nxt(i, s, '('), nxt(j, t, '('), bal+1), f(nxt(i, s, ')'), nxt(j, t, ')'), bal-1));
	if(dp[i][j][bal]==1+f(nxt(i, s, '('), nxt(j, t, '('), bal+1)) go[i][j][bal] = '(';
	else go[i][j][bal] = ')';
	return dp[i][j][bal];
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	memset(dp, -1, sizeof dp);
	cin >> s >> t;
//	cout <<
			f(0, 0, 0);//<< "\n";
	bt(0, 0, 0);
}