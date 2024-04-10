#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

const int MAXN = 1000005;

int n, k, m, ofs = 1, br;
set <pi> st;
int t[MAXN * 4], prop[MAXN * 4];

void propagate (int x) {
    if (prop[x] == 0) return;
    if (x < ofs) {
        prop[2 * x] += prop[x];
        prop[2 * x + 1] += prop[x];
    }
    t[x] += prop[x];
    prop[x] = 0;
}

void update (int x, int from, int to, int lo, int hi, int val) {
    propagate(x);
    if (from <= lo && hi <= to) {
        prop[x] += val;
        propagate(x);
        return;
    }
    if (to < lo || hi < from) return;
    update(2 * x, from, to, lo, (lo + hi) / 2, val);
    update(2 * x + 1, from, to, (lo + hi) / 2 + 1, hi, val);
    t[x] = min(t[x * 2], t[x * 2 + 1]);
}

int calc (int x, int lo, int hi, int mn) {
    propagate(x);
    int val = min(mn, t[x]);
    if (val < br - hi) return -1;
    if (lo == hi) return lo;
    int lef = calc(2 * x, lo, (lo + hi) / 2, mn);
    if (lef != -1) return lef;
    return calc(2 * x + 1, (lo + hi) / 2 + 1, hi, min(mn, t[2 * x]));
}

void tour_init () {
    for (int i = 0; i < ofs; i++) {
        t[ofs + i] = -i;
    }
    for (int i = ofs - 1; i > 0; i--) {
        t[i] = min(t[i * 2], t[i * 2 + 1]);
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k >> m;
    while (ofs < 2*n + m + 1) ofs *= 2;
    tour_init();
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        int val = y + abs(x - k);
        if (st.find({x, y}) == st.end()) {
            update(1, val, ofs - 1, 0, ofs - 1, 1);
            st.insert({x, y});
        } else {
            update(1, val, ofs - 1, 0, ofs - 1, -1);
            st.erase({x, y});
        }
        br = st.size();
        cout << max(calc(1, 0, ofs - 1, 1e9) - n, 0) << '\n';
    }
    return 0;
}