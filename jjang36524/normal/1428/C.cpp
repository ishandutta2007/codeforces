#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
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
		string s;
		cin >> s;
		N = s.length();
		int i;
		int stc = 0;
		int ans = N;
		for (i = 0; i < N; i++)
		{
			if (s[i] == 'A')
				stc++;
			else
			{
				if (stc)
				{
					ans -= 2;
					stc--;
				}
				else
				{
					stc++;
				}
			}
		}
		cout << ans << '\n';
	}
}