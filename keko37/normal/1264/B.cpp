#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef vector <int> vi;

int a, b, c, d;
vi v, r, t;

vi spoji (vi vv, vi rr) {
    vi res;
    for (int i = 0; i < vv.size(); i++) {
        res.push_back(vv[i]);
        if (i < rr.size()) res.push_back(rr[i]);
    }
    return res;
}

bool check (vi vv) {
    for (int i = 1; i < vv.size(); i++) {
        if (abs(vv[i] - vv[i - 1]) > 1) return 0;
    }
    return 1;
}

void ispis (vi vv) {
    for (auto x : vv) cout << x << " ";
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> a >> b >> c >> d;
    for (int i = 0; i < a; i++) v.push_back(0);
    for (int i = 0; i < c; i++) v.push_back(2);
    for (int i = 0; i < b; i++) r.push_back(1);
    for (int i = 0; i < d; i++) r.push_back(3);
    if (abs((int)(v.size() - r.size())) > 1) {
        cout << "NO";
        return 0;
    }
    bool naso = 0;
    if (!naso && v.size() >= r.size()) {
        t = spoji(v, r);
        if (check(t)) naso = 1;
    }
    if (!naso && v.size() <= r.size()) {
        t = spoji(r, v);
        if (check(t)) naso = 1;
    }
    if (!naso) {
        cout << "NO";
    } else {
        cout << "YES\n";
        ispis(t);
    }
    return 0;
}