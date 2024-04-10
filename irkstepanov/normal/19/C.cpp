 #include <bits/stdc++.h>
#include <string.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;
typedef pair<ll, int> pll;

const int nmax = 100500;
const int rmax = 17;

vector<vector<int> > c(rmax);
vector<vector<int> > p(rmax);
int n;

bool eq(int x, int y, int len)
{
    if (x + len - 1 >= n || y + len - 1 >= n) {
        return false;
    }
    int r = 0;
    for (; (1 << r) <= len; ++r) ;
    --r;
    if (c[r][x] != c[r][y]) {
        return false;
    }
    if (c[r][x + len - (1 << r)] != c[r][y + len - (1 << r)]) {
        return false;
    }
    return true;
}

int main()
{

    //ifstream cin("input.txt");
    //freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<int> init = a;
    vector<int> sorted = a;
    sort(all(sorted));
    sorted.resize(unique(all(sorted)) - sorted.begin());

    for (int i = 0; i < n; ++i) {
        a[i] = lower_bound(all(sorted), a[i]) - sorted.begin();
    }

    vector<queue<int> > bucket(nmax);
    for (int i = 0; i < rmax; ++i) {
        c[i].resize(n);
        p[i].resize(n);
    }

    for (int i = 0; i < n; ++i) {
        bucket[a[i]].push(i);
    }
    int cl = 0;
    int pos = 0;
    for (int i = 0; i < nmax; ++i) {
        if (!bucket[i].empty()) {
            while (!bucket[i].empty()) {
                int v = bucket[i].front();
                bucket[i].pop();
                c[0][v] = cl;
                p[0][pos++] = v;
            }
            ++cl;
        }
    }

    int last_len = 0;

    for (int len = 1; (1 << len) <= n; ++len) {
        last_len = len;
        p[len] = p[len - 1];
        for (int i = 0; i < n; ++i) {
            p[len][i] -= (1 << (len - 1));
            if (p[len][i] < 0) {
                p[len][i] += n;
            }
        }
        for (int i = 0; i < n; ++i) {
            bucket[c[len - 1][p[len][i]]].push(p[len][i]);
        }
        pos = 0;
        for (int i = 0; i < nmax; ++i) {
            if (!bucket[i].empty()) {
                while (!bucket[i].empty()) {
                    int v = bucket[i].front();
                    bucket[i].pop();
                    p[len][pos++] = v;
                }
            }
        }
        cl = 0;
        for (int i = 0; i < n; ++i) {
            if (i == 0) {
                c[len][p[len][i]] = cl;
                continue;
            }
            if (c[len - 1][p[len][i]] != c[len - 1][p[len][i - 1]]) {
                ++cl;
            } else {
                int a = c[len - 1][(p[len][i] + (1 << (len - 1))) % n];
                int b = c[len - 1][(p[len][i - 1] + (1 << (len - 1))) % n];
                if (a != b) {
                    ++cl;
                }
            }
            c[len][p[len][i]] = cl;
        }
    }

    vector<vector<int> > positions(nmax);
    for (int i = 0; i < n; ++i) {
        positions[a[i]].pb(i);
    }

    set<pii> q;
    for (int x = 0; x < nmax; ++x) {
        for (int i = 0; i < sz(positions[x]); ++i) {
            for (int j = i + 1; j < sz(positions[x]); ++j) {
                int a = positions[x][i], b = positions[x][j];
                if (eq(a, b, b - a)) {
                    q.insert(mp(b - a, a));
                }
            }
        }
    }

    vector<char> used(n, false);
    while (!q.empty()) {
        pii it = *q.begin();
        q.erase(q.begin());
        if (used[it.second]) {
            continue;
        }
        for (int i = it.second + it.first - 1; i >= 0 && !used[i]; --i) {
            used[i] = true;
        }
    }

    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (!used[i]) {
            ++cnt;
        }
    }
    cout << cnt << "\n";
    for (int i = 0; i < n; ++i) {
        if (!used[i]) {
            cout << init[i] << " ";
        }
    }
    cout << "\n";

}