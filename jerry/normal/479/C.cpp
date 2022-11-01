#include <cstdio>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

struct cmp
{
	bool operator() (const pair<int,int>& a, const pair<int,int>& b) const
	{
		if (a.first != b.first)
			return (a.first > b.first);
		return (a.second > b.second);
	}
};

priority_queue<pair<int, int>, vector<pair<int, int> >, cmp> pq;
int n;
int tmp, tmq;
int ctime;

int main()
{
	scanf("%d", &n);
	for (int i = 0;i < n;i++)
	{
		scanf("%d%d", &tmp, &tmq);
		pq.push(make_pair(tmp, tmq));
	}
	while (!pq.empty())
	{
		pair<int, int> u = pq.top(); pq.pop();
		if (u.second < ctime)
			pq.push(make_pair(u.first, u.first));
		else
			ctime = u.second;
	}
	printf("%d\n", ctime);
	return 0;
}