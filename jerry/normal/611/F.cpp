#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007ll

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};
int mp[256];

vector<pair<int, int> > evt;
long long fl, fr, fu, fd;
long long ans;
int x, y;

char buf[500005];
int n, h, w;

void foo(bool _)
{
	for (long long i = 0;i < n;i++)
	{
		if (fl > fr || fd > fu) break;
		x += dx[mp[buf[i]]]; y += dy[mp[buf[i]]];
		if (x+fl < 0 || x+fr >= w)
		{
			if (x+fl < 0)
			{ fl++; if (_) evt.emplace_back(i+1, 0); }
			if (x+fr >= w)
			{ fr--; if (_) evt.emplace_back(i+1, 1); }
			ans += (fu-fd+1)*(i+1);
			if (_) ans += (fu-fd+1)*n;
			ans %= MOD;
		}
		if (y+fd < 0 || y+fu >= h)
		{
			if (y+fd < 0)
			{ fd++; if (_) evt.emplace_back(i+1, 2); }
			if (y+fu >= h)
			{ fu--; if (_) evt.emplace_back(i+1, 3); }
			ans += (fr-fl+1)*(i+1);
			if (_) ans += (fr-fl+1)*n;
			ans %= MOD;
		}
	}
}

int main()
{
	mp['L'] = 0, mp['R'] = 1, mp['D'] = 2, mp['U'] = 3;
	scanf("%d%d%d%s", &n, &h, &w, buf);
	fl = 0, fr = w-1, fd = 0, fu = h-1;
	foo(false); foo(true);
	if (fl <= fr && fd <= fu && x == 0 && y == 0) { printf("-1\n"); return 0; }
	long long ext = n;
	while (fl <= fr && fd <= fu)
	{
		ext += n;
		for (auto u: evt)
		{
			if (fl > fr || fd > fu) break;
			switch (u.second) // wow, a switch statement
			{                 // these things are actually useful for once
				case 0:
					fl++;
					ans += (fu-fd+1)*(u.first+ext);
					break;
				case 1:
					fr--;
					ans += (fu-fd+1)*(u.first+ext);
					break;
				case 2:
					fd++;
					ans += (fr-fl+1)*(u.first+ext);
					break;
				case 3:
					fu--;
					ans += (fr-fl+1)*(u.first+ext);
					break;
			}
			ans %= MOD;
		}
	}
	printf("%lld\n", ans);
	return 0;
}