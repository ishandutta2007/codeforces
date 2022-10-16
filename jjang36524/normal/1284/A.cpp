#include <iostream>
#include <string>
using namespace std;
#define int long long
int N, M, T;
string x[20];
string t[20];
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M;
	int i;
	for (i = 0; i < N; i++)
	{
		cin >> x[i];
	}
	for (i = 0; i < M; i++)
		cin >> t[i];
	cin >> T;
	while (T--)
	{
		int y;
		cin >> y;
		cout << x[(y - 1) % N] << t[(y - 1) % M]<<'\n';
	}
}