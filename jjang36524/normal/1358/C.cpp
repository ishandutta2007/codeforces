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
	int N, M,a,b;
	cin >> T;
	while (T--)
	{
		cin >> N >> M >> a >> b;
		int x = a - N + 1;
		int y = b - M + 1;
		cout << (x - 1) * (y - 1) + 1 << '\n';
	}
}