#include <iostream>
#include <algorithm>
#include <vector>
#define int long long
using namespace std;
vector<int>psum;
int res[10100];
signed main()
{
	int N,K;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N>>K;
	int i;
	int arr[5][5];
	for (i = 1; i < 3; i++)
	{
		int j;
		for (j = i + 1; j <= 3; j++)
		{
			arr[i][j] = 0;
			cout << "and " << i << ' ' << j << '\n';
			cout.flush();
			int a;
			cin >> a;
			arr[i][j] += a;
			cout << "or " << i << ' ' << j << '\n';
			cout.flush();
			cin >> a;
			arr[i][j] += a;
		}
	}
	int ans = (arr[1][2] + arr[2][3] + arr[1][3]) / 2;
	res[1] = ans - arr[2][3];
	res[2] = ans - arr[1][3];
	res[3] = ans - arr[1][2];
	for (i = 4; i <= N; i++)
	{
		cout << "and " << i << ' ' << 1 << '\n';
		cout.flush();
		int a;
		cin >> a;
		res[i] += a;
		cout << "or " << i << ' ' << 1 << '\n';
		cout.flush();
		cin >> a;
		res[i] += a;
		res[i] -= res[1];
	}
	sort(res + 1, res + N + 1);
	cout << "finish " << res[K] << '\n';
	cout.flush();
}