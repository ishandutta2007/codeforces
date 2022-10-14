#include<bits/stdc++.h>

using namespace std;

int n;
string a, b;
vector <int> pa, pb;
vector < pair <int, int> > v;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> a >> b;
    for (int i=0; i<n; i++) {
        if (a[i] == b[i]) continue;
        if (a[i] == 'a') pa.push_back(i); else pb.push_back(i);
    }
    if ((pa.size() + pb.size()) % 2) {
        cout << -1;
        return 0;
    }
    for (int i=1; i<pa.size(); i += 2) {
        int x = pa[i - 1], y = pa[i];
        v.push_back({x, y});
    }
    for (int i=1; i<pb.size(); i += 2) {
        int x = pb[i - 1], y = pb[i];
        v.push_back({x, y});
    }
    if (pa.size() & 1) {
        int x = pa.back(), y = pb.back();
        v.push_back({y, y});
        v.push_back({x, y});
    }
    cout << v.size() << '\n';
    for (auto par : v) cout << par.first + 1 << " " << par.second + 1 << '\n';
    return 0;
}