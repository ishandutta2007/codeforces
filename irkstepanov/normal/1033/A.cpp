#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ld, ld> pld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int nmax = 1010;

bool valid[nmax][nmax];
bool used[nmax][nmax];

int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, 1, -1, -1, 0, 1};

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            valid[i][j] = true;
        }
    }

    int x, y;
    cin >> x >> y;
    --x, --y;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == x || j == y) {
                valid[i][j] = false;
            }
            if (i - j == x - y || i + j == x + y) {
                valid[i][j] = false;
            }
        }
    }

    cin >> x >> y;
    --x, --y;
    used[x][y] = true;
    queue<pii> q;
    q.push({x, y});
    while (!q.empty()) {
        pii p = q.front();
        x = p.first, y = p.second;
        q.pop();
        for (int k = 0; k < 8; ++k) {
            int a = x + dx[k], b = y + dy[k];
            if (a >= 0 && a < n && b >= 0 && b < n && valid[a][b] && !used[a][b]) {
                used[a][b] = true;
                q.push({a, b});
            }
        }
    }

    cin >> x >> y;
    --x, --y;
    cout << (used[x][y] ? "YES\n" : "NO\n");
    
}