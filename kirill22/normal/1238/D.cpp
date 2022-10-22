#include<bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ans = ((n * (n - 1)) / 2);
    char tmp = s[0];
    int res = 0;
    vector<int> a;
    for (int i = 0; i < n; i++) {
        if (tmp != s[i]) {
            a.push_back(res);
            res = 1;
            tmp = s[i];
        }
        else {
            res++;
        }
    }
    a.push_back(res);
    res = 0;
    n = a.size();
    for (int i = 1; i < n; i++) {
        res += a[i] + a[i - 1] - 1;
    }
    cout << ans - res;
}