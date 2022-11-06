#include <bits/stdc++.h>

using namespace std;

void fail() {
    cout << "IMPOSSIBLE\n";
    exit(0);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int n, m, s, d;
    cin >> n >> m >> s >> d;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    a.push_back(-1); a.push_back(m + 1);
    sort(a.begin(), a.end());

    if (a[1] <= s) {
        fail();
    }

    vector<char> good(n + 1, false);
    for (int i = 0; i <= n; i++) {
        if (i == n) good[i] = true;
        else good[i] = (a[i + 1] - a[i] - 2 >= s);
    }

    int left = 0;
    while (true) {
        int dist = m - (a[left + 1] - 1);
        if (dist <= d) {
            break;
        }
        for (int i = left + 1; i <= n; i++) {
            int dist = (a[i] + 1) - (a[left + 1] - 1);
            if (dist <= d && good[i]) {
                left = i;
                break;
            }
            if (i == n) fail();
        }
    }

    left = 0;
    while (true) {
        cout << "RUN " << a[left + 1] - a[left] - 2 << '\n';
        int dist = m - (a[left + 1] - 1);
        if (dist <= d) {
            if (dist) cout << "JUMP " << dist << '\n';
            break;
        }
        for (int i = left + 1; i <= n; i++) {
            int dist = (a[i] + 1) - (a[left + 1] - 1);
            if (dist <= d && good[i]) {
                cout << "JUMP " << dist << '\n';
                left = i;
                break;
            }
        }
    }
}