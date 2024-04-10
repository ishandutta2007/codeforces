#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <ctime>
#include <sstream>
#include <fstream>
#include <bitset>
#include <iomanip>

using namespace std;

typedef long long int64;
typedef long long LL;
typedef long double real;
typedef long double LD;

#define mp make_pair
#define PII pair<int, int>
#define pb push_back
#define sz(X) ((int)((X).size()))

const double eps = 1e-8;
const double PI = acos(0.) * 2;
const int lim = 1000000000;
const int inf = ~0U >> 1;

template<class T> T abs(T x){return x < 0 ? -x : x;}

const int N = 1000005;

int f[N], g[N];
char s[N], t[N];

int gcd(int a, int b)
{
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main()
{
    #ifdef LOCAL_TEST
        freopen("c.in","r",stdin);
//      freopen("c.out","w",stdout);
    #endif
    long long p, q;
    scanf("%I64d%I64d", &p, &q);
    scanf("%s%s", s, t);
    int n = strlen(s);
    int m = strlen(t);
    int gxx = gcd(n, m);
    long long hehe = p * n / (1LL * n / gxx * m);
    long long ans = 0;
    for (char c = 'a'; c <= 'z'; ++c)
    {
        for (int i = 0; i < gxx; ++i)
            f[i] = g[i] = 0;
        for (int i = 0; i < n; ++i)
            if (s[i] == c)
                ++f[i % gxx];
        for (int i = 0; i < m; ++i)
            if (t[i] == c)
                ++g[i % gxx];
        for (int i = 0; i < gxx; ++i)
            ans += 1LL * f[i] * g[i];
    }
    ans *= hehe;
    cout << p * n - ans << endl;
    return 0;
}