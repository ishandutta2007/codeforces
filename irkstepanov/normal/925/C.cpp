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
//typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;

int oldest(ll val) {
    int pos = 0;
    while (val > 1) {
        val >>= 1;
        ++pos;
    }
    return pos;
}

bool bit(ll mask, int pos) {
    return (mask >> pos) & 1;
}

const int rmax = 60;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //ifstream cin("input.txt");

    int n;
    cin >> n;

    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<vector<ll> > v(rmax);
    for (int i = 0; i < n; ++i) {
        v[oldest(a[i])].pb(a[i]);
    }

    vector<ll> ans;
    for (int r = rmax - 1; r >= 0; --r) {
        int cnt = 0;
        for (ll val : ans) {
            if (bit(val, r)) {
                ++cnt;
            }
        }
        if (cnt < sz(v[r]) - 1) {
            cout << "No\n";
            return 0;
        }
        if (v[r].empty()) {
            continue;
        }
        vector<ll> nx;
        nx.pb(v[r][0]);
        int ptr = 1;
        int z = 0;
        while (ptr < sz(v[r])) {
            nx.pb(ans[z]);
            ++z;
            if (bit(nx.back(), r)) {
                nx.pb(v[r][ptr]);
                ++ptr;
                continue;
            }
        }
        while (z < sz(ans)) {
            nx.pb(ans[z]);
            ++z;
        }
        ans = nx;
    }

    cout << "Yes\n";
    for (int i = 0; i < sz(ans); ++i) {
        cout << ans[i] << " ";
    }
    cout << "\n";

}