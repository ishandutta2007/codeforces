#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;
typedef vector <int> vi;

const int MAXN = 55;

int n;
int p[MAXN];
vector <vi> out;

vi makni (vi v) {
    vi res;
    for (auto x : v) {
        if (x != 0) res.push_back(x);
    }
    return res;
}

void ispis (vi v) {
    v = makni(v);
    if (v.size() <= 1) return;
    out.push_back(v);
    vector <vi> r;
    int curr = 1;
    for (auto len : v) {
        vi tmp;
        for (int i = 0; i < len; i++) {
            tmp.push_back(p[curr + i]);
        }
        curr += len;
        r.push_back(tmp);
    }
    reverse(r.begin(), r.end());
    curr = 1;
    for (int i = 0; i < r.size(); i++) {
        for (int j = 0; j < r[i].size(); j++) {
            p[curr] = r[i][j];
            curr++;
        }
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }
    int lo = 1, hi = n;
    while (lo < hi) {
        int mn = 1e9, ind_mn = -1;
        for (int i = lo; i <= hi; i++) {
            if (p[i] < mn) {
                mn = p[i];
                ind_mn = i;
            }
        }
        ispis({lo - 1, ind_mn - lo + 1, hi - ind_mn, n - hi});
        int mx = 0, ind_mx;
        for (int i = lo; i <= hi; i++) {
            if (p[i] > mx) {
                mx = p[i];
                ind_mx = i;
            }
        }
        ispis({lo - 1, ind_mx - lo + 1, hi - ind_mx - 1, 1, n - hi});
        lo++; hi--;
    }
    cout << out.size() << '\n';
    for (int i = 0; i < out.size(); i++) {
        cout << out[i].size() << " ";
        for (auto x : out[i]) cout << x << " ";
        cout << '\n';
    }
    return 0;
}