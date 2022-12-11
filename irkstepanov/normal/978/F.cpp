#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <cmath>
#include <algorithm>
#include <assert.h>
#include <vector>
#include <cstring>
#include <bitset>
#include <random>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
//typedef __int128 ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef double ld;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector<pll> a(n);
    vector<ll> init(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first;
        a[i].second = i;
        init[i] = a[i].first;
    }

    sort(all(a));
    vector<int> ans(n);

    vector<vector<int> > g(n);
    while (m--) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].pb(v);
        g[v].pb(u);
    }

    int cnt = 0;
    int curr = 0;
    for (int i = 0; i < n; ++i) {
        ++curr;
        int z = cnt;
        for (int to : g[a[i].second]) {
            if (init[a[i].second] > init[to]) {
                --z;
            }
        }
        ans[a[i].second] = z;
        if (i + 1 < n && a[i].first != a[i + 1].first) {
            cnt += curr;
            curr = 0;
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << ans[i] << " ";
    }
    cout << "\n";

}