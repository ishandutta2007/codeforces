#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#pragma warning(disable:4996)
using namespace std;
int cur[26];
int main()
{
	ios_base::sync_with_stdio(false);
	int T;
	cin >> T;
	while (T--)
	{
		memset(cur, 0, sizeof(cur));
		int N, K;
		cin >> N >> K;
		string s;
		cin >> s;
		int i;
		if (N % K)
		{
			cout << -1 << '\n';
			continue;
		}
		for (i = 0; i < N; i++)
		{
			cur[s[i] - 'a']++;
		}
		for (i = N - 1; i >= 0; i--)
		{
			cur[s[i] - 'a']--;
			int j;
			for (j = s[i] - 'a' + (i!=N-1); j < 26; j++)
			{
				int ans = 0;
				cur[j]++;
				int k;
				for (k = 0; k < 26; k++)
				{
					ans += (cur[k] + K - 1) / K*K;
				}
				if (ans <= N)
				{
					for (k = 0; k < i; k++)
						cout << s[k];
					cout << (char)(j + 'a');
					string x;
					for (k = 0; k < N - ans; k++)
						cout << 'a';
					for (k = 0; k < 26; k++)
					{
						int cal = (cur[k] + K - 1) / K*K-cur[k];
						int l;
						for (l = 0; l < cal; l++)
							cout << (char)(k + 'a');
					}
					cout << '\n';
					goto T;
				}
				cur[j]--;
			}
		}
	T:
		int d;
	}
}