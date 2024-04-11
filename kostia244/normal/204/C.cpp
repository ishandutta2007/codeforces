#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
using namespace std;
using ll = long long;
using vi = vector<ll>;
const int MAXN = (1 << 18);

template <class T>
struct fenwick
{
	ll sz;
	T tr[MAXN];

	void init(int n)
	{
		sz = n + 1;
		memset(tr, 0, sizeof(tr));
	}

	T query(int idx)
	{
		T ans = 0;
		for(; idx >= 1; idx -= (idx & -idx))
			ans += tr[idx];
		return ans;
	}

	void update(ll idx, T val)
	{
		if(idx <= 0) return;
		for(; idx <= sz; idx += (idx & -idx))
			tr[idx] += val;
	}

	T query(int l, int r) { return query(r) - query(l - 1); }
};
int main() {
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	fenwick<ll> dp[2][26];
	ll n;
	string s, t;//change n back to normal!!
	cin >> n >> s >> t;
	s = " " + s;
	t = " " + t;
	for(ll i = 0; i < 26; i++) {
		dp[0][i].init(n);
		dp[1][i].init(n);
	}
	for(ll i = 1; i < s.size(); i++) {
		dp[0][s[i]-'A'].update(i, (ll)s.size()-i);
		dp[1][s[i]-'A'].update(i, i);
	}
	long double a = 0, b = 0;
	for(ll i = 1; i <= n; i++) b += i*1ll*i;
	for(ll i = 1; i < (ll)t.size(); i++) {
		ll x = i*1ll*dp[0][t[i]-'A'].query(i+1, n);
		x += (n-i+1)*1ll*dp[1][t[i]-'A'].query(1, i);
		a += (long double)x / b;
	}
	cout << fixed << setprecision(20) << a;
}