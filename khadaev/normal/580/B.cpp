#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, d;
    cin >> n >> d;
    vector<pair<int, int> > v;
    for (int i = 0; i < n; ++i) {
        pair<int, int>tmp;
        cin >> tmp.first >> tmp.second;
        v.push_back(tmp);
        };
    sort(v.begin(), v.end());
    //for (int i = 0; i < n; ++i) cout << v[i].first << " " << v[i].second << endl;
    long long sumv = 0, ans = 0;
    int j = 0, minv;
    for (int i = 0; i < n; ++i) {
        if (i > 0) sumv -= v[i - 1].second;
        while ((j < n) && (v[j].first < v[i].first + d)) {
            sumv += v[j].second;
            //cout << sumv << endl;
            ++j;
            };
        ans = max(ans, sumv);
        };
    cout << ans;
};