#include<bits/stdc++.h>

using namespace std;

#define int long long


int f(int n) {
    if (n % 2 == 0) {
        return n / 2;
    }
    else {
        return n / 2 + 1;
    }
}

signed main() {
    int n;
    cin >> n;
    vector<int> a(n);
    int mx1 = 1e18, mx2 = -1e18;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mx1 = min(mx1, a[i]);
        mx2 = max(mx2, a[i]);
    }
    if (mx1 >= f(mx2)) {
        for (int i = 0; i < n; i++) {
            cout << -1 << " ";
        }
        return 0;
    }
    vector<int> ans(n, -1);
    int k = 0;
    multiset<int> mx;
    set<pair<int, int>> b;
    vector<int> used(n, false);
    int i = -1, t = 0;
    while (k < n) {
        t++;
        i = (i + 1) % n;
        if (b.size() == 0) {
            if (ans[i] == -1 && !used[i]) {
                b.insert({t, i});
                used[i] = true;
            }
            mx.insert(-a[i]);
        }
        else {
            while (b.size() > 0) {
                auto x = *b.begin();
                if (f(-(*mx.begin())) > a[i]) {
                    ans[x.second] = t - x.first;
                    k++;
                    mx.erase(mx.find(-a[x.second]));
                    b.erase(b.begin());
                }
                else {
                    break;
                }
            }
            if (ans[i] == -1 && !used[i]) {
                b.insert({t, i});
                used[i] = true;
            }
            mx.insert(-a[i]);
        }
    }
    for (auto c : ans) {
        cout << c << " ";
    }
}