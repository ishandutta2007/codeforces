#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MOD 998244353
int di(int n, int m = MOD - 2)
{
	if (m == 0)
		return 1;
	if (m % 2)
		return di(n, m - 1) * n % MOD;
	int a = di(n, m / 2);
	return a * a % MOD;
}
int tree[1 << 22];
int treeN;
int query(int l, int r, int L=0, int R=treeN-1, int idx=1)
{
	if (l <= L && R <= r)
	{
		return tree[idx];
	}
	if (L > r || R < l)
	{
		return 0;
	}
	return query(l, r, L, (L + R) / 2, idx * 2) + query(l, r, (L + R) / 2 + 1, R, idx * 2 + 1);
}
void update(int idx, int changevalue)
{
	idx += treeN;
	tree[idx] += changevalue;
	while (idx != 1)
	{
		idx /= 2;
		tree[idx] = tree[idx * 2] + tree[idx * 2 + 1];
	}
}
int cntt[200100];
int fact[200100];
int t[200100];
signed main()
{
	int T, N, M;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M;
	for (treeN = 1; treeN < 200000; treeN *= 2);
	int i;
	fact[0] = 1;
	for (i = 0; i < N; i++)
	{
		int a;
		cin >> a;
		update(a, 1);
		fact[i + 1] += fact[i] * (i+1) % MOD;
	}
	for (i = 0; i < M; i++)
	{
		int a;
		cin >> a;
		cntt[a]++;
		t[i] = a;
	}
	int d = fact[N];
	for (i = 1; i <=200000; i++)
	{
		d *= di(fact[tree[i+treeN]]);
		d %= MOD;
	}
	
	int ans = 0;
	for (i = 0; i < M; i++)
	{
		if (i == N)
		{
			ans++;
			ans %= MOD;
			break;
		}
		d *= di(N - i);
		d %= MOD;
		ans += d*query(0,t[i]-1);
		ans %= MOD;
		int v = tree[treeN + t[i]];
		if (v == 0)
		{
			break;
		}
		d *= fact[tree[t[i] + treeN]];
		d %= MOD;
		update(t[i], -1);
		d *= di(fact[tree[t[i] + treeN]]);
		d %= MOD;
	}
	cout << ans;
}