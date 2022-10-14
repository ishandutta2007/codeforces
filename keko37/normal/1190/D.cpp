#include<bits/stdc++.h>

using namespace std;

const int MAXN = 400005;

typedef long long llint;

llint n, sol, uk;
llint x[MAXN], y[MAXN];
vector <llint> v, c[MAXN];
llint fen[MAXN];

void ubaci (llint x, llint k) {
    x++;
    for (; x < MAXN; x += x&-x) fen[x] += k;
}

llint upit (llint x) {
    x++;
    llint res = 0;
    for (; x > 0; x -= x&-x) res += fen[x];
    return res;
}

llint get (llint x, llint y) {
    if (x > y) return 0;
    if (x == 0) return upit(y);
    return upit(y) - upit(x-1);
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> x[i] >> y[i];
        v.push_back(x[i]);
        v.push_back(y[i]);
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    for (int i=0; i<n; i++) {
        x[i] = lower_bound(v.begin(), v.end(), x[i]) - v.begin();
        y[i] = lower_bound(v.begin(), v.end(), y[i]) - v.begin();
        c[y[i]].push_back(x[i]);
    }
    for (int i=(int)v.size(); i >= 0; i--) {
        if (c[i].empty()) continue;
        sort(c[i].begin(), c[i].end());
        for (auto p : c[i]) {
            llint curr = get(p, p);
            if (curr == 0) {
                ubaci(p, 1);
                uk++;
            }
        }
        llint res = uk * (uk + 1) / 2;
        llint prosli = -1;
        //cout << "bla " << i << "  ";
        for (auto p : c[i]) {
            llint medu = get(prosli + 1, p - 1);
            //cout << medu << " ";
            res -= medu * (medu + 1) / 2;
            prosli = p;
        }
        llint medu = get(prosli + 1, 2*n);
        //cout << medu << "  ";
        res -= medu * (medu + 1) / 2;
        //cout << res << endl;
        sol += res;
    }
    cout << sol;
    return 0;
}