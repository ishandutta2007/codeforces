#include<bits/stdc++.h>

using namespace std;

typedef long long llint;

const int MAXN = 1005;

int n;
int x[MAXN], y[MAXN];
vector <int> v[2][2], sol;

void rjesi () {
    v[0][0].clear();
    v[0][1].clear();
    v[1][0].clear();
    v[1][1].clear();
    for (int i = 0; i < n; i++) {
        v[abs(x[i]) % 2][abs(y[i]) % 2].push_back(i);
    }
    int black = v[0][0].size() + v[1][1].size();
    int white = v[0][1].size() + v[1][0].size();
    if (black > 0 && white > 0) {
        for (auto x : v[0][0]) sol.push_back(x);
        for (auto x : v[1][1]) sol.push_back(x);
        return;
    }
    if (black == 0) {
        for (int i = 0; i < n; i++) x[i]++;
        rjesi();
        return;
    }
    if (v[0][0].size() > 0 && v[1][1].size() > 0) {
        sol = v[0][0];
        return;
    }
    for (int i = 0; i < n; i++) {
        if (x[i] % 2 != 0) x[i]++;
        if (y[i] % 2 != 0) y[i]++;
        x[i] /= 2;
        y[i] /= 2;
    }
    rjesi();
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }
    rjesi();
    cout << sol.size() << endl;
    for (auto x : sol) cout << x + 1 << " ";
    return 0;
}