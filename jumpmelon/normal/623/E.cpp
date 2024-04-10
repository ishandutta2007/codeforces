#include <bits/stdc++.h>

using namespace std;

namespace jumpmelon
{
	typedef long long big;
	typedef long double ld;

	const int MAXM = 30000, MAXL = (1 << 16) + 3, P = 1000000007;
	const ld PI = acos(-1.0L);
	int kc, Bin[MAXM + 1], Fac[MAXM + 1], InvFac[MAXM + 1];

	int inv(int x) { return x == 1 ? 1 : int(big(P - P / x) * inv(P % x) % P); }

	struct comp
	{
		ld r, i;
		comp() {}
		comp(ld a_r, ld a_i = 0) : r(a_r), i(a_i) {}
		comp operator/(ld v) const { return comp(r / v, i / v); }
		comp &operator/=(ld v) { return *this = *this / v; }
	};

	inline comp operator+(const comp &a, const comp &b) { return comp(a.r + b.r, a.i + b.i); }
	inline comp operator-(const comp &a, const comp &b) { return comp(a.r - b.r, a.i - b.i); }
	inline comp operator*(const comp &a, const comp &b) { return comp(a.r * b.r - a.i * b.i, a.r * b.i + a.i * b.r); }
	inline comp &operator*=(comp &a, const comp &b) { return a = a * b; }

	void FFT(int f, comp *X, int n)
	{
		static int prev, Rev[MAXL];
		if (prev != n)
		{
			prev = n;
			for (int i = 1; i < n; i++)
				Rev[i] = (Rev[i >> 1] >> 1) | ((i & 1) * (n >> 1));
		}
		for (int i = 0; i < n; i++)
			if (i < Rev[i])
				swap(X[i], X[Rev[i]]);
		for (int i = 1; i < n; i <<= 1)
		{
			comp wn(cos(PI / i), f * sin(PI / i));
			for (int j = 0; j < n; j += i << 1)
			{
				comp w = 1;
				for (int k = 0; k < i; k++, w *= wn)
				{
					comp x0 = X[j + k], x1 = w * X[i + j + k];
					X[j + k] = x0 + x1;
					X[i + j + k] = x0 - x1;
				}
			}
		}
		if (f == -1)
			for (int i = 0; i < n; i++)
				X[i] /= n;
	}

	void get(comp *A1, comp *A0, const int *A, int n, int t)
	{
		static comp T[MAXL];
		for (int i = 0; i < n; i++)
			T[i] = comp(A[i] >> 15, A[i] & 32767);
		for (int i = n; i < t; i++)
			T[i] = 0;
		FFT(1, T, t);
		for (int i = 0; i < t; i++)
		{
			int j = (t - i) & (t - 1);
			A1[i] = comp((T[i].r + T[j].r) / 2, (T[i].i - T[j].i) / 2);
			A0[i] = comp((T[i].i + T[j].i) / 2, (T[j].r - T[i].r) / 2);
		}
	}

	void mul(int *R, const int *A, const int *B, int n, int m, int rlen)
	{
		static comp A1[MAXL], A0[MAXL], B1[MAXL], B0[MAXL], R1[MAXL], R0[MAXL];
		int t = 1;
		while (t < n + m - 1)
			t <<= 1;
		get(A1, A0, A, n, t);
		if (A != B)
		{
			get(B1, B0, B, m, t);
			for (int i = 0; i < t; i++)
			{
				R1[i] = A1[i] * B1[i] + A0[i] * B0[i] * comp(0, 1);
				R0[i] = A0[i] * B1[i] + A1[i] * B0[i];
			}
		}
		else
			for (int i = 0; i < t; i++)
			{
				R1[i] = A1[i] * A1[i] + A0[i] * A0[i] * comp(0, 1);
				R0[i] = A0[i] * A1[i] + A1[i] * A0[i];
			}
		FFT(-1, R1, t);
		FFT(-1, R0, t);
		for (int i = 0; i < n + m - 1 && i < rlen; i++)
			R[i] = int((((big(R1[i].r + 0.5) % P) << 30) + ((big(R0[i].r + 0.5) % P) << 15) + big(R1[i].i + 0.5)) % P);
	}

	void solve(int *R, int n)
	{
		static int A[MAXM + 1], B[MAXM + 1];
		if (n == 0)
			R[0] = 1;
		else if (n & 1)
		{
			solve(R, n - 1);
			for (int i = 0, t = 1; i <= kc; i++, t = (t << 1) % P)
			{
				A[i] = int((big)R[i] * InvFac[i] % P * t % P);
				B[i] = i ? InvFac[i] : 0;
			}
			mul(R, A, B, kc + 1, kc + 1, kc + 1);
			for (int i = 0; i <= kc; i++)
				R[i] = int((big)R[i] * Fac[i] % P);
		}
		else
		{
			solve(R, n >> 1);
			for (int i = 0, t = 1; i <= kc; i++, t = int((big)t * Bin[n >> 1] % P))
			{
				A[i] = int((big)R[i] * InvFac[i] % P * t % P);
				B[i] = int((big)R[i] * InvFac[i] % P);
			}
			mul(R, A, B, kc + 1, kc + 1, kc + 1);
			for (int i = 0; i <= kc; i++)
				R[i] = int((big)R[i] * Fac[i] % P);
		}
	}

	void work()
	{
		static int R[MAXM + 1];
		big n;
		scanf("%lld%d", &n, &kc);
		if (n > kc)
			return void(puts("0"));
		Bin[0] = 1;
		for (int i = 1; i <= kc; i++)
			Bin[i] = (Bin[i - 1] << 1) % P;
		Fac[0] = 1;
		for (int i = 1; i <= kc; i++)
			Fac[i] = int((big)Fac[i - 1] * i % P);
		InvFac[kc] = inv(Fac[kc]);
		for (int i = kc; i >= 1; i--)
			InvFac[i - 1] = int((big)InvFac[i] * i % P);
		solve(R, int(n));
		int ans = 0;
		for (int i = 0; i <= kc; i++)
			ans = int((ans + (big)R[i] * Fac[kc] % P * InvFac[i] % P * InvFac[kc - i]) % P);
		printf("%d\n", ans);
	}
}

int main()
{
	jumpmelon::work();
	return 0;
}