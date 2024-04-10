#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using D = double;
using uint = unsigned int;

#ifdef WIN32
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second

int main()
{
	int f, h, m;
	scanf("%d%d:%d", &f, &h, &m);
	if (f == 24)
	{
		if (h > 23)
		{
			h -= (h / 10) * 10;
// 			ans++;
		}
		if (m / 10 > 5)
		{
// 			ans++;
			m -= (m / 10) * 10;
		}
	} else
	{
		if (h == 0)
		{
// 			ans++;
			h = 10;
		}
		else {
			if (h > 12)
			{
// 				ans++;
				if (h % 10 == 0) h = 10;
				else h -= (h / 10) * 10;
			}
		}
		if (m / 10 > 5)
		{
// 			ans++;
			m -= (m / 10) * 10;
		}
	}
	printf("%02d:%02d\n", h, m);
    return 0;
}