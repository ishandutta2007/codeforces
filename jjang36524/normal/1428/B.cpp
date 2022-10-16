#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int arr[300100];
int main()
{
	int T;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> T;
	while (T--)
	{
		int N;
		cin >> N;
		string s;
		cin >> s;
		int i;
		for (i = 0; i < N; i++)
		{
			arr[i] = 0;
		}
		char at = 0;
		int succ = 1;
	
		for (i = 0; i < N; i++)
		{
			if (!at)
			{
				if(s[i]!='-')
					at = s[i];
			}
			else
			{
				if (at != s[i]&&s[i]!='-')
					succ = 0;
			}
			if (s[i] == '-')
			{
				arr[i] = 1;
				arr[(i + 1) % N] = 1;
			}
		}
		int ans = 0;
		for (i = 0; i < N; i++)
		{
			ans += arr[i];
		}
		if (succ)
			ans = N;
		cout << ans << '\n';
	}
}