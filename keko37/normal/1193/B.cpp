#include<bits/stdc++.h>

using namespace std;

typedef long long llint;

const int MAXN = 100005;

int n, m, k;
llint d[MAXN], w[MAXN], p[MAXN];
map <int, llint> mp[MAXN];
vector <int> v[MAXN];

void spoji (int x, int y) {
    if (mp[x].size() < mp[y].size()) swap(mp[x], mp[y]);
    for (auto par : mp[y]) {
        mp[x][par.first] += par.second;
    }
}

void dodaj (int x) {
    mp[x][d[x]] += w[x];
    auto it = mp[x].find(d[x]); it++;
    llint ofs = 0;
    while (it != mp[x].end()) {
        ofs += (it -> second);
        if (ofs <= w[x]) {
            it = mp[x].erase(it);
        } else {
            mp[x][it -> first] = ofs - w[x];
            break;
        }
    }
}

void calc (int x) {
    for (auto sus : v[x]) {
        spoji(x, sus);
    }
    if (d[x] != 0) dodaj(x);
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> k;
    for (int i=2; i<=n; i++) {
        cin >> p[i];
        v[p[i]].push_back(i);
    }
    for (int i=0; i<m; i++) {
        llint vv, dd, ww;
        cin >> vv >> dd >> ww;
        d[vv] = dd;
        w[vv] = ww;
    }
    for (int i=n; i>=1; i--) calc(i);
    llint sol = 0;
    for (auto par : mp[1]) sol += par.second;
    cout << sol << endl;
    return 0;
}