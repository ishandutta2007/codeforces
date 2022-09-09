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

const int maxn = 400004;
const int inf = 1e9;

int ans[maxn];
ll a, b;
ll bound;
int k;

ll count(int a, int b)
{
    for (int i = 0; i <= bound; i++) ans[i] = inf;
    ans[a] = 0;
    for (int i = a + 1; i <= b; i++)
    {
	ans[i] = ans[i - 1] + 1;
// 	cout << i << ' ' << ans[i] << endl;
	for (int j = 2; j <= k; j++) ans[i] = min(ans[i], ans[i - (i % j)] + 1);
    }
    return ans[b];
}

int main()
{
    cin >> a >> b >> k;
    bound = 1;
    for (int i = 2; i <= k; i++)
    {
	int d = __gcd((ll)i, bound);
	bound = bound * i / d;
    }
//     cerr << bound << endl;
    if (b / bound == a / bound)
    {
// 	cerr << "sgf" << endl;
	cout << count(b % bound, a % bound) << endl;
	return 0;
    }
    if (a / bound == b / bound + 1)
    {
	cout << count(b % bound, bound) + count(0, a % bound) << endl;
	return 0;
    }
    cout << count(b % bound, bound) + count(0, a % bound) + count(0, bound) * (a / bound - b / bound - 1) << endl;
    return 0;
}