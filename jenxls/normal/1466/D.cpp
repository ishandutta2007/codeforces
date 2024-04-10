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

#define int ll

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;

#define pb push_back
#define F first
#define S second
#define _sz(x) ((int)x.size())

const int N = 2e5 + 20;
int T;
int n, w[N], deg[N];
vector <pii> vec;

int32_t main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    cin >> T;

    while (T--) {
        int ans = 0;

        cin >> n;
        for (int i = 0; i < n; i++) cin >> w[i], ans += w[i];

        for (int i = 0; i < n; i++) {
            deg[i] = 0;
        }
        vec.clear();

        for (int i = 0, u, v; i < n - 1; i++) {
            cin >> u >> v;
            u--, v--;
            deg[u]++;
            deg[v]++;
        }

        for (int i = 0; i < n; i++) vec.pb({w[i], deg[i]});

        sort(vec.begin(), vec.end());
        reverse(vec.begin(), vec.end());

        int p = 0, cnt = 0;
        for (int i = 0; i < n - 1; i++) {
            if (i) {
                while (vec[p].S <= cnt + 1) {
                    p++;
                    cnt = 0;
                }

                ans += vec[p].F;
                cnt++;
            }

            cout << ans << ' ';
        }
        cout << '\n';
    }
}