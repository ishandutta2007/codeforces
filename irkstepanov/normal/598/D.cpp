#include <bits/stdc++.h>

#define mp make_pair
#define pbp ush-back
#define all(a) (a).begin(), (a).end()
#define sz(a) (int) (a).size()
#define forn(i, n) for (int i = 0; i < n; ++i)

using namespace std;

int main()
{

    //freopen("input.txt", "r", stdin);

    int n, m, k;
    scanf("%d %d %d\n", &n, &m, &k);

    vector<vector<char> > t(n, vector<char>(m));
    forn(i, n) {
        forn(j, m) {
            scanf("%c", &t[i][j]);
        }
        scanf("\n");
    }

    int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
    vector<vector<pair<int, int> > > used(n, vector<pair<int ,int> >(m, mp(-1, -1)));
    vector<vector<int> > ans(n, vector<int>(m));
    forn(i, n) {
        forn(j, m) {
            if (used[i][j].first == -1 && t[i][j] == '.') {
                used[i][j] = mp(i, j);
                queue<int> q;
                q.push(i);
                q.push(j);
                while (!q.empty()) {
                    int x = q.front();
                    q.pop();
                    int y = q.front();
                    q.pop();
                    for (int z = 0; z < 4; ++z) {
                        int xx = x + dx[z], yy = y + dy[z];
                        if (used[xx][yy].first == -1 && t[xx][yy] == '.') {
                            q.push(xx);
                            q.push(yy);
                            used[xx][yy] = mp(i, j);
                        }
                        if (t[xx][yy] == '*') {
                            ++ans[i][j];
                        }
                    }
                }
            }
        }
    }

    while (k--) {
        int x, y;
        scanf("%d %d\n", &x, &y);
        --x, --y;
        printf("%d\n", ans[used[x][y].first][used[x][y].second]);
    }

}