#include <bits/stdc++.h>
 
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;
typedef pair<ll, ll> pll;

const int nmax = 15;

bool used[nmax][nmax][nmax];
char a[nmax][nmax][nmax];
int k, n, m;
int ans = 0;

void dfs(int i, int j, int u) {
    used[i][j][u] = true;
    ++ans;
    if (i - 1 >= 0 && a[i - 1][j][u] == '.' && !used[i - 1][j][u]) {
        dfs(i - 1, j, u);
    } 
    if (i + 1 < k && a[i + 1][j][u] == '.' && !used[i + 1][j][u]) {
        dfs(i + 1, j, u);
    }
    if (j - 1 >= 0 && a[i][j - 1][u] == '.' && !used[i][j - 1][u]) {
        dfs(i, j - 1, u);
    }
    if (j + 1 < n && a[i][j + 1][u] == '.' && !used[i][j + 1][u]) {
        dfs(i, j + 1, u);
    }
    if (u - 1 >= 0 && a[i][j][u - 1] == '.' && !used[i][j][u - 1]) {
        dfs(i, j, u - 1);
    }
    if (u + 1 < m && a[i][j][u + 1] == '.' && !used[i][j][u + 1]) {
        dfs(i, j, u + 1);
    }
}

int main()
{

    //memset(pro, -1, sizeof(pro));
 
    //ifstream cin("input.txt");
    //ofstream cout("output.txt");
    //freopen("input.txt", "r", stdin);
 
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> k >> n >> m;

    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int u = 0; u < m; ++u) {
                cin >> a[i][j][u];
            }
        }
    }

    int x, y;
    cin >> x >> y;
    --x, --y;

    dfs(0, x, y);
    cout << ans << "\n";

}