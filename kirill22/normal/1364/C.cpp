#include<bits/stdc++.h>

using namespace std;

#define int long long
#define fi first
#define se second
#define pii pair<int, int>
#define ld long double
#define pb push_back

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> b(n, -1);
    set<int> pos;
    int tmp = 0;
    for (int i = 0; i < n; i++) {
        pos.insert(i);
        if (a[i] > i + 1) {
            cout << -1;
            return 0;
        }
        while (tmp < a[i]) {
            if (pos.size() == 0) {
                cout << -1;
                return 0;
            }
            auto j = *pos.rbegin();
            pos.erase(j);
            b[j] = tmp;
            tmp++;
        }
    }
    for (int i = 0; i < n; i++) if (b[i] == -1) b[i] = 1e6;
    for (int i = 0; i < n; i++) cout << b[i] << " ";
}