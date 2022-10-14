#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx,popcnt")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
using namespace std;
using ll = long long;
using ld = long double;
const int maxn = 304, mod = 1e9 + 7, i2 = (mod+1)/2;
int main() {
	cin.tie(0)->sync_with_stdio(0);
	string s;
	cin >> s;
	if(count(all(s), 'a') == s.size()) {
		s.pop_back();
		s += 'z';
		cout << s << '\n';
		return 0;
	}
	int x = 0, y;
	while(s[x] == 'a') x++;
	y = x;
	while(y < s.size() && s[y] != 'a') y++;
	for(int i = x; i < y; i++) s[i]--;
	cout << s;
	
	return 0;
}