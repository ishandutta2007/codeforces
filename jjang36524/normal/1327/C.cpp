#include <iostream>
#include <algorithm>
#include <vector>
#define int long long
using namespace std;
int N, M, K;
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N>>M;
	cout << N * M + N + M - 3 << '\n';
	int i;
	for (i = 1; i < N;i++)
		cout << 'U';
	for (i = 1; i < M; i++)
		cout << 'L';
	for (i = 0; i < N; i++)
	{
		if (i)
			cout << 'D';
		int j;
		for (j = 1; j < M; j++)
			cout << (i % 2 ? 'L' : 'R');
	}
}