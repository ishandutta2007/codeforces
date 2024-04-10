#include <bits/stdc++.h>
#include <string.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;
typedef pair<ll, ll> pll;

struct cross
{
    int r;
    int i, j;
};

int n, m;

bool inside(int x, int y)
{
    return x >= 0 && x < n && y >= 0 && y < m;
}

int main()
{

    //ifstream cin("input.txt");
    //freopen("input.txt", "r", stdin);

    //ios_base::sync_with_stdio(false);
    //cin.tie(0);

    int k;
    cin >> n >> m >> k;

    vector<vector<char> > a(n, vector<char>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }

    vector<cross> ans;
    for (int r = 1; r <= n; ++r) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (a[i][j] != '*') {
                    continue;
                }
                if (!inside(i - r, j) || !inside(i + r, j) || !inside(i, j - r) || !inside(i, j + r)) {
                    continue;
                }
                if (a[i - r][j] == '*' && a[i + r][j] == '*' && a[i][j - r] == '*' && a[i][j + r] == '*') {
                    ans.pb({r, i, j});
                }
            }
        }
    }

    if (sz(ans) < k) {
        cout << "-1\n";
        return 0;
    }
    --k;
    int i = ans[k].i + 1, j = ans[k].j + 1, r = ans[k].r;
    cout << i << " " << j << "\n";
    cout << i - r << " " << j << "\n";
    cout << i + r << " " << j << "\n";
    cout << i << " " << j - r << "\n";
    cout << i << " " << j + r << "\n";

}