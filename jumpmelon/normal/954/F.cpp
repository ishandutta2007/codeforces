#include <bits/stdc++.h>

using namespace std;

namespace program
{
	typedef long long big;

	const int L = 3, P = 1000000007;

	struct matrix
	{
		int A[L][L];
		matrix() { memset(A, 0, sizeof(A)); }
		int *operator [](int i) { return A[i]; }
		const int *operator [](int i) const { return A[i]; }
	};

	matrix unit()
	{
		matrix R;
		for(int i = 0; i < L; i++)
			R[i][i] = 1;
		return R;
	}

	matrix operator *(const matrix &A, const matrix &B)
	{
		matrix R;
		for(int i = 0; i < L; i++)
			for(int k = 0; k < L; k++)
				for(int j = 0; j < L; j++)
					R[i][j] = (int)((R[i][j] + (big)A[i][k] * B[k][j]) % P);
		return R;
	}

	void qpow(matrix &S, matrix X, big n)
	{
		while(n)
		{
			if(n & 1)
				S = S * X;
			X = X * X;
			n >>= 1;
		}
	}

	const int MAXN = 10000;
	int C[L];
	struct opt { big p; int a, f; } A[(MAXN << 1) + 10];

	inline bool operator <(const opt &a, const opt &b) { return a.p < b.p; }

	matrix build()
	{
		matrix R;
		if(!C[0])
			R[0][0] = R[1][0] = 1;
		if(!C[1])
			R[0][1] = R[1][1] = R[2][1] = 1;
		if(!C[2])
			R[1][2] = R[2][2] = 1;
		return R;
	}

	void work()
	{
		int n, t = 0;
		matrix R = unit();
		big m;
		scanf("%d%lld", &n, &m);
		A[t++] = {2, 0, 0};
		while(n--)
		{
			int a;
			big l, r;
			scanf("%d%lld%lld", &a, &l, &r);
			A[t++] = {l, a - 1, 1};
			A[t++] = {r + 1, a - 1, -1};
		}
		sort(A, A + t);
		A[t] = {m + 1, 0, 0};
		for(int i = 0; i < t; i++)
		{
			C[A[i].a] += A[i].f;
			qpow(R, build(), A[i + 1].p - A[i].p);
		}
		printf("%d\n", R[1][1]);
	}
}

int main()
{
	program::work();
	return 0;
}