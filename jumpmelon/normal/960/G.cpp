#include <bits/stdc++.h>

using namespace std;

namespace jumpmelon
{
	typedef long long big;

	const int P = 998244353, INV_3 = (P + 1) / 3;
	const int MAXN = 100000, MAXL = 1 << 19;
	int Fac[MAXN + 1], InvFac[MAXN + 1];

	int inv(int x) { return x == 1 ? 1 : int(big(P - P / x) * inv(P % x) % P); }

	int qpow(int x, int n)
	{
		int s = 1;
		while (n)
		{
			if (n & 1)
				s = int((big)s * x % P);
			x = int((big)x * x % P);
			n >>= 1;
		}
		return s;
	}

	void NTT(int f, int *X, int n)
	{
		static int Rev[MAXL + 3], prev;
		if (prev != n)
		{
			prev = n;
			for (int i = 1; i < n; i++)
				Rev[i] = (Rev[i >> 1] >> 1) | ((i & 1) ? (n >> 1) : 0);
		}
		for (int i = 1; i < n; i++)
			if (i < Rev[i])
				swap(X[i], X[Rev[i]]);
		for (int l = 1; l < n; l <<= 1)
		{
			int wn = qpow(f == 1 ? 3 : INV_3, (P - 1) / (l << 1));
			for (int i = 0; i < n; i += l << 1)
				for (int j = 0, w = 1; j < l; j++, w = int((big)w * wn % P))
				{
					int x0 = X[i + j], x1 = int((big)w * X[i + l + j] % P);
					X[i + j] = (x0 + x1) % P;
					X[i + l + j] = (x0 + P - x1) % P;
				}
		}
		if (f == -1)
			for (int i = 0, v = inv(n); i < n; i++)
				X[i] = int((big)X[i] * v % P);
	}

	void mul(int *R, const int *FA, const int *FB, int n, int m)
	{
		static int A[MAXL + 3], B[MAXL + 3], C[MAXL + 3];
		int t = 1;
		while (t < n + m - 1)
			t <<= 1;
		memcpy(A, FA, sizeof(int[n]));
		memcpy(B, FB, sizeof(int[m]));
		memset(A + n, 0, sizeof(int[t - n]));
		memset(B + m, 0, sizeof(int[t - m]));
		NTT(1, A, t);
		NTT(1, B, t);
		for (int i = 0; i < t; i++)
			C[i] = int((big)A[i] * B[i] % P);
		NTT(-1, C, t);
		memcpy(R, C, sizeof(int[n + m - 1]));
	}

	void mov(int *R, const int *F, int d, int n)
	{
		static int A[MAXN + 1], B[MAXN + 1], C[MAXN + 1];
		for (int i = 0; i < n; i++)
			A[n - i - 1] = int((big)Fac[i] * F[i] % P);
		for (int i = 0, v = 1; i < n; i++, v = int((big)v * d % P))
			B[i] = int((big)v * InvFac[i] % P);
		mul(C, A, B, n, n);
		for (int i = 0; i < n; i++)
			R[i] = int((big)C[n - i - 1] * InvFac[i] % P);
	}

	void solve(int *R, int n)
	{
		if (n == 0)
			R[0] = 1;
		else if (n & 1)
		{
			solve(R, n - 1);
			for (int i = n; i >= 1; i--)
				R[i] = int((R[i - 1] + big(n - 1) * R[i]) % P);
			R[0] = int(big(n - 1) * R[0] % P);
		}
		else
		{
			static int T[MAXL + 3];
			solve(R, n >> 1);
			mov(T, R, n >> 1, (n >> 1) + 1);
			mul(R, R, T, (n >> 1) + 1, (n >> 1) + 1);
		}
	}

	void work()
	{
		static int F[MAXL + 3];
		int n, a, b;
		scanf("%d%d%d", &n, &a, &b);
		int k = (--a) + (--b);
		if (k > --n)
			return void(puts("0"));
		Fac[0] = 1;
		for (int i = 1; i <= n; i++)
			Fac[i] = int((big)Fac[i - 1] * i % P);
		InvFac[n] = inv(Fac[n]);
		for (int i = n; i >= 1; i--)
			InvFac[i - 1] = int((big)InvFac[i] * i % P);
		solve(F, n);
		printf("%d\n", int((big)F[k] * Fac[k] % P * InvFac[a] % P * InvFac[b] % P));
	}
}

int main()
{
	jumpmelon::work();
	return 0;
}