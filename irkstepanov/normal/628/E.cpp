#include <bits/stdc++.h>

#define sz(a) static_cast<int>(a.size())
#define all(a) (a).begin(), (a).end()
#define pb push_back
#define mp make_pair

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

vector<vector<int> > t;
int N;

void upd(int id, int pos)
{
    for (; pos < N; pos = (pos | (pos + 1))) {
        ++t[id][pos];
    }
}

int get(int id, int pos)
{
    int ans = 0;
    for (; pos >= 0; pos = (pos & (pos + 1)) - 1) {
        ans += t[id][pos];
    }
    return ans;
}

int main()
{

    //freopen("input.txt", "r", stdin);

    int n, m;
    scanf("%d %d\n", &n, &m);

    vector<vector<char> > a(n, vector<char>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf("%c", &a[i][j]);
        }
        if (i != n - 1) {
            scanf("\n");
        }
    }

    vector<vector<int> > lf(n, vector<int>(m)), rg(n, vector<int>(m)), dl(n, vector<int>(m));
    vector<vector<pii> > events(m);
    for (int j = m - 1; j >= 0; --j) {
        for (int i = 0; i < n; ++i) {
            if (a[i][j] == 'z') {
                if (j != m - 1 && a[i][j + 1] == 'z') {
                    rg[i][j] = rg[i][j + 1] + 1;
                } else {
                    rg[i][j] = 1;
                }
                events[j + rg[i][j] - 1].pb(mp(i, j));
            }
        }
    }
    for (int j = 0; j < m; ++j) {
        for (int i = 0; i < n; ++i) {
            if (a[i][j] == 'z') {
                if (j != 0 && a[i][j - 1] == 'z') {
                    lf[i][j] = lf[i][j - 1] + 1;
                } else {
                    lf[i][j] = 1;
                }
            }
        }
    }
    for (int i = n - 1; i >= 0; --i) {
        for (int j = 0; j < m; ++j) {
            if (a[i][j] == 'z') {
                if (i != n - 1 && j != 0 && a[i + 1][j - 1] == 'z') {
                    dl[i][j] = dl[i + 1][j - 1] + 1;
                } else {
                    dl[i][j] = 1;
                }
            }
        }
    }

    t.resize(n + m - 1);
    N = m;
    for (int i = 0; i < n + m - 1; ++i) {
        t[i].resize(N);
    }

    ll ans = 0;
    for (int j = m - 1; j >= 0; --j) {
        for (pii& p : events[j]) {
            upd(p.first + p.second, p.second);
        }
        for (int i = 0; i < n; ++i) {
            if (a[i][j] == 'z') {
                int d = min(lf[i][j], dl[i][j]);
                ans += get(i + j, j) - get(i + j, j - d);
            }
        }
    }

    cout << ans << "\n";

}