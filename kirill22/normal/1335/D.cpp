#include <bits/stdc++.h>

using namespace std;

#define int long long
#define fi first
#define se second
#define ld long double
#define yes cout << "YES\n";
#define no cout << "NO\n";

void get(string &s, int j) {
    if (s[j] == '1') {
        s[j] = '2';
    }
    else s[j] = '1';
}

signed main() {
    int q;
    cin >> q;
    while (q--) {
        int n = 9;
        vector<string> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        get(a[0], 0);
        get(a[1], 3);
        get(a[2], 6);
        get(a[3], 1);
        get(a[4], 4);
        get(a[5], 7);
        get(a[6], 2);
        get(a[7], 5);
        get(a[8], 8);
        for (int i = 0; i < n; i++) {
            cout << a[i] << '\n';
        }
    }
}