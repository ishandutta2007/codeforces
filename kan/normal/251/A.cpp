#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <ctime>
#include <cassert>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned int uint;

#ifdef WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

const int maxn = 1e5 + 5;

int a[maxn];
int n, d;

int main()
{
    scanf("%d%d", &n, &d);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    a[n] = 2e9 + 1;
    int cur = 0;
    ll answer = 0;
    for (int i = 0; i < n; i++)
    {
	while (a[cur + 1] <= a[i] + d) cur++;
	int k = cur - i + 1;
	answer += (ll)(k - 1) * (k - 2) / 2;
    }
    cout << answer << endl;
    return 0;
}