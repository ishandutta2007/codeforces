#include <iostream>
#include <algorithm>
using namespace std;
int minx, miny, maxx, maxy;
int Q, N;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> Q;
	while (Q--)
	{
		cin >> N;
		minx = miny = -100000;
		maxx = maxy = 100000;
		int i;
		for (i = 0; i < N; i++)
		{
			int a, b, c, d, e, f;
			cin >> a >> b >> c >> d >> e >> f;
			if (!c)
				minx = max(minx,a);
			if (!d)
				maxy = min(maxy, b);
			if (!e)
				maxx = min(maxx, a);
			if (!f)
				miny = max(miny, b);
		}
		if (minx > maxx || miny > maxy)
			cout << 0 << '\n';
		else
			cout << 1 <<' '<< minx <<' '<< miny << '\n';
	}
}