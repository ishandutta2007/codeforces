#include <bits/stdc++.h>
using namespace std;
string a;
int main() {
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cin >> a;
        int p = 0;
        while (p < n && a[p] == '0') {
            cout << 0;
            p++;
        }
        p = n - 1;
        int cnt = 0;
        while (p >= 0 && a[p] == '1') {
            cnt++;
            p--;
        }
        int sum = 0;
        for (int i = 0; i < n; i++)
            if (a[i] == '1') sum++;
        if (sum != cnt) cout << 0;
        for (int i = 0; i < cnt; i++) cout << 1;
        cout << endl;
    }
}