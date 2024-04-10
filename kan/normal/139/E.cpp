#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long double ld;

const int OPEN = 0;
const int MUSH = 1;
const int CLOSE = 2;

struct tsob
{
	int x, t, v;
	tsob(int x, int t, int v): x(x), t(t), v(v) {}
};

inline bool operator<(const tsob &a, const tsob &b)
{
	if (a.x != b.x) return a.x < b.x;
	return (a.t < b.t);
}

vector<tsob> sobs;
int n, m;

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		int x, h, vl, vr;
		scanf("%d%d%d%d", &x, &h, &vl, &vr);
		sobs.push_back(tsob(x - h, OPEN, 100 - vl));
		sobs.push_back(tsob(x - 1, CLOSE, 100 - vl));
		sobs.push_back(tsob(x + 1, OPEN, 100 - vr));
		sobs.push_back(tsob(x + h, CLOSE, 100 - vr));
	}
	for (int i = 0; i < m; i++)
	{
		int x, v;
		scanf("%d%d", &x, &v);
		sobs.push_back(tsob(x, MUSH, v));
	}
	sort(sobs.begin(), sobs.end());
	ld curv = 0;
	int kv0 = 0;
	ld answer = 0;
	for (int i = 0; i < (int)sobs.size(); i++)
	{
		if (sobs[i].t == OPEN)
		{
			if (sobs[i].v == 0) kv0++;
			else curv += log(sobs[i].v / 100.0);
		}
		if (sobs[i].t == CLOSE)
		{
			if (sobs[i].v == 0) kv0--;
			else curv -= log(sobs[i].v / 100.0);
		}
		if (sobs[i].t == MUSH)
		{
			if (kv0 == 0) answer += sobs[i].v * exp(curv);
		}
	}
	cout.precision(20);
	cout << answer << endl;
	return 0;
}