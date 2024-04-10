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

const int MOD = 1000000007;

const int maxn = 4005;

int c[maxn][maxn];
int cnt[maxn], cnt2[maxn];

void add(int &a, ll b)
{
    a = (a + b) % MOD;
}

int main()
{
    int n;
    scanf("%d", &n);
    c[0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        c[i][0] = 1;
        for (int j = 1; j <= i; j++) c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % MOD;
    }
    cnt[0] = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j + i <= n; j++) add(cnt[i + j], (ll)cnt[i] * c[n - i - 1][j - 1]);
    }
    cnt2[0] = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j + i <= n; j++) add(cnt2[i + j], (ll)cnt2[i] * c[n - i - 1][j - 1]);
        add(cnt2[i + 1], cnt2[i]);
    }
    int answer = (cnt2[n] - cnt[n] + MOD) % MOD;
//     for (int i = 0; i < n; i++) add(answer, cnt[i]);
    cout << answer << endl;
	return 0;
}