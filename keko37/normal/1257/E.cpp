#include<bits/stdc++.h>

using namespace std;

int siz[3];
vector <int> v, r;

int lis () {
    for (auto x : v) {
        int pos = lower_bound(r.begin(), r.end(), x) - r.begin();
        if (pos == r.size()) r.push_back(x); else r[pos] = x;
    }
    return r.size();
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> siz[0] >> siz[1] >> siz[2];
    for (int i = 0; i < 3; i++) {
        vector <int> tmp;
        for (int j = 0; j < siz[i]; j++) {
            int x; cin >> x;
            tmp.push_back(x);
        }
        sort(tmp.begin(), tmp.end());
        for (auto x : tmp) v.push_back(x);
    }
    cout << v.size() - lis();
    return 0;
}