#include <bits/stdc++.h>
using namespace std;

int x[200001], y[200001], v[200001];
int n, k, a, b, q;

void upd(int* bit, int wh, int va)
{for(;wh<200001;wh+=wh&-wh)bit[wh]+=va;}

int qu(int* bit, int wh)
{int r=0;for(;wh;wh-=wh&-wh)r+=bit[wh];return r;}

int qu(int* bit, int lo, int hi)
{return qu(bit,hi)-qu(bit,lo-1);}

int main()
{
	scanf("%d%d%d%d%d", &n, &k, &a, &b, &q);
	while (q--)
	{
		int t; scanf("%d", &t);
		if (t == 1)
		{
			int D, A; scanf("%d%d", &D, &A);
			upd(x, D, max(min(b-v[D], A), 0));
			upd(y, D, max(min(a-v[D], A), 0));
			v[D] += A;
		} else
		{
			int P; scanf("%d", &P);
			printf("%d\n", qu(x, 1, P-1)+qu(y, P+k, n));
		}
	}
	return 0;
}