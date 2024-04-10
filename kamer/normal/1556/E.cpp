#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <queue>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <string>
#include <utility>
#include <iomanip>
#include <fstream>
#include <cmath>
using namespace std;
typedef long long ll;

struct RMQMIN {
    vector<vector<ll>> jmp;

    RMQMIN(const vector<ll>& V) {
        int N = V.size(), on = 1, depth = 1;
        while (on < N) on *= 2, depth++;
        jmp.assign(depth, V);
        for (int i = 0; i < depth - 1; i++) {
            for (int j = 0; j < N; j++) {
                jmp[i + 1][j] = min(jmp[i][j], jmp[i][min(N - 1, j + (1 << i))]);
            }
        }
    }

    ll query(int a, int b) {
        if (b <= a) return (ll) 1000000000000000000;
        int dep = 31 - __builtin_clz(b - a);
        return min(jmp[dep][a], jmp[dep][b - (1 << dep)]);
    }
};


struct RMQMAX {
    vector<vector<ll>> jmp;

    RMQMAX(const vector<ll>& V) {
        int N = V.size(), on = 1, depth = 1;
        while (on < N) on *= 2, depth++;
        jmp.assign(depth, V);
        for (int i = 0; i < depth - 1; i++) {
            for (int j = 0; j < N; j++) {
                jmp[i + 1][j] = max(jmp[i][j], jmp[i][min(N - 1, j + (1 << i))]);
            }
        }
    }

    ll query(int a, int b) {
        if (b <= a) return (ll) -1000000000000000000;
        int dep = 31 - __builtin_clz(b - a);
        return max(jmp[dep][a], jmp[dep][b - (1 << dep)]);
    }
};

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(14);
    int n, q;
    cin >> n >> q;
    vector<ll> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    vector<ll> pref_diff(n);
    pref_diff[0] = b[0] - a[0];
    for (int i = 1; i < n; i++) {
        pref_diff[i] = pref_diff[i - 1] + b[i] - a[i];
    }

    RMQMAX rmq_max(pref_diff);
    RMQMIN rmq_min(pref_diff);
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        l--;
        ll range_sum = pref_diff[r - 1] - (l == 0 ? 0 : pref_diff[l - 1]);
        if (range_sum != 0) {
            cout << "-1\n";
            continue;
        }
        ll min_val = rmq_min.query(l, r);
        if (l > 0) min_val -= pref_diff[l - 1];
        if (min_val < 0) cout << "-1\n";
        else {
            ll max_val = rmq_max.query(l, r);
            
            if (l > 0) max_val -= pref_diff[l - 1];
            cout << max_val << "\n";
        }
    }
}