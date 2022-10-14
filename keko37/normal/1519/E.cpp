#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <llint, llint> pi;

const int MAXN = 400005;

int n;
pi x[MAXN], y[MAXN];
int cx[MAXN], cy[MAXN];
int bio[MAXN];
vector <pi> saz, v[MAXN], sol;

pi normalize (llint a, llint b) {
    llint d = __gcd(a, b);
    return {a / d, b / d};
}

void sazmi () {
    sort(saz.begin(), saz.end());
    saz.erase(unique(saz.begin(), saz.end()), saz.end());
    for (int i = 1; i <= n; i++) {
        cx[i] = lower_bound(saz.begin(), saz.end(), x[i]) - saz.begin();
        cy[i] = lower_bound(saz.begin(), saz.end(), y[i]) - saz.begin();
    }
}

int dfs (int node) {
    bio[node] = 1;
    vector <int> tmp;
    for (auto pp : v[node]) {
        int sus = pp.first, ind = pp.second;
        if (bio[sus] == 0) {
            int ost = dfs(sus);
            if (ost == 0) {
                tmp.push_back(ind);
            } else {
                sol.push_back({ind, ost});
            }
        } else if (bio[sus] == 2) {
            tmp.push_back(ind);
        }
    }
    while (tmp.size() >= 2) {
        int a = tmp.back(); tmp.pop_back();
        int b = tmp.back(); tmp.pop_back();
        sol.push_back({a, b});
    }
    bio[node] = 2;
    if (tmp.size()) return tmp.back();
    return 0;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        llint a, b, c, d;
        cin >> a >> b >> c >> d;
        x[i] = normalize((a + b) * d, b * c);
        y[i] = normalize(a * d, (c + d) * b);
        saz.push_back(x[i]);
        saz.push_back(y[i]);
    }
    sazmi();
    for (int i = 1; i <= n; i++) {
        v[cx[i]].push_back({cy[i], i});
        v[cy[i]].push_back({cx[i], i});
    }
    for (int i = 0; i < saz.size(); i++) {
        if (bio[i] == 0) dfs(i);
    }
    cout << sol.size() << '\n';
    for (auto pp : sol) cout << pp.first << " " << pp.second << '\n';
    return 0;
}