#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const ld PI = acosl(-1.);

const int N = 55;
char w[N][N];
bool used[N][N];
typedef pair<int, int> pii;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

vector<pair<int, int>> doit(int x, int y) {
    memset(used, 0, sizeof(used));
    queue<pii> q;
    q.emplace(x, y);
    used[x][y] = true;
    vector<pii> result;
    while (!q.empty()) {
        auto t = q.front(); q.pop();
        result.push_back(t);
        for (int i = 0; i < 4; ++i) {
            pii nt{t.first + dx[i], t.second + dy[i]};
            if (used[nt.first][nt.second]) continue;
            if (w[nt.first][nt.second] != '0') continue;
            used[nt.first][nt.second] = true;
            q.push(nt);
        }
    }
    sort(begin(result), end(result));
    return result;
}

ll sqr(ll x) {
    return x * x;
}

ll calc(pii a, pii b) {
    return sqr(a.first - b.first) + sqr(a.second - b.second);
}

int main() {
    int n;
    cin >> n;
    int sx, sy, fx, fy; cin >> sx >> sy >> fx >> fy;
    scanf("\n");
    for (int i = 0; i < n; ++i) {
        cin >> (w[i + 1] + 1);
    }

    auto a = doit(sx, sy);
    auto b = doit(fx, fy);
    if (a == b) {
        cout << 0 << endl;
        return 0;
    }
    ll ans = calc(a[0], b[0]);
    for (auto aa : a)
        for (auto bb : b)
            ans = min(ans, calc(aa, bb));
    cout << ans << endl;

    return 0;
}