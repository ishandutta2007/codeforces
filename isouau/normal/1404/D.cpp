#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 5;

int pos[N * 2], a[N][2], len[N], used[N], ans[N * 2];
int n;

inline int getpos(int v) {
    if (v <= n) return pos[v + n];
    return pos[v - n];
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    if (n % 2 == 0) {
        cout << "First" << endl;
        for (int i = 1; i <= 2 * n; i++) cout << (i - 1) % n + 1 << " ";
        cout << endl;
    } else {
        cout << "Second" << endl;
        long long sum = 0;
        for (int i = 1; i <= n * 2; i++) {
            cin >> pos[i];
            a[pos[i]][len[pos[i]]++] = i;
        }
        for (int i = 1; i <= n; i++) {
            if (used[i]) continue;
            used[i] = 1;
            ans[a[i][0]] = 1;
            sum += a[i][0];
            int now = getpos(a[i][1]), las = a[i][1];
            while (!used[now]) {
                if (las <= n) las += n;
                else las -= n;
                used[now] = 1;
                int id = (las == a[now][1]);
                sum += a[now][id];
                ans[a[now][id]] = 1;
                las = a[now][id ^ 1];
                now = getpos(a[now][id ^ 1]);
            }
        }
        if (sum % (2 * n) == n) {
            for (int i = 1; i <= n * 2; i++) {
                if (!ans[i]) {
                    cout << i << " ";
                }
            }
            cout << endl;
        } else {
            for (int i = 1; i <= n * 2; i++) {
                if (ans[i]) {
                    cout << i << " ";
                }
            }
            cout << endl;
        }
    }
    return 0;
}