#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;

struct pt
{
    int x, y;
    int dx, dy;
    bool operator<(const pt& other) const
    {
        if (x != other.x) {
            return x < other.x;
        }
        if (y != other.y) {
            return y < other.y;
        }
        if (dx != other.dx) {
            return dx < other.dx;
        }
        return dy < other.dy;
    }
};

const int nmax = 400;

int main()
{

    //ifstream cin("input.txt");

    //freopen("input.txt", "r", stdin);

    vector<vector<char> > used(nmax, vector<char>(nmax, false));

    set<pt> q;
    int n;

    cin >> n;
    q.insert({nmax / 2, nmax / 2, -1, 0});

    vector<pii> dir;
    dir.pb({-1, 0});
    dir.pb({-1, 1});
    dir.pb({0, 1});
    dir.pb({1, 1});
    dir.pb({1, 0});
    dir.pb({1, -1});
    dir.pb({0, -1});
    dir.pb({-1, -1});

    while (n--) {
        int t;
        cin >> t;
        set<pt> next;
        for (auto p : q) {
            int x = p.x, y = p.y;
            for (int j = 0; j < t; ++j) {
                used[x][y] = true;
                if (j != t - 1) {
                    x += p.dx;
                    y += p.dy;
                }
            }
            int pos;
            for (int i = 0; i < sz(dir); ++i) {
                if (dir[i].first == p.dx && dir[i].second == p.dy) {
                    pos = i;
                }
            }
            int pos1 = (pos + 1) % sz(dir);
            int pos2 = (pos - 1 + sz(dir)) % sz(dir);
            pt u = {x + dir[pos1].first, y + dir[pos1].second, dir[pos1].first, dir[pos1].second};
            pt v = {x + dir[pos2].first, y + dir[pos2].second, dir[pos2].first, dir[pos2].second};
            next.insert(u);
            next.insert(v);
        }
        q.swap(next);
    }

    int ans = 0;
    for (int i = 0; i < nmax; ++i) {
        for (int j = 0; j < nmax; ++j) {
            if (used[i][j]) {
                ++ans;
            }
        }
    }

    cout << ans << "\n";

}