#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <string>
#include <vector>
#include <cstdio>
#include <cassert>
#include <ctime>

using namespace std;

typedef long long ll;
typedef long double ld;

#ifdef WIN32
	#define LLD "%I64d"
#else
	#define LLD "%lld"
#endif

const int maxn = 1000006;

int p[maxn], ans[maxn], maxt[maxn];
int n;

void upd(int cur, int curt)
{
	if (cur == -1) return;
// 	cout << "upd " << cur << ' ' << curt << endl;
// 	cout << maxt[cur] << ' ' << ans[cur] << endl;
	if (curt > maxt[cur])
	{
		maxt[cur] = curt;
		if (ans[cur] < curt) upd(p[cur], curt);
		ans[cur] = curt;
	} else if (curt == maxt[cur])
	{
// 		cout << "eq " << endl;
		if (ans[cur] == curt)
		{
			ans[cur]++;
			upd(p[cur], ans[cur]);
		}
	}
}

int main()
{
	scanf("%d", &n);
	ans[0] = 1;
	maxt[0] = -1;
	p[0] = -1;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &p[i + 1]);
		p[i + 1]--;
		ans[i + 1] = 1;
		maxt[i + 1] = -1;
// 		cout << "to " << p[i + 1] << endl;
		upd(p[i + 1], 1);
		printf("%d ", maxt[0]);
	}
	printf("\n");
	return 0;
}