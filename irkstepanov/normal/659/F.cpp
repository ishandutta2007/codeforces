#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;

struct data
{
    ll val;
    int x, y;
    bool operator<(const data& other) const
    {
        if (val != other.val) {
            return val > other.val;
        }
        return false;
    }
};

vector<int> parent, size;

void create(int x)
{
    parent[x] = x;
    size[x] = 1;
}

int get(int x)
{
    if (parent[x] == x) {
        return x;
    }
    return parent[x] = get(parent[x]);
}

void unite(int x, int y)
{
    x = get(x), y = get(y);
    if (x == y) {
        return;
    }
    if (size[x] < size[y]) {
        swap(x, y);
    }
    parent[y] = x;
    size[x] += size[y];
}

int main()
{

    //ifstream cin("input.txt");

    int n, m;
    ll k;
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> k;
    vector<vector<ll> > init(n, vector<ll>(m));
    vector<data> d(n * m);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> init[i][j];
            d[i * m + j] = {init[i][j], i, j};
        }
    }

    sort(all(d));
    parent.assign(n * m, -1);
    size.assign(n * m, -1);
    int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
    vector<vector<char> > used(n, vector<char>(m, false));
    int x0 = -1, y0 = -1;

    for (int i = 0; i < n * m; ++i) {
        create(d[i].x * m + d[i].y);
        for (int step = 0; step < 4; ++step) {
            int x = d[i].x + dx[step], y = d[i].y + dy[step];
            if (x >= 0 && x < n && y >= 0 && y < m && used[x][y]) {
                unite(d[i].x * m + d[i].y, x * m + y);
            }
        }
        int s = size[get(d[i].x * m + d[i].y)];
        if (k % d[i].val == 0 && d[i].val * (ll)(s) >= k) {
            cout << "YES\n";
            x0 = d[i].x, y0 = d[i].y;
            break;
        }
        used[d[i].x][d[i].y] = true;
    }

    if (x0 == -1 && y0 == -1) {
        cout << "NO\n";
        return 0;
    }

    vector<vector<int> > ans(n, vector<int>(m, 0));
    queue<int> x, y;
    ans[x0][y0] = init[x0][y0];
    x.push(x0), y.push(y0);
    ll sum = ans[x0][y0];
    while (!x.empty() && sum < k) {
        int i = x.front(), j = y.front();
        x.pop(), y.pop();
        for (int step = 0; step < 4 && sum < k; ++step) {
            int xn = i + dx[step], yn = j + dy[step];
            if (xn >= 0 && xn < n && yn >= 0 && yn < m && ans[xn][yn] == 0 && init[xn][yn] >= init[x0][y0]) {
                ans[xn][yn] = ans[x0][y0];
                x.push(xn);
                y.push(yn);
                sum += ans[x0][y0];
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }

}