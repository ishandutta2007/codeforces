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

int main()
{
    ll A, B;
    int n;
    scanf(LLD LLD, &A, &B);
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int left, t, m;
        scanf("%d%d%d", &left, &t, &m);
        left--;
        int l = left - 1;
        int r = t + 1;
        while (r - l > 1)
        {
            int mid = (l + r) / 2;
            if (A + B * mid <= t && A * (mid - left + 1) + B * (mid - left + 1) * (mid + left) / 2 <= (ll)m * t) l = mid;
            else r = mid;
        }
        if (l < left) printf("-1\n");
        else printf("%d\n", l + 1);
    }
	return 0;
}