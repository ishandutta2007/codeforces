#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <string>
#include <vector>
#include <cstdio>

using namespace std;

typedef long long ll;
typedef long double ld;

#ifdef WIN32
	#define LLD "%I64d"
#else
	#define LLD "%lld"
#endif

const int maxn = 100005;

int a[maxn];
ll sum[maxn];
int n, nq;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    sort(a, a + n);
    reverse(a, a + n);
    sum[0] = 0;
    for (int i = 0; i < n; i++) sum[i + 1] = sum[i] + a[i];
    ll answer1 = 0;
    ll cursum = 0;
    for (int i = n - 1; i > 0; i--)
    {
        cursum += a[i];
        answer1 += cursum;
    }
    scanf("%d", &nq);
    for (int i = 0; i < nq; i++)
    {
        int q;
        scanf("%d", &q);
        if (q == 1)
        {
            printf(LLD " ", answer1);
            continue;
        }
        ll cur = 0;
        ll answer = 0;
        for (ll cursz = 1, curk = 0; cur < n; cur += cursz, cursz *= q, curk++)
        {
            answer += (sum[min((ll)n, cursz + cur)] - sum[cur]) * curk;
        }
        printf(LLD " ", answer);
    }
	return 0;
}