#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <string>
#include <vector>
#include <cstdio>
#include <cassert>

using namespace std;

typedef long long ll;
typedef long double ld;

#ifdef WIN32
	#define LLD "%I64d"
#else
	#define LLD "%lld"
#endif

const int maxn = 100005;

vector<int> gr[maxn];
bool was[maxn];
int n, m;

void go(int cur)
{
    if (was[cur]) return;
    was[cur] = true;
    for (int i = 0; i < (int)gr[cur].size(); i++) go(gr[cur][i]);
}

int main()
{
    scanf("%d%d", &n, &m);
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        int k;
        scanf("%d", &k);
        for (int j = 0; j < k; j++)
        {
            int x;
            scanf("%d", &x), x--;
            gr[i].push_back(n + x);
            gr[n + x].push_back(i);
        }
        sum += k;
    }
    if (sum == 0)
    {
        printf("%d\n", n);
        return 0;
    }
    for (int i = 0; i < n + m; i++) was[i] = false;
    int ans = 0;
    for (int i = 0; i < n; i++) if (!was[i])
    {
        ans++;
        go(i);
    }
    cout << ans - 1 << endl;
	return 0;
}