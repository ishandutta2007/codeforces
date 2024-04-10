#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>
#define an 100100
using namespace std;
vector<int>rarr[an];
vector<int>carr[an];
long long N, M, D;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M >> D;
	int i;
	for (i = 0; i < D; i++)
	{
		int a, b;
		cin >> a >> b;
		rarr[a].push_back(b);
		carr[b].push_back(a);
	}
	for (i = 1; i <= N; i++)
	{
		rarr[i].push_back(0);
		rarr[i].push_back(M + 1);
		sort(rarr[i].begin(), rarr[i].end());
	}
	for (i = 1; i <= M; i++)
	{
		carr[i].push_back(0);
		carr[i].push_back(N + 1);
		sort(carr[i].begin(), carr[i].end());
	}
	long long leftthing = N * M - D-1;
	int nowx = 1;
	int nowy = 1;
	int dir = 0;
	int minx = 0, maxx = N + 1,miny = 0,maxy = M + 1;
	if (rarr[1][1] == 2)
		dir++;
	while ((maxy-miny+maxx-minx))
	{
		if (leftthing == 0)
		{
			cout << "Yes";
			return 0;
		}
		int next = -1;
		if (dir == 0)
		{
			next = min(maxy, *lower_bound(rarr[nowx].begin(), rarr[nowx].end(), nowy));
			minx = nowx;
		}
		if (dir == 1)
		{
			next = min(maxx, *lower_bound(carr[nowy].begin(), carr[nowy].end(), nowx));
			maxy = nowy;
		}
		if (dir == 2)
		{
			auto ayee = lower_bound(rarr[nowx].begin(), rarr[nowx].end(), nowy);
			ayee--;
			next = max(miny, *(ayee));
			maxx= nowx;
		}
		if (dir == 3)
		{
			auto ayee = lower_bound(carr[nowy].begin(), carr[nowy].end(), nowx);
			ayee--;
			next = max(minx, *(lower_bound(carr[nowy].begin(), carr[nowy].end(), nowx) - 1));
			miny = nowy;
		}
		int diff;
		if (dir % 2)
		{
			diff = abs(nowx - next);
		}
		else
		{
			diff = abs(nowy - next);
		}
		if (diff == 1)
		{
			cout << "No";
			return 0;
		}
		if (dir == 0)
		{
			nowy = next - 1;
		}
		if (dir == 1)
		{
			nowx = next - 1;
		}
		if (dir == 2)
		{
			nowy = next + 1;
		}
		if (dir == 3)
		{
			nowx = next + 1;
		}
		dir = (dir + 1) % 4;
		leftthing -= diff - 1;
	}
	cout << "No";
}