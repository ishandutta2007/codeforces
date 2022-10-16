#include <iostream>
#include <algorithm>
using namespace std;
int T, N;
int main()
{
	cin >> T;
	while (T--)
	{
		cin >> N;
		int i;
		int lasta = -1;
		int ans = 0;
		for (i = 0; i < N; i++)
		{
			char a;
			cin >> a;
			if (a == 'A')
			{
				lasta = i;
			}
			else
			{
				if (lasta != -1)
					ans = max(i - lasta,ans);
			}
		}
		cout << ans << '\n';
	}
}