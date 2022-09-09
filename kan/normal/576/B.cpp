#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstdio>

using namespace std;

#define pb push_back

const int maxn = 100005;

int a[maxn];
bool was[maxn];
vector<pair<int, int>> ans;
int n;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]), a[i]--;
	for (int i = 0; i < n; i++) if (a[i] == i)
	{
		printf("YES\n");
		for (int j = 0; j < n; j++) if (j != i) printf("%d %d\n", j + 1, i + 1);
		return 0;
	}
	for (int i = 0; i < n; i++) if (a[a[i]] == i)
	{
		was[i] = true;
		was[a[i]] = true;
		for (int j = 0; j < n; j++) if (!was[j])
		{
			int cnt = 0;
			int cur = j;
			while (!was[cur])
			{
				was[cur]++;
				if (cnt & 1) ans.pb({cur, i});
				else ans.pb({cur, a[i]});
				cnt++;
				cur = a[cur];
			}
			if (cnt % 2 != 0)
			{
				printf("NO\n");
				return 0;
			}
		}
		ans.pb({i, a[i]});
		printf("YES\n");
		for (auto t : ans) printf("%d %d\n", t.first + 1, t.second + 1);
		return 0;
	}
	printf("NO\n");
}