#include<bits/stdc++.h>

using namespace std;

typedef long long llint;

const int MAXN = 105;

int t, n, m, k, cnt;
char a[MAXN][MAXN];
vector <int> v;
string s;

void nxt (int & x, int & y, int & dir) {
    y += dir;
    if (y == m) y--, x++, dir = -1;
    if (y < 0) y++, x++, dir = 1;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    for (char c = 'a'; c <= 'z'; c++) s += c;
    for (char c = 'A'; c <= 'Z'; c++) s += c;
    for (char c = '0'; c <= '9'; c++) s += c;
    cin >> t;
    while (t--) {
        cin >> n >> m >> k;
        cnt = 0;
        v.clear();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> a[i][j];
                cnt += (a[i][j] == 'R');
            }
        }
        for (int i = 0; i < cnt % k; i++) {
            v.push_back(cnt / k + 1);
        }
        for (int i = cnt % k; i < k; i++) {
            v.push_back(cnt / k);
        }
        int x = 0, y = 0, dir = 1, curr = 0;
        while (x < n) {
            v[curr] -= (a[x][y] == 'R');
            if (v[curr] < 0) curr++, v[curr]--;
            a[x][y] = s[curr];
            nxt(x, y, dir);
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << a[i][j];
            }
            cout << '\n';
        }
    }
    return 0;
}