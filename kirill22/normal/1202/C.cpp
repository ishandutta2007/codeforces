#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q;
    cin >> q;
    while (q--) {
        string s;
        cin >> s;
        int n = s.size();
        int minh = 0, mind = 0, maxh = 0, maxd = 0;
        int x = 0, y = 0;
        vector<pair<int, int>> a;
        vector<int> MINH(1, 0);
        vector<int> MIND(1, 0);
        vector<int> MAXH(1, 0);
        vector<int> MAXD(1, 0);
        a.push_back({0, 0});
        for (auto c : s) {
            if (c == 'W') {
                x++;
            }
            if (c == 'S') {
                x--;
            }
            if (c == 'D') {
                y++;
            }
            if (c == 'A') {
                y--;
            }
            a.push_back({x, y});
            minh = min(minh, x);
            mind = min(mind, y);
            maxh = max(maxh, x);
            maxd = max(maxd, y);
            MINH.push_back(minh);
            MIND.push_back(mind);
            MAXH.push_back(maxh);
            MAXD.push_back(maxd);
        }
        int d = (maxd - mind + 1), h =  (maxh - minh + 1);
        int ans = d * h;
        n = a.size();
        minh = a[n - 1].first, mind = a[n - 1].second, maxh = a[n - 1].first, maxd = a[n - 1].second;
        for (int i = a.size() - 1; i >= 0; i--) {
            d = 0, h = 0;
            int  d2 = 0, h2 = 0;
            if (i != 0) {
                d = MAXD[i - 1];
                h = MAXH[i - 1];
                d2 = MIND[i - 1];
                h2 = MINH[i - 1];
            }
            minh = min(minh, a[i].first);
            mind = min(mind, a[i].second);
            maxh = max(maxh, a[i].first);
            maxd = max(maxd, a[i].second);
            if (i == 0) {
                       ans = min(ans, (max(1ll, maxd + 1) - min(d2, mind + 1) + 1) * (max(h ,maxh) - min(h2, minh) + 1));
                        ans = min(ans, (max(d, maxd - 1) - min(-1ll, mind - 1) + 1) * (max(h ,maxh) - min(h2, minh) + 1));
                        ans = min(ans, (max(d, maxd) - min(d2, mind) + 1) * (max(1ll ,maxh + 1) - min(h2, minh + 1) + 1));
                        ans = min(ans, (max(d, maxd) - min(d2, mind) + 1) * (max(h ,maxh - 1) - min(-1ll, minh - 1) + 1));

            }
            else {
                ans = min(ans, (max(max(d, a[i - 1].second + 1), maxd + 1) - min(d2, mind + 1) + 1) * (max(h ,maxh) - min(h2, minh) + 1));
                ans = min(ans, (max(d, maxd - 1) - min(min(d2, a[i - 1].second - 1), mind - 1) + 1) * (max(h ,maxh) - min(h2, minh) + 1));
                ans = min(ans, (max(d, maxd) - min(d2, mind) + 1) * (max(max(h, a[i - 1].first + 1) ,maxh + 1) - min(h2, minh + 1) + 1));
                ans = min(ans, (max(d, maxd) - min(d2, mind) + 1) * (max(h ,maxh - 1) - min(min(h2, a[i - 1].first - 1), minh - 1) + 1));

            }
        }
        cout << ans << endl;

    }
}