#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;
typedef pair<int, ll> data;

int main()
{

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");
    //freopen("input.txt", "r", stdin);

    //ios_base::sync_with_stdio(false);
    //cin.tie(0);

    int n, m, q;
    scanf("%d%d%d", &n, &m, &q);

    vector<vector<pii> > down(n + 2, vector<pii>(m + 2));
    vector<vector<pii> > right(n + 2, vector<pii>(m + 2));
    for (int i = 0; i <= n + 1; ++i) {
        for (int j = 0; j <= m + 1; ++j) {
            if (i + 1 <= n + 1) {
                down[i][j] = mp(i + 1, j);
            } else {
                down[i][j] = mp(-1, -1);
            }
            if (j + 1 <= m + 1) {
                right[i][j] = mp(i, j + 1);
            } else {
                right[i][j] = mp(-1, -1);
            }
        }
    }

    vector<vector<int> > a(n + 2, vector<int>(m + 2));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            scanf("%d", &a[i][j]);
        }
    }

    while (q--) {
        int x[2], y[2], h, w;
        scanf("%d%d%d%d%d%d", &x[0], &y[0], &x[1], &y[1], &h, &w);
        //cout << h << " " << w << "\n";
        pii s[2];
        s[0] = mp(0, 0);
        s[1] = mp(0, 0);
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < x[i] - 1; ++j) {
                s[i] = down[s[i].first][s[i].second];
            }
            for (int j = 0; j < y[i] - 1; ++j) {
                s[i] = right[s[i].first][s[i].second];
            }
        }
        pii curr[2];
        curr[0] = s[0];
        curr[1] = s[1];
        //cout << curr[0].first << " " << curr[0].second << " " << curr[1].first << " " << curr[1].second << "\n";
        for (int i = 0; i < h; ++i) {
            //cout << curr[0].first << " " << curr[0].second << " " << curr[1].first << " " << curr[1].second << "\n";
            curr[0] = down[curr[0].first][curr[0].second];
            curr[1] = down[curr[1].first][curr[1].second];
            swap(right[curr[0].first][curr[0].second], right[curr[1].first][curr[1].second]);
        }
        //cout << curr[0].first << " " << curr[0].second << " " << curr[1].first << " " << curr[1].second << "\n";
        pii tmp = curr[0];
        curr[0] = right[curr[1].first][curr[1].second];
        curr[1] = right[tmp.first][tmp.second];
        for (int j = 0; j < w; ++j) {
            //cout << curr[0].first << " " << curr[0].second << " " << curr[1].first << " " << curr[1].second << "\n";
            swap(down[curr[0].first][curr[0].second], down[curr[1].first][curr[1].second]);
            curr[0] = right[curr[0].first][curr[0].second];
            curr[1] = right[curr[1].first][curr[1].second];
        }
        //cout << curr[0].first << " " << curr[0].second << " " << curr[1].first << " " << curr[1].second << "\n";
        curr[0] = s[0];
        curr[1] = s[1];
        for (int j = 0; j < w; ++j) {
            curr[0] = right[curr[0].first][curr[0].second];
            curr[1] = right[curr[1].first][curr[1].second];
            swap(down[curr[0].first][curr[0].second], down[curr[1].first][curr[1].second]);
        }
        //cout << curr[0].first << " " << curr[0].second << " " << curr[1].first << " " << curr[1].second << "\n";
        tmp = curr[0];
        curr[0] = down[curr[1].first][curr[1].second];
        curr[1] = down[tmp.first][tmp.second];
        //cout << curr[0].first << " " << curr[0].second << " " << curr[1].first << " " << curr[1].second << "\n";
        for (int i = 0; i < h; ++i) {
            //cout << curr[0].first << " " << curr[0].second << " " << curr[1].first << " " << curr[1].second << "\n";
            swap(right[curr[0].first][curr[0].second], right[curr[1].first][curr[1].second]);
            curr[0] = down[curr[0].first][curr[0].second];
            curr[1] = down[curr[1].first][curr[1].second];
        }
        //cout << curr[0].first << " " << curr[0].second << " " << curr[1].first << " " << curr[1].second << "\n";
    }


    //cout << down[1][1].first << "\n";

    //cout << right[1][2].first << " " << right[1][2].second << "\n";

    vector<vector<pii> > ans(n + 2, vector<pii>(m + 2));
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= m; ++j) {
            int x = ans[i][j].first, y = ans[i][j].second;
            //cout << i << " " << j << " " << ans[i][j].first << " " << ans[i][j].second << "\n";
            if (right[x][y].first != -1) {
                ans[i][j + 1] = right[x][y];
            }
            if (down[x][y].first != -1) {
                ans[i + 1][j] = down[x][y];
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            printf("%d ", a[ans[i][j].first][ans[i][j].second]);
        }
        printf("\n");
    }

}