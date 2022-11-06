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

const int N = 5e5 + 20;
int n, k, a[N];
bool mark[N];

const int inf = 1e9 + 20;
int mn[N];

int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    cin >> n >> k;

    for (int i = 0; i < n; i++) cin >> a[i], a[i] -= i;

    while (k--) {
        int x;
        cin >> x;
        x--;
        mark[x] = 1;
    }


    mn[0] = -inf;
    for (int i = 1; i < N; i++) mn[i] = +inf;

    int l_bound = 0;

    for (int i = 0; i < n; i++) {
        int p = upper_bound(mn + l_bound, mn + n, a[i]) - mn;

        if (p == l_bound) {
            if (mark[i]) return cout << "-1\n", 0;
            continue;
        }

        mn[p] = a[i];

        if (mark[i]) {
            l_bound = p;
            for (int i = p + 1; i < N && mn[i] < +inf; i++) mn[i] = +inf;
        }
    }

    int ans = l_bound;
    for (int i = l_bound; i < N; i++)
        if (mn[i] < +inf) ans = i;

    cout << n - ans << '\n';
}