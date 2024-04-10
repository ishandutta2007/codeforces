#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int n, m;
char s[55][55];
set<int> r, c;

void dfs(int x, int y) {
    if (c.count(x) && r.count(y))
        return;
    c.insert(x);
    r.insert(y);
    for (int i = 0; i < n; ++i)
        if (s[i][x] == '#')
            dfs(x, i);
    for (int j = 0; j < m; ++j)
        if (s[y][j] == '#')
            dfs(j, y);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        cin >> s[i];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (s[i][j] == '#') {
                r.clear();
                c.clear();
                dfs(j, i);
                for (int y : r)
                    for (int x : c)
                        if (s[y][x] != '#')
                            cout << "No" << endl, exit(0);
                        else
                            s[y][x] = '.';
            }
        }
    }

    cout << "Yes" << endl;
}