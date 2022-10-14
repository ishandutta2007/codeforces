#include<bits/stdc++.h>

using namespace std;

const int INF = 1000000007;

int n;
vector < pair < pair <int, int> , pair <int, int> > > v;
vector <int> saz;
vector < pair <int, int> > sol;

int rjesi (int lef, int rig) {
    vector <int> ost;
    for (int i = lef; i <= rig; i++) {
        if (i == rig || v[i].first.second != v[i + 1].first.second) {
            ost.push_back(i);
        } else {
            sol.push_back({i, i + 1});
            i++;
        }
    }
    for (int i = 1; i < ost.size(); i += 2) {
        sol.push_back({ost[i - 1], ost[i]});
    }
    if (ost.size() % 2 == 1) return ost.back();
    return -1;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i=1; i<=n; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        v.push_back({{x, y}, {z, i}});
        saz.push_back(x);
    }
    sort(v.begin(), v.end());
    sort(saz.begin(), saz.end());
    saz.erase(unique(saz.begin(), saz.end()), saz.end());
    vector <int> r;
    /*cout << "---" << endl;
    for (int i = 0; i < v.size(); i++) {
        cout << v[i].first.first << " " << v[i].first.second << " " << v[i].second.first << endl;
    }
    cout << "---" << endl;*/
    for (auto x : saz) {
        int lef = lower_bound(v.begin(), v.end(), make_pair(make_pair(x, -INF), make_pair(-INF, -INF))) - v.begin();
        int rig = lower_bound(v.begin(), v.end(), make_pair(make_pair(x, INF), make_pair(INF, INF))) - v.begin();
        int ind = rjesi(lef, rig - 1);
        if (ind != -1) r.push_back(ind);
    }
    for (int i = 1; i < r.size(); i += 2) {
        sol.push_back({r[i - 1], r[i]});
    }
    for (auto par : sol) cout << v[par.first].second.second << " " << v[par.second].second.second << '\n';
    return 0;
}