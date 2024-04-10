#include <bits/stdc++.h>
using namespace std;

namespace TYC
{
	typedef long long ll;
	typedef pair<int, int> pii;
	const int N = 1005;

	int n, M[N][N];

	void work()
	{
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				scanf("%d", &M[i][j]);
		int a1 = sqrt((ll)M[1][2] * M[1][3] / M[2][3]);
		for (int i = 1; i <= n; i++)
			if (i == 1)
				printf("%d ", a1);
			else
				printf("%d ", M[1][i] / a1);
	}
}

int main()
{
	TYC::work();
	return 0;
}