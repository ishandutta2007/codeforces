#include <bits/stdc++.h>

using namespace std;

#define int long long
#define double long double

struct Lemming {
    int m, v, i;
    
    bool operator < (const Lemming &l) const {
        return make_tuple(m, v, i) > make_tuple(l.m, l.v, l.i);
    }
};

int n, k, h;
vector<Lemming> a;

bool check(double t, vector<int> &ans) {
    int p = k;
    for (auto i: a) {
        if (p <= t * i.v) {
            ans[p - 1] = i.i;
            --p;
            if (p == 0) return true;
        }
    }
    return false;
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    
    cin >> n >> k >> h;
    a.resize(n);
    for (int i = 0; i < n; ++i) cin >> a[i].m;
    for (int i = 0; i < n; ++i) cin >> a[i].v;
    for (int i = 0; i < n; ++i) a[i].i = i;
    sort(a.begin(), a.end());
    
    vector<int> ans(k);
    double left = 0, right = 1e9 + 5;
    for (int it = 0; it < 100; ++it) {
        double mid = (left + right) / 2;
        if (check(mid, ans)) right = mid;
        else left = mid;
    }
    check(right, ans);
    for (auto i: ans) {
        cout << i + 1 << ' ';
    }
}