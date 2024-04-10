#include <iostream>
#include <queue>
#define int long long
using namespace std;
priority_queue<int>q;
signed main()
{
	int N;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	while (N--)
	{
		int i;
		for (i = 0; i < 81; i++)
		{
			char a;
			cin >> a;
			if (a == '1')
				cout << 2;
			else
				cout << a;
			if (i % 9 == 8)
				cout << '\n';
		}
	}
}