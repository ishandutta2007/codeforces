#include <iostream>
#include <fstream>
#include <set>
#include <string>
#include <map>
#include <queue>
#include <algorithm>
#include <deque>
#include <memory.h>
#include <assert.h>
#include <random>
#include <cstring>
#include <cmath>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
//typedef __ll128 bigll;
typedef pair<int, int> pii;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n, k, m;
    cin >> n >> k >> m;
    vector<string> s(n);
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }

    vector<ll> cost(n);
    for (int i = 0; i < n; ++i) {
        cin >> cost[i];
    }

    map<string, ll> mapa;

    while (k--) {
        int r;
        cin >> r;
        ll best = ll(1e18);
        vector<int> v(r);
        for (int i = 0; i < r; ++i) {
            cin >> v[i];
            --v[i];
            best = min(best, cost[v[i]]);
        }
        for (int i = 0; i < r; ++i) {
            mapa[s[v[i]]] = best;
        }
    }

    ll ans = 0;

    while (m--) {
        string t;
        cin >> t;
        ans += mapa[t];
    }

    cout << ans << "\n";

}