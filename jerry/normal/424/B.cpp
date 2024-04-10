#include <cstdio>
#include <cmath>
#include <algorithm>
#include <utility>

using namespace std;

#define om pair<pair<int, int>, int>

om things[1000];
int remain;
int n;

int dist(const om& a)
{
	return (a.first.first*a.first.first + a.first.second*a.first.second);
}

bool comp(const om& a, const om& b)
{
	return (dist(a) < dist(b));
}

int main()
{
	scanf("%d%d", &n, &remain);
	remain = 1000000 - remain;
	for (int i = 0;i < n;i++)
		scanf("%d%d%d", &things[i].first.first, &things[i].first.second, &things[i].second);
	sort(things, things+n, comp);
	for (int i = 0;i < n;i++)
	{
		remain -= things[i].second;
		if (remain <= 0)
		{
			printf("%.7lf\n", sqrt(dist(things[i])));
			return 0;
		}
	}
	printf("-1\n");
	return 0;
}