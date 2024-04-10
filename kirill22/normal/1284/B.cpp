#include<bits/stdc++.h>
 
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    long long ans = 0;
    int cnt = n;
    vector<int> mx, mn;
    for (int i = 0; i < n; i++) {
        int d;
        cin >> d;
        vector<int> a(d);
        for (int j = 0; j < d; j++) {
            cin >> a[j];
        }
        int ok = 0;
        for (int j = 0; j + 1 < d; j++) {
            ok |= (a[j] < a[j + 1]);
        }
        if (ok) {
            cnt--;
            ans += 2 * cnt + 1;
        } else {
            mx.push_back(a[0]);
            mn.push_back(a[d - 1]);
        }
    }
    sort(mx.begin(), mx.end());
    sort(mn.begin(), mn.end());
    int j = 0;
    for (auto x : mx) {
        while (j < (int) mn.size() && mn[j] < x) {
            j++;
        }
        ans += j;
    }
    cout << ans;
}