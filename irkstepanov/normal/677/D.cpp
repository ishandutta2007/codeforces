#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;
typedef pair<ll, ll> pll;

int n, m;
const int nmax = 300;
const int inf = 1e9;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

struct cell
{
    int x, y;
    int d;
    bool operator<(const cell& other) const
    {
        return d < other.d;
    }
};

vector<cell> solve(vector<cell>& s, const vector<pii>& t)
{
    vector<cell> ans;
    for (int i = 0; i < sz(t); ++i) {
        ans.pb({t[i].first, t[i].second, inf});
    }
    if (sz(s) < nmax) {
        for (int i = 0; i < sz(t); ++i) {
            for (int j = 0; j < sz(s); ++j) {
                ans[i].d = min(ans[i].d, s[j].d + abs(t[i].first - s[j].x) + abs(t[i].second - s[j].y));
            }
        }
        return ans;
    }
    int d[nmax][nmax];
    sort(all(s));
    for (int i = 0; i < nmax; ++i) {
        for (int j = 0; j < nmax; ++j) {
            d[i][j] = inf;
        }
    }
    deque<pii> q;
    int ptr = 0;
    while (!q.empty() || ptr != sz(s)) {
        if (ptr < sz(s) && (q.empty() || s[ptr].d <= d[q.front().first][q.front().second])) {
            int x = s[ptr].x, y = s[ptr].y;
            if (d[x][y] > s[ptr].d) {
                d[x][y] = s[ptr].d;
                q.push_front({x, y});
            }
            ++ptr;
            continue;
        }
        int x = q.front().first, y = q.front().second;
        q.pop_front();
        for (int k = 0; k < 4; ++k) {
            int xx = x + dx[k], yy = y + dy[k];
            if (xx >= 0 && xx < n && yy >= 0 && yy < m && d[xx][yy] > d[x][y] + 1) {
                d[xx][yy] = d[x][y] + 1;
                q.push_back({xx, yy});
            }
        }
    }
    for (int i = 0; i < sz(ans); ++i) {
        ans[i].d = d[ans[i].x][ans[i].y];
    }
    return ans;
}

int main()
{

    //ifstream cin("input.txt");
	//ofstream cout("output.txt");
    //freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int p;
    cin >> n >> m >> p;

    int color[nmax][nmax];
    vector<vector<pii> > v(p);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> color[i][j];
            --color[i][j];
            v[color[i][j]].pb({i, j});
        }
    }

    vector<cell> curr;
    for (pii& p : v[0]) {
        curr.pb({p.first, p.second, p.first + p.second});
    }

    for (int i = 0; i + 1 < p; ++i) {
        vector<cell> nx = solve(curr, v[i + 1]);
        curr.swap(nx);
    }

    cout << curr[0].d << "\n";

}