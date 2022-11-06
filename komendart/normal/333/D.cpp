#include <bits/stdc++.h>

using namespace std;

const int maxn = 1005;

int n, m;
int a[maxn][maxn];

char used[maxn][maxn];

int f(int x) {
    memset(used, 0, maxn * maxn);
    for (int i = 0; i < n; ++i) {
        vector<int> v;
        for (int j = 0; j < m; ++j) {
            if (a[i][j] >= x) {
                v.push_back(j);
            }
        }
        for (int j = 0; j < v.size(); ++j) {
            for (int k = j + 1; k < v.size(); ++k) {
                int x = v[j];
                int y = v[k];
                if (used[x][y]) return true;
                used[x][y] = true;
            }
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }

    int left = 0, right = 1e9 + 1;
    while (right - left > 1) {
        int mid = (left + right) / 2;
        if (f(mid)) {
            left = mid;
        } else {
            right = mid;
        }
    }

    cout << left << '\n';
}