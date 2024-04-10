#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int vis[10000];
int cnt[10000];

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n;
    cin >> n;
    int l = 1, r = 2;
    while (r <= n) {
        cout << '?' << ' ' << l << ' ' << r << endl;
        cout.flush();
        int a;
        cin >> a;
        cout << '?' << ' ' << r << ' ' << l << endl;
        cout.flush();
        int b;
        cin >> b;
        if (a > b) {
            vis[l] = a;
        } else {
            vis[r] = b;
        }
        while (vis[l]) l++;
        while (vis[r] || l == r) r++;
    }
    int point = 0;
    for (int i = 1; i <= n; i++) {
        cnt[vis[i]] = 1;
        if (vis[i] == 0) point = i;
    }
    for (int i = 1; i <= n; i++) {
        if (cnt[i] == 0) {
            vis[point] = i;
            break;
        }
    }
    cout << '!' << ' ';
    for (int i = 1; i <= n; i++) cout << vis[i] << ' ';
}