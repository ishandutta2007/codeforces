#include<bits/stdc++.h>
using namespace std;
void solve() {
	string s;
	cin >> s;
	map<char, int> f;
	for(auto i : s) f[i]++;
	char m = 'R';
	f['R'] += 0;
	for(auto i : f) {
		if(i.second > f[m]) m = i.first;
	}
	map<char, char> win;
	win['R'] = 'P';
	win['P'] = 'S';
	win['S'] = 'R';
	cout << string(s.size(), win[m]) << '\n';
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t;
	cin >> t;
	while(t--) solve();
}