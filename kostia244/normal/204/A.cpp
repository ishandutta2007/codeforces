#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
using namespace std;
using ll = long long;
using vi = vector<ll>;

ll solve(ll x) {
	if(x <= 0) return 0;
	if(x < 10) return x;
	if(x < 100) return 9+(x/11);
	string t = to_string(x);
	ll f = t[0]-'0';
	ll ans = 9, opt = stoll(t.substr(1, t.size()-2)), a2 = 18;
	for(int i = 3; i <= t.size(); i++) {
		ans*=10;
		if(i != t.size())
			a2+=ans;
		else {
			ans/=9;
			ans *= f-1;
			a2+=ans;
		}
	}
	a2 += opt + (t.back() >= t[0]);
	return a2;
}

int main() {
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	ll l, r;
	cin >> l >> r;
	cout << solve(r) - solve(l-1);
}