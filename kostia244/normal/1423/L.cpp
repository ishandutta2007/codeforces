#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math,inline")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")

#define private public

//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <bitset>
#include <unordered_map>
#include <map>

using namespace std;

#ifdef NeverBeRed
//#include "debug.h"
#else
#define debug(...) 9715
#endif
typedef long long ll;
typedef long double ld;
//typedef complex<ld> point;
#define F first
#define S second



const int R = 1000, mod1 = 1e9+7, mod2 = 1e9+13, SZ = 32;
const ll b1 = 2147483659, b2 = 2147483693;
ll get(const bitset<R> &b)
{
    int x1 = 0, x2 = 0;
    for (int i = 0; i < SZ; ++i)
    {
        x1 = ((ll)x1 * b1 + b._M_w[i]) % mod1;
        x2 = ((ll)x2 * b2 + b._M_w[i]) % mod2;
    }
    return ((ll)x1) << 30 | x2;
}

int main()
{
	#ifdef TurnRed
		freopen("a.in", "r", stdin);
		//freopen("a.out", "w", stdout);
	#endif

	ios_base::sync_with_stdio(0), cin.tie(0);

	int n, s, d;
	cin >> n >> s >> d;
	vector<bitset<R>> a(s);
	for (int i = 0, k, x; i < s; ++i)
	{
		cin >> k;
		while (k--) cin >> x, a[i][x-1] = 1;
	}

	int m = min(s, 10);
	vector<pair<int, bitset<R>>> f1(1<<m);

	for (int i = 1; i < 1<<m; ++i)
	{
		int p = i & -i;
		f1[i].F = f1[i ^ p].F + 1;
		f1[i].S = f1[i ^ p].S ^ a[__lg(p)];
	}

	unordered_map<ll, int> mp;
	mp[0] = 0;
	int m2 = s - m;
	vector<pair<int, bitset<R>>> f2(1<<m2);

	for (int i = 1; i < 1<<m2; ++i)
	{
		int p = i & -i;
		f2[i].F = f2[i ^ p].F + 1;
		f2[i].S = f2[i ^ p].S ^ a[m + __lg(p)];
		ll h = get(f2[i].S);
		if (!mp.count(h)) mp[h] = f2[i].F;
		else mp[h] = min(mp[h], f2[i].F);
	}

	for (int k, x; d--; )
	{
		cin >> k;
		bitset<R> b;
		while (k--) cin >> x, b[x-1] = 1;

		int ans = 1<<30;
		for (auto i : f1)
		{
			ll h = get(b ^ i.S);
			if (mp.count(h))
				ans = min(ans, i.F + mp[h]);
		}
		if (ans == 1<<30)
			ans = -1;
		cout << ans << "\n";
	}

	return 0;
}