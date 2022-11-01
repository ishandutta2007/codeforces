#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll ans, br, bb, fr, fb, lr, lb;
char c[300005];
ll p[300005];
int n, st;

int main()
{
	scanf("%d", &n);
	for (int i = 0;i < n;i++) scanf("%lld %c", p+i, c+i);
	fr = fb = -1;
	for (int i = 0;i < n;i++)
	{
		if (c[i] != 'B')
		{
			br = max(br, p[i]-lr);
			lr = p[i];
			if (c[i] == 'R' && fr == -1) fr = p[i];
		}
		if (c[i] != 'R')
		{
			bb = max(bb, p[i]-lb);
			lb = p[i];
			if (c[i] == 'B' && fb == -1) fb = p[i];
		}
		if (c[i] == 'G')
		{
			if (st) ans += min((p[i]-p[st-1])<<1, (p[i]-p[st-1])*3-br-bb);
			else
			{
				if (fr != -1) ans += p[i]-fr;
				if (fb != -1) ans += p[i]-fb;
			}
			st = i + 1; br = bb = 0; fr = fb = -1; lr = lb = p[i];
		}
	}
	if (st) ans += lr+lb-p[st-1]*2;
	else
	{
		if (fr != -1) ans += lr-fr;
		if (fb != -1) ans += lb-fb;
	}
	printf("%lld\n", ans);
	return 0;
}