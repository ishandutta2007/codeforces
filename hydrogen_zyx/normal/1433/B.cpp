#include <bits/stdc++.h>
using namespace std;
int a[100];
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int cnt = 0, n;
        bool f = 0;
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> a[i];
        for (int i = 1; i <= n; i++)
            if (a[i] == 0) cnt++;
        int p = 1;
        while (a[p] == 0) cnt--, p++;
        p = n;
        while (a[p] == 0) cnt--, p--;
        cout << cnt << endl;
    }
}