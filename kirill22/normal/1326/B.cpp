#include<bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int tmp = 0;
    for (int i = 0; i < n; i++) {
        int x = a[i] + tmp;
        cout << x << " ";
        tmp = max(tmp, x);
    }
}