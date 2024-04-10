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

const int maxn = 1000006;
const int hst = 239;
const int MOD = 1000000007;

struct thash
{
    int h1, h2;

    thash() {}
    thash(int x): h1(x), h2(x) {}
    thash(int h1, int h2): h1(h1), h2(h2) {}
};

thash operator+(const thash &a, const thash &b)
{
    return thash((a.h1 + b.h1) % MOD, a.h2 + b.h2);
}

thash operator-(const thash &a, const thash &b)
{
    return thash((a.h1 - b.h1 + MOD) % MOD, a.h2 - b.h2);
}

thash operator*(const thash &a, const thash &b)
{
    return thash(((ll)a.h1 * b.h1) % MOD, a.h2 * b.h2);
}

bool operator==(const thash &a, const thash &b)
{
    return a.h1 == b.h1 && a.h2 && b.h2;
}

int n, m;
char s[maxn];
thash h[maxn];
thash sth[maxn];

inline thash geth(int l, int r)
{
//     cout << "geth " << l << ' ' << r << endl;
    return h[r] - h[l] * sth[r - l];
}

int main()
{
    scanf("%d%d", &n, &m);
    scanf("%s", s);
    int len = strlen(s);
    for (int i = 0; i < len; i++) h[i + 1] = h[i] * hst + s[i];
    sth[0] = 1;
    for (int i = 1; i <= len; i++) sth[i] = sth[i - 1] * hst;
    int last = -len;
    int unknown = 0;
    bool bad = false;
    for (int i = 0; i < m; i++)
    {
        int x;
        scanf("%d", &x);
        x--;
        if (x < last + len)
        {
            int overlap = last + len - x;
            if (!(geth(0, overlap) == geth(len - overlap, len))) bad = true;
        } else unknown += x - (last + len);
        last = x;
    }
    unknown += n - (last + len);
    if (bad)
    {
        printf("%d\n", 0);
    } else
    {
        int ans = 1;
        for (int i = 0; i < unknown; i++) ans = ((ll)ans * 26) % MOD;
        printf("%d\n", ans);
    }
	return 0;
}