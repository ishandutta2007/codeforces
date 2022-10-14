#define _GLIBCXX_DEBUG
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
using vi = vector<ll>;
using pi = pair<ll, ll>;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, k;
	bitset<100> g;
	cin >> n >> k;
	char c;
	string s;
	cin >> s;
	for(int i = 0; i < k ;i++) cin >> c, g.set(c-'a');
	ll ans = 0, l = 0;
	for(auto i : s) {
		if(g.test(i-'a')) l++;
		else {
			ans += l*(l+1)/2;
			l = 0;
		}
	}
	ans += l*(l+1)/2;
	cout << ans;
}