#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;
#define int long long
int T;
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N, M;
	cin >> T;
	while (T--)
	{
		cin >> N >> M;
		cout << (N * M + 1) / 2 << '\n';
	}
}