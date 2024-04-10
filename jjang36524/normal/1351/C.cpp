#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <string>
using namespace std;
set<pair<pair<int,int>, int>>t;
int main()
{
	int N;
	cin >> N;
	while (N--)
	{
		t.clear();
		string s;
		cin >> s;
		int i;
		int l = s.length();
		int nx = 0, ny = 0;
		int ans = 0;
		for (i = 0; i < l; i++)
		{
			if (s[i] == 'N')
			{
				ans += 1 - t.count({ {nx,ny},0 });
				t.insert({ {nx,ny},0 });
				nx++;
			}
			else if (s[i] == 'E')
			{
				ans += 1 - t.count({ {nx,ny},1 });
				t.insert({ {nx,ny},1 });
				ny++;
			}
			else if (s[i] == 'W')
			{
				ny--;
				ans += 1 - t.count({ {nx,ny},1 });
				t.insert({ {nx,ny},1 });
			}
			else
			{
				nx--;
				ans += 1 - t.count({ {nx,ny},0 });
				t.insert({ {nx,ny},0 });
			}
		}
		cout << l + 4 * ans << '\n';
	}
}