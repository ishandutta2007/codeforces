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
#include <stack>

using namespace std;

typedef long long ll;
typedef long double ld;

#ifdef WIN32
	#define LLD "%I64d"
#else
	#define LLD "%lld"
#endif

#define pb push_back
#define all(x) begin(x), end(x)

const int maxn = 200005;

int a[maxn], l[maxn], r[maxn], ans[maxn];
stack<pair<int, int>> q;
int n;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    q.push({-1, -1});
    for (int i = 0; i < n; i++)
    {
        while (q.top().first >= a[i]) q.pop();
        l[i] = q.top().second;
        q.push({a[i], i});
    }
    while (!q.empty()) q.pop();
    q.push({-1, n});
    for (int i = n; i >= 0; i--)
    {
        while (q.top().first >= a[i]) q.pop();
        r[i] = q.top().second;
        q.push({a[i], i});
        int len = r[i] - l[i] - 1;
        ans[len] = max(ans[len], a[i]);
    }
    for (int i = n - 1; i >= 0; i--) ans[i] = max(ans[i], ans[i + 1]);
    for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
    printf("\n");
    return 0;
}