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

const int maxn = 25;

int a[maxn];
int kv[maxn], now[maxn];
int waskv[maxn], wasnow[maxn];
int kv_1, kv_3;
int n;

inline void bad()
{
	printf("NO\n");
	exit(0);
}

void go(int cur)
{
	if (cur == n)
	{
// 		cout << "last " << endl;
// 		for (int i = 0; i < n; i++) cout << now[i] << ' ' << kv[i] << endl;
		int curkv_1 = kv_1;
		int curkv_3 = kv_3;
		for (int i = 0; i < n; i++)
		{
			wasnow[i] = now[i];
			waskv[i] = kv[i];
		}
		for (int i = 0; i < n; i++) if (kv[i] == 0)
		{
			if (a[i] - now[i] == 3)
			{
				kv[i] += 3;
				now[i] += 3;
				curkv_1 -= 3;
			} else
			{
				int sp_3 = min(curkv_3, (a[i] - now[i]) / 3);
				curkv_3 -= sp_3;
				now[i] += 3 * sp_3;
				kv[i] += sp_3;
				curkv_1 -= (a[i] - now[i]);
				kv[i] += (a[i] - now[i]);
				now[i] = a[i];
			}
		}
		for (int i = 0; i < n; i++)
		{
			int sp_3 = min(curkv_3, (a[i] - now[i]) / 3);
			curkv_3 -= sp_3;
			now[i] += 3 * sp_3;
			kv[i] += sp_3;
			curkv_1 -= (a[i] - now[i]);
			kv[i] += (a[i] - now[i]);
			now[i] = a[i];
		}
		bool ok = true;
		for (int i = 0; i < n; i++) if (kv[i] < 2) ok = false;
		if (curkv_1 != 0 || !ok)
		{
			for (int i = 0; i < n; i++)
			{
				now[i] = wasnow[i];
				kv[i] = waskv[i];
			}
			return;
		}
		printf("YES\n");
		exit(0);
	}
// 	cout << "go " << cur << endl;
	for (int i = 0; i < cur; i++) if (now[i] + a[cur] <= a[i])
	{
		now[i] += a[cur];
		kv[i]++;
		go(cur + 1);
		now[i] -= a[cur];
		kv[i]--;
	}
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	sort(a, a + n);
	reverse(a, a + n);
	if (a[0] != n) bad();
	if (n == 1)
	{
		printf("YES\n");
		return 0;
	}
	if (n == 2) bad();
	kv_1 = 0;
	while (a[n - 1] == 1)
	{
		kv_1++;
		n--;
	}
	if (a[n - 1] == 2) bad();
	if (kv_1 <= n) bad();
	kv_3 = 0;
	while (n > 0 && a[n - 1] == 3)
	{
		kv_3++;
		kv_1 -= 2;
		n--;
	}
	if (n == 0)
	{
		if (kv_1 != 0 || kv_3 != 1) bad();
		printf("YES\n");
		return 0;
	}
	if (kv_1 < 0) bad();
	if (kv_1 + kv_3 <= n) bad();
// 	cout << "check " << kv_1 << ' ' << kv_3 << ' ' << n << endl;
	for (int i = 0; i < n; i++) now[i] = 1;
	go(1);
	bad();
	return 0;
}