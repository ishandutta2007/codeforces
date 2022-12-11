#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define mp make_pair
#define pb push_back

using namespace std;
typedef long long ll;
typedef long double ld;

vector<vector<int> > comp;
vector<int> cnt, leftt, rightt, up, down;
vector<int> marked;
vector<int> added;
vector<vector<int> > r;
int cnt_out;
int n, k;

vector<int> inside;
int size_inside;

void add_inside(int l, int r, int j)
{
    for (int i = l; i <= r; ++i) {
        if (comp[i][j] != -1) {
            int c = comp[i][j];
            if (leftt[c] >= j && rightt[c] <= j + k - 1 && up[c] >= l && down[c] <= r && !inside[c]) {
                inside[c] = 1;
                size_inside += cnt[c];
            }
        }
    }
}

void del_inside(int l, int r, int j)
{
    for (int i = l; i <= r; ++i) {
        if (comp[i][j] != -1) {
            int c = comp[i][j];
            if (inside[c]) {
                inside[c] = 0;
                size_inside -= cnt[c];
            }
        }
    }
}

void add_col(int l, int r, int j)
{
    for (int i = l; i <= r; ++i) {
        if (comp[i][j] != -1 && !inside[comp[i][j]]) {
            if (!marked[comp[i][j]]) {
                marked[comp[i][j]] = 1;
                added.pb(comp[i][j]);
                cnt_out += cnt[comp[i][j]];
            }
        }
    }
}

void add_row(int i, int l, int r)
{
    for (int j = l; j <= r; ++j) {
        if (comp[i][j] != -1 && !inside[comp[i][j]]) {
            if (!marked[comp[i][j]]) {
                marked[comp[i][j]] = 1;
                added.pb(comp[i][j]);
                cnt_out += cnt[comp[i][j]];
            }
        }
    }
}

void add_all(int i, int j)
{
    if (i) {
        add_row(i - 1, j, j + k - 1);
    }
    if (i + k < n) {
        add_row(i + k, j, j + k - 1);
    }
    if (j) {
        add_col(i, i + k - 1, j - 1);
    }
    if (j + k < n) {
        add_col(i, i + k - 1, j + k);
    }
}

int solve(int i, int j)
{
    int ans = r[i + k - 1][j + k - 1];
    if (i) {
        ans -= r[i - 1][j + k - 1];
    }
    if (j) {
        ans -= r[i + k - 1][j - 1];
    }
    if (i && j) {
        ans += r[i - 1][j - 1];
    }
    return ans;
}

int main()
{

    //ifstream cin("input");
    //ofstream cout("output");

    //freopen("input", "w", stdout);

    cin >> n >> k;

    vector<vector<char> > m(n, vector<char>(n));
    r.resize(n);
    comp.resize(n);
    for (int i = 0; i < n; ++i) {
        comp[i].assign(n, -1);
        r[i].resize(n);
        for (int j = 0; j < n; ++j) {
            cin >> m[i][j];
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (m[i][j] == 'X') {
                r[i][j] = 1;
            }
            if (i) {
                r[i][j] += r[i - 1][j];
            }
            if (j) {
                r[i][j] += r[i][j - 1];
            }
            if (i && j) {
                r[i][j] -= r[i - 1][j - 1];
            }
        }
    }

    int cnt_comp = 0;
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (m[i][j] == 'X' || comp[i][j] != -1) {
                continue;
            }
            queue<int> qx, qy;
            comp[i][j] = cnt_comp++;
            qx.push(i), qy.push(j);
            while (!qx.empty()) {
                int xx = qx.front(), yy = qy.front();
                qx.pop(), qy.pop();
                for (int c = 0; c < 4; ++c) {
                    int x = xx + dx[c], y = yy + dy[c];
                    if (x >= 0 && x < n && y >= 0 && y < n && comp[x][y] == -1 && m[x][y] != 'X') {
                        comp[x][y] = comp[xx][yy];
                        qx.push(x), qy.push(y);
                    }
                }
            }
        }
    }

    cnt.resize(cnt_comp);
    int ans = 0;
    leftt.assign(cnt_comp, 100500);
    rightt.assign(cnt_comp, -1);
    up.assign(cnt_comp, 100500);
    down.assign(cnt_comp, -1);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (comp[i][j] != -1) {
                int c = comp[i][j];
                ++cnt[c];
                ans = max(ans, cnt[c]);
                leftt[c] = min(leftt[c], j);
                rightt[c] = max(rightt[c], j);
                up[c] = min(up[c], i);
                down[c] = max(down[c], i);
            }
        }
    }

    /*for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (comp[i][j] == -1) {
                cout << "-";
            } else {
                cout << comp[i][j];
            }
        }
        cout << "\n";
    }*/

    marked.assign(cnt_comp, 0);

    for (int i = 0; i <= n - k; ++i) {
        inside.assign(cnt_comp, 0);
        size_inside = 0;
        for (int j = 0; j < k; ++j) {
            add_inside(i, i + k - 1, j);
        }
        cnt_out = 0;
        add_all(i, 0);
        ans = max(ans, size_inside + solve(i, 0) + cnt_out);
        //cout << size_inside << " " << solve(i, 0) << " " << cnt_out << "\n";
        for (int x : added) {
            marked[x] = 0;
        }
        added.clear();
        cnt_out = 0;
        for (int j = 0; j + k < n; ++j) { // delete j
            del_inside(i, i + k - 1, j);
            add_inside(i, i + k - 1, j + k);
            add_all(i, j + 1);
            ans = max(ans, size_inside + solve(i, j + 1) + cnt_out);
            //cout << i << " " << j << " " << cnt_out << " " << size_inside + solve(i, j + 1) + cnt_out << "\n";
            for (int x : added) {
                marked[x] = 0;
            }
            added.clear();
            cnt_out = 0;
        }
    }

    /*for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << comp[i][j] << " ";
        }
        cout << "\n";
    }*/

    cout << ans << "\n";

}