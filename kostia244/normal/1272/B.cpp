#define _GLIBCXX_DEBUG
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
using vi = vector<ll>;
using pi = pair<ll, ll>;
void solve() {
	string s;
	map<char, int> cnt;
	cin >> s;
	for(auto i : s) cnt[i]++;
	int x = min(cnt['L'], cnt['R']);
	int y = min(cnt['U'], cnt['D']);
	if(!x) y = min(y, 1);
	if(!y) x = min(x, 1);
	cout << x+x+y+y << '\n';
	for(int i = 0; i < x; i++) cout << 'L';
	for(int i = 0; i < y; i++) cout << 'U';
	for(int i = 0; i < x; i++) cout << 'R';
	for(int i = 0; i < y; i++) cout << 'D';
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