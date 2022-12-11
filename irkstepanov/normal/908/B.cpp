#include <iostream>
#include <fstream>
#include <set>
#include <string>
#include <map>
#include <queue>
#include <algorithm>
#include <deque>
#include <memory.h>
#include <assert.h>
#include <cstring>
#include <cmath>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;
typedef pair<ll, ll> pll;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

	//ifstream cin("input.txt");
    //ofstream cout("output.txt");
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n, m;
    cin >> n >> m;

    vector<vector<char> > a(n, vector<char>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }

    string s;
    cin >> s;

    vector<int> p = {0, 1, 2, 3};
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {1, -1, 0, 0};
    int ans = 0;

    do {
        int x, y;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (a[i][j] == 'S') {
                    x = i, y = j;
                }
            }
        }
        bool ok = true;
        for (int i = 0; i < sz(s); ++i) {
            int dir = p[s[i] - '0'];
            int xx = x + dx[dir];
            int yy = y + dy[dir];
            if (xx < 0 || xx >= n || yy < 0 || yy >= m || a[xx][yy] == '#') {
                ok = false;
                break;
            }
            x = xx, y = yy;
            if (a[xx][yy] == 'E') {
                break;
            }
        }
        if (a[x][y] != 'E') {
            ok = false;
        }
        if (ok) {
            ++ans;
        }
    } while (next_permutation(all(p)));

    cout << ans << "\n";

}