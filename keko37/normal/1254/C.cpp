#include<bits/stdc++.h>

using namespace std;

typedef long long llint;

int n;
vector < pair <llint, int> > v;
vector <int> lef, rig;

llint pitaj (int t, int a, int b, int c) {
    llint res;
    cout << 3 - t << " " << a << " " << b << " " << c << endl;
    cin >> res;
    return res;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    int ind = 2;
    for (int i = 3; i <= n; i++) {
        if (pitaj(1, 1, i, ind) == 1) ind = i;
    }
    for (int i = 2; i <= n; i++) {
        if (i == ind) continue;
        v.push_back({pitaj(2, 1, ind, i), i});
    }
    sort(v.begin(), v.end());
    for (int i = 1; i < v.size(); i++) {
        if (pitaj(1, 1, v[i - 1].second, v[i].second) == 1) {
            lef.push_back(v[i - 1].second);
        } else {
            rig.push_back(v[i - 1].second);
        }
    }
    lef.push_back(v.back().second);
    cout << 0 << " " << 1 << " " << ind << " ";
    for (int i = 0; i < lef.size(); i++) cout << lef[i] << " ";
    for (int i = (int) rig.size() - 1; i >= 0; i--) cout << rig[i] << " ";
    return 0;
}