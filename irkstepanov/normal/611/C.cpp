#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back
#define sz(a) static_cast<int>((a).size())
#define all(a) (a).begin(), (a).end()
#define forn(i, n) for (int i = 0; i < n; ++i)

using namespace std;

typedef long long ll;

vector<vector<int> > hor, ver;
vector<vector<int> > dp1, dp2;

int f1(int a, int b, int c, int d)
{
    if (a > c || b > d) {
        return 0;
    }
    return dp1[c][d] - dp1[c][b - 1] - dp1[a - 1][d] + dp1[a - 1][b - 1];
}

int f2(int a, int b, int c, int d)
{
    if (a > c || b > d) {
        return 0;
    }
    return dp2[c][d] - dp2[c][b - 1] - dp2[a - 1][d] + dp2[a - 1][b - 1];
}

int main()
{

    //ifstream cin("input.txt");
    //freopen("input.txt", "r", stdin);
    //ofstream cout("output.txt");

    int n, m;
    cin >> n >> m;

    vector<vector<char> > a(n + 1, vector<char>(m + 1, '?'));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> a[i][j];
        }
    }

    hor.resize(n + 1);
    ver.resize(n + 1);
    dp1.resize(n + 1);
    dp2.resize(n + 1);

    for (int i = 0; i <= n; ++i) {
        hor[i].resize(m + 1);
        ver[i].resize(m + 1);
        dp1[i].resize(m + 1);
        dp2[i].resize(m + 1);
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (a[i][j] == '#') {
                continue;
            }
            if (a[i - 1][j] == '.') {
                ++ver[i][j];
            }
            if (a[i][j - 1] == '.') {
                ++hor[i][j];
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            dp1[i][j] = hor[i][j] + dp1[i - 1][j] + dp1[i][j - 1] - dp1[i - 1][j - 1];
            dp2[i][j] = ver[i][j] + dp2[i - 1][j] + dp2[i][j - 1] - dp2[i - 1][j - 1];
        }
    }

    int q;
    cin >> q;
    while (q--) {
        int a, b, c, d;
        scanf("%d%d%d%d", &a, &b, &c, &d);
        int ans = f1(a, b + 1, c, d);
        ans += f2(a + 1, b, c, d);
        printf("%d\n", ans);
    }

}