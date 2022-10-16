#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	while (T--)
	{
		int N;
		cin >> N;
		int i;
		int ans = 0;
		for (i = 0; i < N; i++)
		{
			int a;
			cin >> a;
			ans += a != 2;
		}
		cout << ans << '\n';
	}
}