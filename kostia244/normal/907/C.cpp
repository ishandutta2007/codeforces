#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
using ld = long double;
using vi = vector<ll>;
using vvi = vector<vi>;
const ll mod = 998244353;

int main() {
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	bitset<26> xbet((1<<26) - 1);
	int n;
	cin >> n;
	char c;
	string t;
	int ans = 0;
	for(int i = 0; i+1 < n; i++) {
		cin >> c >> t;
		if(xbet.count() == 1)
			ans += c!='.';
		if(c == '?') {
			xbet.set(t[0]-'a', 0);
			continue;
		}
		bitset<26> ybet;
		if(xbet.count() == 1) {
		} else {
		if(c == '!') {
		for(auto i : t) ybet.set(i-'a');
		} else {
			ybet = (1<<26) - 1;
			for(auto i : t) ybet.set(i-'a', 0);
		}
		xbet&=ybet;
		}
	}
	cout << ans;
}