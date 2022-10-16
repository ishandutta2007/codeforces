#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MOD 998244353
int arr[100100];
int psuml[100100];
int psumr[100100];
int pw(int n, int k = MOD - 2)
{
	if (k == 0)
		return 1;
	if (k % 2)
	{
		return pw(n, k - 1) * n % MOD;
	}
	int a = pw(n, k / 2);
	return a * a % MOD;
}
int fact[100100];
int rev[100100];
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	int i;
	fact[0] = 1;
	rev[0] = 1;
	for (i = 1; i <= 100010; i++)
	{
		fact[i] = fact[i - 1] * i % MOD;
		rev[i] = pw(fact[i]);
	}
	while (T--)
	{
		int N;
		cin >> N;
		int i;
		int s = 0;
		for (i = 0; i < N; i++)
		{
			cin >> arr[i];
			s += arr[i];
			psuml[i] = arr[i];
			if (i)
			{
				psuml[i] += psuml[i - 1];
			}
		}
		for (i = 1; i < N; i++)
		{
			psumr[i] = s - psuml[i - 1];
		}
		psumr[0] = s;
		int ans = 1;
		int e = N-1;
		i = 0;
		while(i<N-1)
		{
			if (psuml[i] * 2 > s)
				break;
			if (psuml[i] * 2 == s)
			{
				ans *= 2;
				ans %= MOD;
				i++;
				continue;
			}
			while (psumr[e] < psuml[i])
			{
				e--;
			}
			if (psumr[e] == psuml[i])
			{
				int ni = i;
				int ne = e;
				while (psuml[ni] == psuml[i])
					ni++;
				while (psumr[ne] == psumr[e])
					ne--;
				int v = ni - i;
				int v2 = e - ne;
				int va = 0;
				int j;
				for (j = 0; j <= min(v,v2); j++)
				{
					va += (fact[v] * rev[j] % MOD * rev[v - j] % MOD) * (fact[v2] * rev[j] % MOD * rev[v2 - j] % MOD);
					va %= MOD;
				}
				ans *= va;
				ans %= MOD;
				i = ni;
				e = ne;
				if (ni >= ne)
				{
					break;
				}
			}
			else
			{
				i++;
			}
		}
		cout << ans << '\n';
	}
}