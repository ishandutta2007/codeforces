#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<pair<int, int>> a(n, {0, 0});
    int mx;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a[i].second = x;
        while (x % 2 == 0) {
            a[i].first++;
            x /= 2;
        }
    }
    sort(a.begin(), a.end());
    mx = a[0].first;
    vector<pair<int,int>> b;
    int i = 1, c = 1, ii = 0;
    while (i < n) {
        if (a[i].first == mx) {
            c++;
        }
        else {
            b.push_back({c, ii});
            c = 1;
            ii = i;
            mx = a[i].first;
        }
        i++;
    }
    b.push_back({c, ii});
    sort(b.rbegin(), b.rend());
    cout << n - b[0].first << endl;
    for (int i = 0; i < n; i++) {
        if (i < b[0].second || i >= b[0].second + b[0].first) {
            cout << a[i].second << " ";
        }
    }
}