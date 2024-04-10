#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;
typedef vector <int> vi;

const int LOG = 14;

int n;
vector <int> v[20];
vector <pi> e;

void spoji (vi &a, vi &b) {
    for (int i = 0; i < a.size(); i++) {
        e.push_back({a[i], b[i]});
    }
}

void build (vi p) {
    if (p.size() == 1) return;
    int siz = p.size();
    vi a, b;
    for (int i = 0; i < siz; i++) {
        if (2 * i < siz) a.push_back(p[i]); else b.push_back(p[i]);
    }
    build(a);
    build(b);
    spoji(a, b);
}

void ispis () {
    cout << e.size() << '\n';
    for (auto par : e) {
        cout << par.first << " " << par.second << '\n';
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    int curr = 1;
    int mx = 0;
    for (int i = 0; i < LOG; i++) {
        if (n & (1 << i)) {
            mx = max(mx, i);
            for (int j = 0; j < (1 << i); j++) {
                v[i].push_back(curr);
                curr++;
            }
            build(v[i]);
        }
    }
    for (int i = 0; i < mx - 1; i++) {
        if (v[i].empty()) continue;
        int siz = v[i].size();
        if (siz != (1 << (i + 1))) {
            vi bla;
            for (int j = 0; j < siz; j++) {
                bla.push_back(v[mx].back());
                v[mx].pop_back();
            }
            spoji(v[i], bla);
            for (auto x : bla) v[i].push_back(x);
        }
        if (v[i + 1].empty()) {
            swap(v[i], v[i + 1]);
        } else {
            spoji(v[i], v[i + 1]);
            for (auto x : v[i]) v[i + 1].push_back(x);
        }
    }
    ispis();
    return 0;
}