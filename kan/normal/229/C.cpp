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

const int maxn = 1e6+6;

int gr[maxn];
int n, m;

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b), a--, b--;
        gr[a]++;
        gr[b]++;
    }
    ll a = ((ll)n) * (n - 1) * (n - 2) / 6;
    ll b = ((ll)m) * (n - 2);
    ll d = 0;
    for (int i = 0; i < n; i++)
    {
        d += ((ll)gr[i])*(gr[i] - 1) / 2;
    }
    cout << a - b + d << endl;
	return 0;
}