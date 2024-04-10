#include <bits/stdc++.h>
using namespace std;

int f(int n, int m, int x, int y, int i) {
    if (i == 0)
        return 1;

    int cnt = 0;

    // lu
    {
        int s_y = max(y - i, 0);
        int e_x = max(x - i, 0);
        int e_y = y - (e_x - (x - i));
        int c = e_y - s_y + 1;
        cnt += max(0, c);
    }

    // ru
    {
        int e_y = min(m - 1, y + i);
        int s_x = max(x - i, 0);
        int s_y = y + (s_x - (x - i));
        int c = e_y - s_y + 1;
        cnt += max(0, c);
    }

    // rd
    {
        int e_y = min(m - 1, y + i);
        int s_x = min(x + i, n - 1);
        int s_y = y - (s_x - (x + i));
        int c = e_y - s_y + 1;
        cnt += max(0, c);
    }

    // ld
    {
        int s_y = max(0, y - i);
        int e_x = min(x + i, n - 1);
        int e_y = y + (e_x - (x + i));
        int c = e_y - s_y + 1;
        cnt += max(0, c);
    }

    if (x - i >= 0)
        cnt--;
    if (x + i < n)
        cnt--;
    if (y - i >= 0)
        cnt--;
    if (y + i < m)
        cnt--;

    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    vector<int> a(t);
    for (int i = 0; i < t; i++) {
        cin >> a[i];
    }
    vector<int> C(t, 0);
    for (int x : a)
        C[x]++;
    int ma = *max_element(a.begin(), a.end());

    for (int n = 1; n * n <= t; n++) {
        if (t % n) continue;
        int m = t / n;

        for (int x = 0; x < n; x++) {
            int y = ma - x;
            if (y >= m) continue;

            bool b = true;
            for (int i = 0; i <= ma; i++) {
                if (C[i] != f(n, m, x, y, i)) {
                    b = false;
                    break;
                }
            }
            if (b) {
                cout << n << " " << m << '\n';
                cout << x + 1 << " " << y + 1 << '\n';
                return 0;
            }
        }
    }
    
    cout << -1 << '\n';
}