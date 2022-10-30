#include <bits/stdc++.h>
 
#define INT_INF (2 * 1e9)
#define LL_INF  (2LL * 1e18)
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL);
 
using namespace std;
 
typedef long long int ll;
typedef unsigned long long int ull;

int main(int argc, char** argv)
{
	int n;
	int ans = 0;
	string str;
	vector<pair<int, int>> blocks;

	cin >> n >> str;

	for(int i = 0; i < n;)
	{
		if(str[i] == 'G')
		{
			int j = i;

			while(j + 1 < n && str[j + 1] == 'G')
				++j;

			blocks.emplace_back(i, j);

			i = j + 1;
		}
		else
		{
			++i;
		}
	}

	int m = blocks.size();

	for(auto block: blocks)
		ans = max(ans, block.second - block.first + 1);

	if(blocks.size() > 1)
	{
		for(auto block: blocks)
			ans = max(ans, block.second - block.first + 2);

		for(int i = 0; i + 1 < m; ++i)
		{
			if(blocks[i + 1].first == blocks[i].second + 2)
			{
				ans = max(ans, blocks[i + 1].second - blocks[i].first);
			}
		}
	}

	if(blocks.size() > 2)
	{
		for(int i = 0; i + 1 < m; ++i)
		{
			if(blocks[i + 1].first == blocks[i].second + 2)
			{
				ans = max(ans, blocks[i + 1].second - blocks[i].first + 1);
			}
		}
	}

	cout << ans << endl;

    return 0;
}