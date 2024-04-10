#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <iomanip>
#include <cassert>
#include <cstring>
#include <sstream>
#include <numeric>
#include <cstdio>
#include <bitset>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;

#define pb push_back
#define F first
#define S second
#define _sz(x) ((int)x.size())

const int N = 2e5 + 20, mod = 1e9 + 7;
int n, a[N];

int tot, ans = 1;

int tme = 0, t[N];
int mark[N];

int p2[N];

void pre () {
    for (int i = p2[0] = 1; i < N; i++)
        p2[i] = 2 * p2[i - 1] % mod;
}

void dfs (int v) {
    mark[v] = 1;
    t[v] = tme++;

    if (mark[a[v]] == 0) dfs(a[v]);
    else if (mark[a[v]] == 1) {
        int len = t[v] - t[a[v]] + 1;

        ans = 1ll * ans * (p2[len] + mod - 2) % mod;
        tot += len;
    }

    mark[v] = 2;
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    pre();

    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i], a[i]--;

    for (int i = 0; i < n; i++)
        if (!mark[i]) dfs(i);
        
    ans = 1ll * ans * p2[n - tot] % mod;

    cout << ans << '\n';
}