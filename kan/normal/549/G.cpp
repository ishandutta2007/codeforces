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

#define pb push_back
#define all(x) begin(x), end(x)

const int maxn = 200005;

int a[maxn];
int n;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        a[i] += i;
    }
    sort(a, a + n);
    for (int i = 1; i < n; i++) if (a[i] == a[i - 1])
    {
        printf(":(\n");
        return 0;
    }
    for (int i = 0; i < n; i++) printf("%d ", a[i] - i);
    printf("\n");
	return 0;
}