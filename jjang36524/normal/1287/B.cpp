#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
int T, N;
vector<string>s;
int main()
{
	cin >> N >> T;
	int i;
	for (i = 0; i < N; i++)
	{
		string st;
		cin >> st;
		s.push_back(st);
	}
	sort(s.begin(), s.end());
	int ans = 0;
	for (i = 0; i < N; i++)
	{
		int j;
		for (j = i+1; j < N; j++)
		{
			int k;
			string ne;
			for (k = 0; k < T; k++)
			{
				char f = s[i][k];
				char se = s[j][k];
				if (f == se)
					ne.push_back(f);
				else
				{
					ne.push_back('S' + 'E' + 'T' - f - se);
				}
			}
			int diff = lower_bound(s.begin(), s.end(), ne) - upper_bound(s.begin(), s.end(), ne);
			if (diff)
				ans++;
		}
	}
	cout << ans/3;
}