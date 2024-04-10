// Coding on my mac
// My mac doesn't have bits/stdc++.h
// http://codeforces.com/blog/entry/47152 looks helpful
// If only I could be bothered setting things up

#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;
typedef long long ll;

const ll MOD = 1000000007;

pair<int, int> all[2005];
ll fact[200005];
ll inv[200005];
ll dp[25][2005];
int n, m, k, s;

ll ncr(ll N, ll R)
{
	return (((fact[N]*inv[R])%MOD)*inv[N-R])%MOD;
}

ll slv(ll r, ll c)
{
	return ncr(r+c, r);
}

ll exp(ll b, ll e)
{
	if (e == 0) return 1;
	ll v = exp(b, e/2);
	v *= v; v %= MOD;
	if (e&1)
	{
		v *= b; v %= MOD;
	}
	return v;
}

int main()
{
	cin.sync_with_stdio(false); cin.tie(0);
	fact[0] = 1;
	for (int i = 1;i < 200005;i++) fact[i] = (fact[i-1]*i) % MOD;
	for (int i = 0;i < 200005;i++) inv[i] = exp(fact[i], MOD-2);
	cin >> n >> m >> k >> s;
	for (int i = 0;i < k;i++) cin >> all[i].first >> all[i].second;
	if (n == 1 && m == 1)
	{
		if (k == 0) cout << s << endl;
		else cout << s-s/2 << endl;
		return 0;
	}
	sort(all, all+k);
	if (all[k-1] != make_pair(n, m)) all[k++] = {n, m};
	else s -= s/2;
	if (all[0] != make_pair(1, 1)) all[k++] = {1, 1}, s *= 2;
	sort(all, all+k);

	dp[0][0] = 1;
	for (int i = 1;i < k;i++) for (int j = 1;j < 25;j++)
	{
		if (j == 1) dp[j][i] = slv(all[i].first-1, all[i].second-1);
		else
		{
			for (int prv = 0;prv < i;prv++) if (all[prv].second <= all[i].second)
			{
				dp[j][i] += (dp[j-1][prv]-dp[j][prv]+MOD)*slv(all[i].first-all[prv].first, all[i].second-all[prv].second);
				dp[j][i] %= MOD;
			}
		}
	}
	ll Q = slv(n-1, m-1), P = 0;
	for (int j = 1;j < 24;j++)
	{
		s -= s/2;
		ll v = dp[j][k-1]-dp[j+1][k-1]+MOD; v %= MOD;
		P += v*s;
		P %= MOD;
	}
	P += dp[24][k-1];
	P %= MOD;
	//cerr << P << ' ' << Q << endl;
	cout << (P*exp(Q, MOD-2))%MOD << '\n';
	return 0;
}