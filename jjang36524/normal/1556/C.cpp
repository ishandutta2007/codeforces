#include <iostream>
#include <algorithm>
#include <vector>
#define int long long
using namespace std;
vector<int>psum;
signed main()
{
	int N;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	psum.push_back(0);
	int i;
	vector<int>pl{ 0,1 };
	for (i = 0; i < N; i++)
	{
		int a;
		cin >> a;
		psum.push_back(psum.back() + a * (i % 2?-1 : 1));
		pl.push_back(psum.back());
		pl.push_back(psum.back() + 1);
	}
	
	sort(pl.begin(), pl.end());
	int ans = 0;
	for (i = 0; i < pl.size()-1; i++)
	{
		int an = 0;
		int cu = 0;
		int j;
		for (j = 1; j < psum.size(); j++)
		{
			if (psum[j - 1] <= pl[i] && psum[j] > pl[i])
			{
				cu++;
			}
			if (psum[j] <= pl[i] && psum[j-1] > pl[i])
			{
				an += cu;
			}
			if (psum[j] < pl[i])
			{
				cu = 0;
			}
		}
		ans += an*(pl[i+1]-pl[i]);
	}
	cout << ans;
}