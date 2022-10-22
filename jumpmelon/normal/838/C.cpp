#include <bits/stdc++.h>

using namespace std;

namespace jumpmelon
{
	typedef long long big;

	const int MAXN = 250000, MAXM = 18;
	int p, m, Fac[MAXN + 1], InvFac[MAXN + 1];
	int Cnt[(1 << MAXM) + 3], F[MAXM][(1 << MAXM) + 3];

	int inv(int x) { return x == 1 ? 1 : int(big(p - p / x) * inv(p % x) % p); }

	void FWT(int *X)
	{
		for (int i = 1; i < (1 << m); i <<= 1)
			for (int j = 0; j < (1 << m); j += i << 1)
				for (int k = 0; k < i; k++)
				{
					int x0 = X[j + k], x1 = X[i + j + k];
					X[j + k] = (x0 + x1) % p;
					X[i + j + k] = (x0 + p - x1) % p;
				}
	}

	void IFWT(int *X)
	{
		int inv_2 = (p + 1) >> 1;
		for (int i = 1; i < (1 << m); i <<= 1)
			for (int j = 0; j < (1 << m); j += i << 1)
				for (int k = 0; k < i; k++)
				{
					int x0 = X[j + k], x1 = X[i + j + k];
					X[j + k] = int(big(x0 + x1) * inv_2 % p);
					X[i + j + k] = int(big(x0 + p - x1) * inv_2 % p);
				}
	}

	vector<int> operator*(const vector<int> &A, const vector<int> &B)
	{
		vector<int> R(m);
		for (int i = 0; i < m; i++)
			for (int j = 0; i + j < m; j++)
				R[i + j] = int((R[i + j] + (big)A[i] * B[j]) % p);
		return R;
	}

	vector<int> qpow(vector<int> X, int k)
	{
		vector<int> S(m);
		S[0] = 1;
		while (k)
		{
			if (k & 1)
				S = S * X;
			X = X * X;
			k >>= 1;
		}
		return S;
	}

	void work()
	{
		int n, k, tot = 1;
		scanf("%d%d%d", &n, &k, &p);
		for (int i = 1; i <= n; i++)
			tot = int((big)tot * k % p);
		if (n & 1)
			return void(printf("%d\n", tot));
		while (n >= (1 << m))
			m++;
		Fac[0] = 1;
		for (int i = 1; i <= n; i++)
			Fac[i] = int((big)Fac[i - 1] * i % p);
		InvFac[n] = inv(Fac[n]);
		for (int i = n; i >= 1; i--)
			InvFac[i - 1] = int((big)InvFac[i] * i % p);
		for (int i = 0; i < (1 << m); i++)
			Cnt[i] = Cnt[i >> 1] + (i & 1);
		for (int i = 0; i <= n; i++)
			F[Cnt[i]][i] = InvFac[i];
		for (int i = 0; i < m; i++)
			FWT(F[i]);
		for (int i = 0; i < (1 << m); i++)
		{
			vector<int> X(m);
			for (int j = 0; j < m; j++)
				X[j] = F[j][i];
			vector<int> R = qpow(X, k);
			for (int j = 0; j < m; j++)
				F[j][i] = R[j];
		}
		IFWT(F[Cnt[n]]);
		printf("%d\n", int((tot + p - (big)Fac[n] * F[Cnt[n]][n] % p) % p));
	}
}

int main()
{
	jumpmelon::work();
	return 0;
}