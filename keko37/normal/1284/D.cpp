#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

const int MAXN = 100005;

int n;
int a[MAXN], b[MAXN], c[MAXN], d[MAXN];
vector < pair <pi, int> > v;
set <pi> st;

bool sijeku (pi a, pi b) {
    return max(a.first, b.first) <= min(a.second, b.second);
}

pi unija (pi a, pi b) {
    return {min(a.first, b.first), max(a.second, b.second)};
}

void ubaci (int x, int y) {
    auto it = st.lower_bound({x, 0});
    if (it != st.end()) {
        pi p = *it;
        if (sijeku({x, y}, p)) {
            st.erase(it);
            pi res = unija({x, y}, p);
            x = res.first;
            y = res.second;
        }
    }

    it = st.lower_bound({x, 0});
    if (it != st.begin()) {
        it--;
        pi p = *it;
        if (sijeku({x, y}, p)) {
            st.erase(it);
            pi res = unija({x, y}, p);
            x = res.first;
            y = res.second;
        }
    }
    st.insert({x, y});
}

bool check (int x, int y) {
    auto it = st.lower_bound({x, 0});
    if (it != st.end()) {
        pi p = *it;
        if (sijeku({x, y}, p)) return 1;
    }

    it = st.lower_bound({x, 0});
    if (it != st.begin()) {
        it--;
        pi p = *it;
        if (sijeku({x, y}, p)) return 1;
    }

    return 0;
}

bool rjesi () {
    v.clear(); st.clear();
    for (int i = 0; i < n; i++) {
        v.push_back({{a[i], 0}, i});
        v.push_back({{b[i], 1}, i});
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++) {
        int tip = v[i].first.second;
        int ind = v[i].second;
        if (tip == 1) {
            ubaci(c[ind], d[ind]);
        } else {
            if (check(c[ind], d[ind])) return 1;
        }
    }
    return 0;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i] >> c[i] >> d[i];
    }
    bool naso = 0;
    naso |= rjesi();
    for (int i = 0; i < n; i++) {
        swap(a[i], c[i]);
        swap(b[i], d[i]);
    }
    naso |= rjesi();
    if (naso) cout << "NO"; else cout << "YES";
    return 0;
}