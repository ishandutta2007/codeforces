#include <iostream>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;
int N, T, a, b, c, d;
vector<pair<int, pair<int, int>>>s;
vector<pair<int, pair<int, int>>>l;
int arr[500100];
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> a >> b >> c;
	int i;
	for (i = 0; i < N; i++)
	{
		int x, y;
		cin >> x >> y;
		int t = x * b + y;
		s.push_back({ t % (b / 2) + 1 ,{1,i} });
		s.push_back({ t % (b / 2) + c, {-1,i} });
		s.push_back({ t % (b / 2) + c - b / 2,{-1,i} });
		s.push_back({ t % (b / 2) - b / 2 + 1,{1,i} });
	}
	sort(s.begin(), s.end());
	int ans = 0;
	pair<int, int>r = { 1LL << 60,0 };
	for (i = 0; i < 4 * N; i++)
	{
		ans += s[i].second.first;
		arr[s[i].second.second] += s[i].second.first;
		if ((i==4*N-1||s[i+1].first > 0) && s[i].first < b / 2 && (i == 4 * N - 1 || s[i].first != s[i + 1].first))
			r = min(r, { ans,max(0LL,s[i].first) });
	}
	cout << r.first << ' ' << r.second;
	cout << '\n';
	for (i = 0; i < 4 * N; i++)
	{
		ans += s[i].second.first;
		arr[s[i].second.second] += s[i].second.first;
		if (ans==r.first&&(s[i].first<=r.second&&(i&&s[i+1].first>r.second)))
		{
			int j;
			for (j = 0; j < N; j++)
			{
				if (arr[j])
					cout << j + 1 << ' ';
			}
			return 0;
		}
	}
}