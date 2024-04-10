#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[200000];
bool vis[200000];

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            int b;
            cin >> b;
            a[b] = i;
        }
        for (int i = 1; i <= n; i++) vis[i] = 0;
        int nxt = 0;
        bool f = 1;
        for (int i = 1; i <= n; i++) {
            if (vis[a[i]]) f = 0;
            vis[a[i]] = 1;
            if (nxt == 0) {
                if (vis[a[i] + 1] == 0 && a[i] != n) nxt = a[i] + 1;
            } else {
                if (a[i] != nxt)
                    f = 0;
                else {
                    if (vis[a[i] + 1] == 0 && a[i] != n)
                        nxt = a[i] + 1;
                    else
                        nxt = 0;
                }
            }
        }
        if (f)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}