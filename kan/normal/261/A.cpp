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

const int maxn = 1e5 + 5;
const int inf = 1e9 + 9;

int a[maxn];
int n, m;

int main()
{
    scanf("%d", &m);
    int sk = inf;
    for (int i = 0; i < m; i++)
    {
        int a;
        scanf("%d", &a);
        sk = min(sk, a);
    }
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    sort(a, a + n);
    int answer = 0;
    for (int i = n - 1; i >= 0; i -= sk + 2)
    {
        for (int j = i; j >= max(0, i - sk + 1); j--) answer += a[j];
    }
    cout << answer << endl;
	return 0;
}