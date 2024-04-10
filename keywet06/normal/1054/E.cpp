#include <bits/stdc++.h>

using namespace std;

const int N = 328;

string s[N][N];

vector<tuple<int, int, int, int>> ans;

void g(int a, int b, int c, int d) {
    assert(a != c || b != d);
    ans.emplace_back(a, b, c, d);
}

int n, m;

void irev(string& s) { reverse(s.begin(), s.end()); }

void solve(bool rev) {
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> s[i][j];
            if (!rev) irev(s[i][j]);
        }
    }
    for (int i = 2; i <= n; ++i) {
        for (int j = 2; j <= m; ++j) {
            for (char c : s[i][j]) {
                if (c == '0') {
                    if (i != n) g(n, 1, i, 1);
                    g(i, 1, i, j);
                } else {
                    if (j != m) g(1, m, 1, j);
                    g(1, j, i, j);
                }
            }
        }
    }
    for (int i = n; i > 1; --i) {
        for (char c : s[i][1]) {
            c == '0' ? g(n, 1, 1, 1) : g(1, m, 1, 1);
            g(1, 1, i, 1);
        }
    }
    for (int j = m; j > 1; --j) {
        for (char c : s[1][j]) {
            c == '0' ? g(n, 1, 1, 1) : g(1, m, 1, 1);
            g(1, 1, 1, j);
        }
    }
    for (char c : s[1][1]) c == '0' ? g(n, 1, 1, 1) : g(1, m, 1, 1);
    if (rev) {
        for (auto& val : ans) {
            swap(get<0>(val), get<2>(val));
            swap(get<1>(val), get<3>(val));
        }
        reverse(ans.begin(), ans.end());
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cout.setf(ios::fixed), cout.precision(20);
    cin >> n >> m;
    solve(true);
    solve(false);
    cout << ans.size() << "\n";
    for (auto& [a, b, c, d] : ans) {
        cout << a << " " << b << " " << c << " " << d << "\n";
    }
}