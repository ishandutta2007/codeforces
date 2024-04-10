#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

const int MAXN = 100005;

int n, p, mx, lef;
int a[MAXN], b[MAXN * 2];
set <int> st[MAXN];
vector <int> v;

inline int calc (int lim) {
    return upper_bound(a, a + n, lim) - a;
}

int get (int x) {
    int sol = 1;
    for (int i = 0; i < n; i++) {
        if (b[x + i] - i <= 0) return 0;
        sol = (llint) sol * (b[x + i] - i) % p;
    }
    return sol;
}

void makni (int lo, int hi, int ost) {
    //cout << "makni " << lo << " " << hi << "  " << ost << endl;
    while (1) {
        auto it = st[ost].lower_bound(lo);
        if (it == st[ost].end() || (*it) > hi) {
            break;
        } else {
            st[ost].erase(it);
            //cout << "micem " << *it << endl;
        }
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> p;
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    mx = a[n - 1]; lef = mx - (n - 1);
    for (int i = 0; i < n; i++) {
        st[i % p].insert(i);
    }
    for (int i = 0; i <= 2*n; i++) {
        b[i] = calc(lef + i);
        int lo = max(max(0, i - b[i]), i - (n - 1));
        int hi = min(n - 1, i);
        int ost = ((i - b[i]) % p + p) % p;
        if (lo <= hi) makni(lo, hi, ost);
    }
    for (int i = 0; i < p; i++) {
        for (auto x : st[i]) v.push_back(x);
    }
    cout << v.size() << endl;
    sort(v.begin(), v.end());
    for (auto x : v) cout << lef + x << " ";
    return 0;
}