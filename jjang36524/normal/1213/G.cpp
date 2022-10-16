#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, M;
pair<int,long long> union_find[200100];
long long nowanswer;
vector<pair<int, pair<int,int>>>vertexes;
vector<pair<int,int>>ms;
long long ans[200100];
long long findpairnum(long long num)
{
	return num * (num - 1) / 2;
}
int find(int x)
{
	if (x == union_find[x].first)
		return x;
	return union_find[x].first = find(union_find[x].first);
}
int unio(int x, int y)
{
	if (union_find[find(x)].first == union_find[find(y)].first)
		return 0;
	nowanswer += findpairnum(union_find[find(x)].second + union_find[find(y)].second) - findpairnum(union_find[find(x)].second) - findpairnum(union_find[find(y)].second);
	union_find[find(y)].second += union_find[find(x)].second;
	union_find[find(x)].first = union_find[find(y)].first;
	
	return 0;
}
int main()
{
	cin >> N >> M;
	int i;
	for (i = 1; i < N; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		vertexes.push_back({ c,{a,b} });
		union_find[i] = { i,1 };
	}
	union_find[N] = { N,1 };
	sort(vertexes.begin(), vertexes.end());
	auto nowiterator = vertexes.begin();
	for (i = 0; i < M; i++)
	{
		int a;
		cin >> a;
		ms.push_back({ a, i});
	}
	sort(ms.begin(), ms.end());
	for (i = 0; i < M; i++)
	{
		while (nowiterator!=vertexes.end()&&nowiterator->first <= ms[i].first)
		{
			unio(nowiterator->second.first, nowiterator->second.second);
			nowiterator++;
		}
		ans[ms[i].second] = nowanswer;
	}
	for (i = 0; i < M; i++)
	{
		cout << ans[i]<<' ';
	}
}