#include <iostream>
#include <cassert>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstdio>

using namespace std;

#define pb push_back

const int maxn = 1000006;
const int BSZ = 1000;
const int BCNT = 1002;

struct pt
{
	int x, y, id;
};

inline bool operator<(const pt &a, const pt &b)
{
	return a.y < b.y;
}

pt p[maxn];
vector<pt> buck[BCNT];
int n;
vector<int> answer;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d", &p[i].x, &p[i].y);
		p[i].id = i;
		buck[p[i].x / BSZ].pb(p[i]);
	}
	for (int i = 0; i < BCNT; i++)
	{
		sort(buck[i].begin(), buck[i].end());
		if (i & 1) reverse(buck[i].begin(), buck[i].end());
		for (auto t : buck[i]) answer.pb(t.id);
	}
	long long len = 0;
	for (int i = 0; i < (int)answer.size(); i++) if (i != 0) len += abs(p[answer[i]].x - p[answer[i - 1]].x) + abs(p[answer[i]].y - p[answer[i - 1]].y);
	cerr << len << endl;
	assert(len <= 2500000000LL);
	for (auto x : answer) printf("%d ", x + 1);
	printf("\n");
	return 0;
}