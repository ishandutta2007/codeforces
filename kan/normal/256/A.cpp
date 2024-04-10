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

const int maxn = 4005;
const int maxx = 1e6 + 6;

int ans[maxn][maxn];
int last[maxx];
int next[maxn];
int a[maxn], kv[maxx];
int n;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    for (int i = 0; i < maxx; i++) last[i] = n;
    memset(kv, 0, sizeof(kv));
    int answer = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        next[i] = last[a[i]];
        kv[a[i]]++;
        answer = max(answer, kv[a[i]]);
        last[a[i]] = i;
    }
    memset(ans, 0, sizeof(ans));
    for (int i = n - 1; i >= 0; i--)
    {
        ans[i][n] = 1;
        for (int j = n - 1; j > i; j--)
        {
            if (next[i] <= j) ans[i][j] = ans[next[i]][j];
            else ans[i][j] = 1 + ans[j][next[i]];
            answer = max(answer, ans[i][j]);
        }
    }
    cout << answer << endl;
	return 0;
}