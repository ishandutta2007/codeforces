// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

using ll = long long;
using ull = long unsigned long;
using ld = double long;

vector<int> transform_slow(vector<int> a) {
    map<int, int> cnt;
    for (int x : a) cnt[x]++;
    for (int& x : a) x = cnt[x];
    return a;
}

vector<int> transform_fast(vector<int> a) {
    vector<int> cnt(a.size() + 1);
    for (int x : a) cnt[x]++;
    for (int& x : a) x = cnt[x];
    return a;
}

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int& x : a) cin >> x;
        
        vector<vector<int>> b(n+1);
        b[0] = a;
        b[1] = transform_slow(b[0]);
        for (int i : ra(2, n+1)) {
            b[i] = transform_fast(b[i-1]);
        }

        int q;
        cin >> q;
        while (q--) {
            int x, k;
            cin >> x >> k;
            x--;
            k = min(k, n);
            cout << b[k][x] << '\n';
        }
    }
    
}