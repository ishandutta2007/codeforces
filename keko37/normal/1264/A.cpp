#include<bits/stdc++.h>

using namespace std;

typedef long long llint;

const int MAXN = 400005;

int t, n;
int a[MAXN];
vector <int> v, r;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++) cin >> a[i];
        v.clear(); r.clear();
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            cnt++;
            if (i == n-1 || a[i] != a[i + 1]) {
                v.push_back(cnt);
                cnt = 0;
            }
        }
        int sum = 0;
        for (auto x : v) {
            if ((sum + x) * 2 > n) break;
            sum += x;
            r.push_back(x);
        }
        if (r.empty()) {
            cout << "0 0 0\n";
            continue;
        }
        int mn = r[0];
        int ss = 0;
        int ind = -1;
        for (int i = 1; i < v.size(); i++) {
            ss += v[i];
            if (ss > mn) {
                ind = i;
                break;
            }
        }
        if (ind == -1 || mn >= sum - ss - mn) {
            cout << "0 0 0\n";
            continue;
        }
        cout << mn << " " << ss << " " << sum - ss - mn << '\n';
    }
    return 0;
}