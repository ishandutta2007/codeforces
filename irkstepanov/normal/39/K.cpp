#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define pb push_back
#define sz(a) (int)(a).size()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef double ld;

const int nmax = 1050;

char a[nmax][nmax];
int h, w;
char used[nmax][nmax];

struct rect {
    int xmin, xmax;
    int ymin, ymax;
    bool operator<(const rect& other) const {
        return ymin < other.ymin;
    }
};

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void dfs(int i, int j, int& xmin, int& xmax, int& ymin, int& ymax) {
    xmin = min(xmin, i);
    xmax = max(xmax, i);
    ymin = min(ymin, j);
    ymax = max(ymax, j);
    used[i][j] = true;
    for (int k = 0; k < 4; ++k) {
        int x = i + dx[k], y = j + dy[k];
        if (x < 0 || x >= h || y < 0 || y >= w || a[x][y] == '.' || used[x][y]) {
            continue;
        }
        dfs(x, y, xmin, xmax, ymin, ymax);
    }
}

int main() {

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int k;
    cin >> h >> w >> k;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> a[i][j];
        }
    }

    memset(used, false, sizeof(used));
    vector<rect> v;
    vector<int> lst;
    lst.pb(h - 1);
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (used[i][j] || a[i][j] == '.') {
                continue;
            }
            int xmin = i, xmax = i;
            int ymin = j, ymax = j;
            dfs(i, j, xmin, xmax, ymin, ymax);
            v.pb({xmin, xmax, ymin, ymax});
            if (xmin > 0) {
                lst.pb(xmin - 1);
            }
            lst.pb(xmin);
            if (xmax > 0) {
                lst.pb(xmax - 1);
            }
            lst.pb(xmax);
        }
    }

    /*for (int i = 0; i < h; ++i) {
        lst.pb(i);
    }*/

    assert(sz(v) == k);
    sort(all(lst));
    lst.resize(unique(all(lst)) - lst.begin());
    vector<pii> segs;
    int pr = 0;
    for (int i = 0; i < sz(lst); ++i) {
        segs.pb({pr, lst[i]});
        pr = lst[i] + 1;
    }

    ll ans = 0;

    for (int a = 0; a < sz(segs); ++a) {
        for (int b = a; b < sz(segs); ++b) {
            //ll oldAns = ans;
            vector<rect> alive;
            for (int i = 0; i < k; ++i) {
                if (v[i].xmax < segs[a].first || v[i].xmin > segs[b].second) {
                    continue;
                }
                alive.pb(v[i]);
            }
            sort(all(alive));
            vector<ll> dp(4, 0);
            ll x = segs[a].second - segs[a].first + 1;
            ll y = segs[b].second - segs[b].first + 1;
            int ptr = 0;
            int curr = 0;
            /*if (a == 0 && b == 9) {
                cout << ans << "\n";
            }*/
            while (ptr < sz(alive)) {
                /*if (a == 0 && b == 9) {
                    cout << curr << " " << ptr << " " << alive[ptr].ymin << "\n";
                }*/
                if (curr < alive[ptr].ymin) {
                    for (int j = 1; j <= 3; ++j) {
                        ans += dp[j] * ll(alive[ptr].ymin - curr);
                    }
                    dp[0] += ll(alive[ptr].ymin - curr) * (a == b ? x * (x + 1) / 2 : x * y);
                    curr = alive[ptr].ymin;
                }
                assert(curr == alive[ptr].ymin);
                int nx = ptr;
                int rg = alive[ptr].ymax;
                while (nx + 1 < sz(alive) && alive[nx + 1].ymin <= rg) {
                    ++nx;
                    rg = max(rg, alive[nx].ymax);
                }
                /*if (a == 0 && b == 9) {
                    cout << ptr << " " << nx << "\n";
                }*/
                bool ok = true;
                for (int j = ptr; j <= nx; ++j) {
                    if (alive[j].xmax > segs[b].second || alive[j].xmin < segs[a].second) {
                        ok = false;
                        break;
                    }
                }
                if (!ok) {
                    dp.assign(4, 0);
                    ptr = nx + 1;
                    curr = rg + 1;
                    continue;
                }
                /*if (a == 0 && b == 9 && ptr == 4) {
                    for (int j = 0; j < 4; ++j) {
                        cout << dp[j] << " ";
                    }
                    cout << "\n";
                }*/
                vector<ll> dpNew(4, 0);
                for (int j = 0; j < 4; ++j) {
                    if (j + (nx - ptr + 1) < 4) {
                        dpNew[j + (nx - ptr + 1)] = dp[j];
                    }
                }
                if (nx - ptr + 1 < 4) {
                    dpNew[nx - ptr + 1] += (a == b ? x * (x + 1) / 2 : x * y);
                }
                dp.swap(dpNew);
                for (int j = 1; j <= 3; ++j) {
                    ans += dp[j];
                }
                ptr = nx + 1;
                curr = rg + 1;
                /*if (a == 0 && b == 9) {
                    cout << ans << "\n";
                }*/
            }
            if (curr < w) {
                for (int j = 1; j <= 3; ++j) {
                    ans += dp[j] * ll(w - curr);
                }
            }
            /*if (a == 0 && b == 9) {
                cout << ans << "\n";
            }*/
            //cout << segs[a].first << " " << segs[b].first << " " << ans - oldAns << "\n";
        }
    }

    cout << ans << "\n";

}