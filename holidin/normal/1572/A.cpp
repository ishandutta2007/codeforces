

//#pragma GCC optimize 03
#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <map>
#include <algorithm>
#include <set>
#include <math.h>
#include <random>
#include <bitset>
#include <map>
#include <unordered_map>
#include <queue>
#include <time.h>
#include <iomanip>
#include <cmath>
#include <cassert>
#include <functional>

#define fi first
#define se second
#define ll long long
#define int long long
#define ld long double
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define pb push_back
using namespace std;
mt19937 rnd;

void solve(int) {
    int n, k;
    cin >> n;
    vector<vector<int> > g(n);
    vector<int> cnt(n);
    set<int> can;
    int read = 0;
    for (int i = 0; i < n; ++i) {
        cin >> cnt[i];
        for (int j = 0; j < cnt[i]; ++j) {
            int x;
            cin >> x;
            --x;
            g[x].push_back(i);
        }
        if (cnt[i] == 0) {
            can.insert(i);
        }
    }
    int last = 0;
    int it = 1;
    while (can.size() > 0) {
        if (can.lower_bound(last) == can.end()) {
            last =  0;
            ++it;
        }
        int x = *can.lower_bound(last);
        can.erase(x);
        last = x;
        ++read;
        for (auto v : g[x]) {
            --cnt[v];
            if (cnt[v] == 0) {
                can.insert(v);
            }
        }
    }
    if (read == n) {
        cout << it << "\n";
    } else {
        cout << -1 << "\n";
    }



}

signed main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // local
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.precision(30);
    int test = 1;
    cin >> test;
    int cnt = 0;
    //testt();
    //return 0;
    while (test--) {
        ++cnt;
        solve(cnt);
    }

}