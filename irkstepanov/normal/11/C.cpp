#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, ll> type;

int last_j(int i, int j, vector<vector<char> >& s)
{
    while (s[i][j] == '1') {
        ++j;
    }
    return j - 1;
}

int last_i(int i, int j, vector<vector<char> >& s)
{
    while (s[i][j] == '1') {
        ++i;
    }
    return i - 1;
}

pii to_left(int i, int j, vector<vector<char> >& s)
{
    while (s[i][j] == '1') {
        ++i, --j;
    }
    return mp(i - 1, j + 1);
}

pii to_right(int i, int j, vector<vector<char> >& s)
{
    while (s[i][j] == '1') {
        ++i, ++j;
    }
    return mp(i - 1, j - 1);
}

int main()
{

    //ifstream cin("input.txt");
    //freopen("input.txt", "r", stdin);

    int tt;
    scanf("%d", &tt);

    while (tt--) {
        int n, m;
        scanf("%d%d", &n, &m);
        vector<vector<char> > s(n + 2, vector<char>(m + 2, '0'));
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                scanf("%c", &s[i][j]);
                if (s[i][j] == '\n') {
                    scanf("%c", &s[i][j]);
                }
            }
        }
        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (s[i][j] == '1' && s[i][j - 1] == '0' && s[i - 1][j] == '0') {
                    int y = last_j(i, j, s);
                    int x = last_i(i, j, s);
                    if (y - j != x - i || y == j) {
                        goto next;
                    }
                    if (last_j(x, j, s) != y) {
                        goto next;
                    }
                    if (last_i(i, y, s) != x) {
                        goto next;
                    }
                    bool ok = true;
                    for (int jj = j - 1; jj <= y + 1; ++jj) {
                        if (s[i - 1][jj] != '0' || s[x + 1][jj] != '0') {
                            ok = false;
                            break;
                        }
                    }
                    for (int ii = i - 1; ii <= x + 1; ++ii) {
                        if (s[ii][j - 1] != '0' || s[ii][y + 1] != '0') {
                            ok = false;
                            break;
                        }
                    }
                    for (int jj = j + 1; jj <= y - 1; ++jj) {
                        if (s[i + 1][jj] != '0' || s[x - 1][jj] != '0') {
                            ok = false;
                            break;
                        }
                    }
                    for (int ii = i + 1; ii <= x - 1; ++ii) {
                        if (s[ii][j + 1] != '0' || s[ii][y - 1] != '0') {
                            ok = false;
                            break;
                        }
                    }
                    if (ok) {
                        ++ans;
                        continue;
                    }
                }
                next:;
                if (s[i][j] == '1' && s[i - 1][j - 1] == '0' && s[i - 1][j + 1] == '0') {
                    pii lf = to_left(i, j, s);
                    pii rg = to_right(i, j, s);
                    if (lf.first != rg.first || lf.first == i) {
                        continue;
                    }
                    if (to_right(lf.first, lf.second, s) != to_left(rg.first, rg.second, s)) {
                        continue;
                    }
                    pii finish = to_right(lf.first, lf.second, s);
                    bool ok = true;

                    for (int ii = i - 1, jj = j; ii <= lf.first; ++ii, --jj) {
                        if (s[ii][jj] != '0') {
                            ok = false;
                            break;
                        }
                        if (ii != lf.first && s[ii][jj - 1] != '0') {
                            ok = false;
                            break;
                        }
                    }
                    for (int ii = rg.first, jj = rg.second + 1; ii <= finish.first + 1; ++ii, --jj) {
                        if (s[ii][jj] != '0') {
                            ok = false;
                            break;
                        }
                        if (ii != rg.first && s[ii][jj + 1] != '0') {
                            ok = false;
                            break;
                        }
                    }
                    for (int ii = i - 1, jj = j; ii <= rg.first; ++ii, ++jj) {
                        if (s[ii][jj] != '0') {
                            ok = false;
                            break;
                        }
                        if (ii != rg.first && s[ii][jj + 1] != '0') {
                            ok = false;
                            break;
                        }
                    }
                    for (int ii = lf.first, jj = lf.second - 1; ii <= finish.first + 1; ++ii, ++jj) {
                        if (s[ii][jj] != '0') {
                            ok = false;
                            break;
                        }
                        if (ii != lf.first && s[ii][jj - 1] != '0') {
                            ok = false;
                            break;
                        }
                    }

                    for (int ii = i + 1, jj = j; ii <= lf.first; ++ii, --jj) {
                        if (s[ii][jj] != '0') {
                            ok = false;
                            break;
                        }
                        if (ii != i + 1 && s[ii][jj + 1] != '0') {
                            ok = false;
                            break;
                        }
                    }
                    for (int ii = rg.first, jj = rg.second - 1; ii < finish.first; ++ii, --jj) {
                        if (s[ii][jj] != '0') {
                            ok = false;
                            break;
                        }
                        if (ii != finish.first - 1 && s[ii][jj - 1] != '0') {
                            ok = false;
                            break;
                        }
                    }
                    for (int ii = i + 1, jj = j; ii <= rg.first; ++ii, ++jj) {
                        if (s[ii][jj] != '0') {
                            ok = false;
                            break;
                        }
                        if (ii != i + 1 && s[ii][jj - 1] != '0') {
                            ok = false;
                            break;
                        }
                    }
                    for (int ii = lf.first, jj = lf.second + 1; ii < finish.first; ++ii, ++jj) {
                        if (s[ii][jj] != '0') {
                            ok = false;
                            break;
                        }
                        if (ii != finish.first - 1 && s[ii][jj + 1] != '0') {
                            ok = false;
                            break;
                        }
                    }
                    if (ok) {
                        ++ans;
                    }
                }
            }
        }
        cout << ans << "\n";
    }

}