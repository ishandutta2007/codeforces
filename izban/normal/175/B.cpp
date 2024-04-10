#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = -1;



int main() {
#ifdef HOME
    freopen("in", "r", stdin);
#endif

    int n;
    bool first = 1;
    while (cin >> n) {
        if (first) first = 0;
        else cout << endl;
        vector<pair<int, string> > a(n);
        for (int i = 0; i < n; i++) cin >> a[i].second >> a[i].first;

        map<string, int> mp;
        for (int i = 0; i < n; i++) mp[a[i].second] = max(mp[a[i].second], a[i].first);

        a.clear();
        for (auto it : mp) a.push_back(make_pair(it.second, it.first));

        cout << a.size() << endl;
        n = a.size();
        sort(a.begin(), a.end());
        for (int i = 0; i < n; i++) {
            int cc = 0;
            for (int j = 0; j < n; j++) if (a[i].first >= a[j].first) cc++;

            string s = "";
            // cc / n >= 99 / 100
            if (cc * 100 >= 99 * n) {
                s = "pro";
            } else if (cc * 100 >= 90 * n) {
                s = "hardcore";
            } else if (cc * 100 >= 80 * n) {
                s = "average";
            } else if (cc * 100 >= 50 * n) {
                s = "random";
            } else {
                s = "noob";
            }
            cout << a[i].second << " " << s << endl;
        }
    }

    return 0;
}