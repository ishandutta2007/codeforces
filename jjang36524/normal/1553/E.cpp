#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
int succs[300100];
int arr[300100];
int uf[300100];
int f(int n)
{
	return n == uf[n] ? n : uf[n] = f(uf[n]);
}
int u(int n,int m)
{
	n = f(n);
	m = f(m);
	if (n == m)
		return 0;
	uf[n] = m;
	return 1;
}
int main()
{
	int T;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> T;
	while (T--)
	{
		int N, M;
		cin >> N >> M;
		int i;
		for (i = 0; i < N; i++)
		{
			cin >> arr[i];
			arr[i]--;
			succs[(arr[i] - i + N) % N]++;
		}
		vector<int>x;
		
		for (i = 0; i < N; i++)
		{
			if (succs[i] >= (N - 2 * M))
			{
				int ans = 0;
				int j;
				for (j = 0; j < N; j++)
					uf[j] = j;
				for (j = 0; j < N; j++)
				{
					ans+=u((j + i) % N, arr[j]);
				}
				if (ans <= M)
				{
					x.push_back((N-i)%N);
				}
			}
		}
		sort(x.begin(), x.end());
		cout << x.size() << ' ';
		for (i = 0; i < x.size(); i++)
			cout << x[i] << ' ';
		cout << '\n';
		for (i = 0; i < N; i++)
		{
			succs[(arr[i] - i + N) % N]--;
		}
	}
}