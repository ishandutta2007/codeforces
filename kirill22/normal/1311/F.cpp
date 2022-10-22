#include<bits/stdc++.h>

using namespace std;

#define int long long

vector<int> f, cnt;

void update(int i, int x) {
    while (i < f.size()) {
        f[i] += x;
        cnt[i]++;
        i = i | (i + 1);
    }
}

pair<int, int> get(int x) {
    int res = 0, c = 0;
    while (x >= 0) {
        res += f[x];
        c += cnt[x];
        x = (x & (x + 1)) - 1;
    }
    return {res, c};
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    vector<int> b;
    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
    }
    for (int i = 0; i < n; i++) {
        cin >> a[i].second;
        b.push_back(a[i].second);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    b.resize(unique(b.begin(), b.end()) - b.begin());
    f.resize(b.size(), 0);
    cnt.resize(b.size(), 0);
    map<int, int> mp;
    for (int i = 0; i < b.size(); i++) mp[b[i]] = i;
    for (auto &el : a) el.second = mp[el.second];
    //for (auto el : a) cout << el.first << " " << el.second << endl;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        auto p = get(a[i].second);
        if (p.second != 0) {
            ans = ans + p.second * a[i].first - p.first;
        }
        //cout << p.first << " " << p.second << endl;
        update(a[i].second, a[i].first);
    }
    cout << ans;
}