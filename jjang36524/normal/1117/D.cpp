#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
#define int long long
#define MOD 1000000007
struct matrix
{
	int N, M;
	vector<vector<int>>x;
	void init(int n, int m)//create a N*M matrix
	{
		N = n;
		M = m;
		vector<int>ne(M, 0);
		vector<vector<int>>nne(N, ne);
		x = nne;
	}
};
matrix mul(matrix a, matrix b)// multiplying the matrix 
{
	int i, j, k;
	matrix ne;
	ne.init(a.N, b.M);
	for (i = 0; i < a.N; i++)
	{
		for (j = 0; j < a.M; j++)
		{
			for (k = 0; k < b.M; k++)
			{
				ne.x[i][k] += a.x[i][j] * b.x[j][k];
				ne.x[i][k] %= 1000000007;
			}
		}
	}
	return ne;
}
matrix pow(matrix a, int k)// powering the matrix 
{
	if (k == 1)
		return a;
	if (k % 2)
	{
		return mul(a, pow(a, k - 1));
	}
	matrix re = pow(a, k / 2);
	return mul(re, re);
}
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N, M;
	cin >> N >> M;
	matrix mu;
	mu.init(M, M);
	matrix ori;
	ori.init(1, M);
	int i;
	for (i = 0; i < M; i++)
		ori.x[0][i] = 1;
	for (i = 1; i < M; i++)
		mu.x[i][i-1] = 1;
	mu.x[M - 1][M - 1] = 1;
	mu.x[0][M - 1] = 1;
	matrix dp = mul(ori, pow(mu, N));
	cout << dp.x[0][0] << '\n';
}