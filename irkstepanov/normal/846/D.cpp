#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;

struct event {
    int x, y;
    int pos;
    bool operator<(const event& other) const {
        return pos < other.pos;
    }
};

int n, m, k;

bool broken(const vector<event>& events) {
    vector<vector<int> > sq(n, vector<int>(m));
    vector<vector<char> > a(n, vector<char>(m, false));
    for (const event& e : events) {
        a[e.x][e.y] = true;
    }
    for (int i = n - 1; i >= 0; --i) {
        for (int j = m - 1; j >= 0; --j) {
            if (a[i][j] == false) {
                sq[i][j] = 0;
                continue;
            }
            if (i == n - 1 || j == m - 1) {
                sq[i][j] = 1;
                continue;
            }
            int x = min(sq[i + 1][j], sq[i][j + 1]);
            if (a[i + x][j + x]) {
                sq[i][j] = x + 1;
            } else {
                sq[i][j] = x;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (sq[i][j] >= k) {
                return true;
            }
        }
    }
    return false;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //ifstream cin("input.txt");
    //freopen("input.txt", "r", stdin);
    //ofstream cout("output.txt");

    int q;
	cin >> n >> m >> k >> q;
    vector<event> events;
    for (int i = 0; i < q; ++i) {
        int x, y, t;
        cin >> x >> y >> t;
        --x, --y;
        events.pb({x, y, t});
    }
    sort(all(events));

    int lf = -1, rg = sz(events) - 1;
    while (rg - lf > 1) {
        int md = (lf + rg) >> 1;
        vector<event> tmp;
        for (int i = 0; i <= md; ++i) {
            tmp.pb(events[i]);
        }
        if (broken(tmp)) {
            rg = md;
        } else {
            lf = md;
        }
    }

    vector<event> tmp;
    for (int i = 0; i <= rg; ++i) {
        tmp.pb(events[i]);
    }
    if (broken(tmp)) {
        cout << events[rg].pos << "\n";
    } else {
        cout << "-1\n";
    }

}