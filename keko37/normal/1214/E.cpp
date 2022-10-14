#include<bits/stdc++.h>

using namespace std;

const int MAXN = 100005;

int n;
int d[MAXN];
pair <int, int> p[MAXN];
vector <int> v;
vector < pair <int, int> > e;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> d[i];
        p[i] = {d[i], 2*i+1};
    }
    sort(p, p + n);
    reverse(p, p + n);
    for (int i=0; i<n; i++) {
        if (i > 0) e.push_back({p[i].second, p[i-1].second});
        v.push_back(p[i].second);
    }
    for (int i=0; i<n; i++) {
        int ind = p[i].second + 1;
        int pos = i + p[i].first;
        if (pos == v.size()) {
            e.push_back({v.back(), ind});
            v.push_back(ind);
        } else {
            e.push_back({v[pos-1], ind});
        }
    }
    for (auto par : e) {
        cout << par.first << " " << par.second << '\n';
    }
    return 0;
}