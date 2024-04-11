#include <bits/stdc++.h>

using namespace std;

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int n;
    string s;
    cin >> n >> s;
    set<int> a;
    for (auto i: s) {
        a.insert(i);
    }
    int maxcnt = a.size();

    multiset<int> d;
    int right = 0;
    int ans = n;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        while (right < n && cnt < maxcnt) {
            if (d.find(s[right]) == d.end()) cnt++;
            d.insert(s[right++]);
        }
        if (cnt == maxcnt) ans = min(ans, right - i);
        d.erase(d.find(s[i]));
        if (d.find(s[i]) == d.end()) cnt--;
    }

    cout << ans << endl;
}