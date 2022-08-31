#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1E5;
int n;
int q[N][3], p[N];
vector<int> a[N];
bool used[N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n - 2; ++i) {
        cin >> q[i][0] >> q[i][1] >> q[i][2];
        a[--q[i][0]].push_back(i);
        a[--q[i][1]].push_back(i);
        a[--q[i][2]].push_back(i);
    }
    while ((int)a[p[0]].size() != 1)
        ++p[0];
    used[p[0]] = true;
    for (int i : a[p[0]]) {
        for (int j = 0; j < 3; ++j) {
            if ((int)a[q[i][j]].size() == 2) {
                p[1] = q[i][j];
                break;
            }
        }
        used[p[1]] = true;
    }
    for (int i = 2; i < n; ++i) {
        for (int j : a[p[i - 2]])
            for (int k = 0; k < 3; ++k)
                if (!used[q[j][k]])
                    p[i] = q[j][k];
        used[p[i]] = true;
    }
    for (int i = 0; i < n; ++i)
        cout << p[i] + 1 << " \n"[i == n - 1];
    return 0;
}