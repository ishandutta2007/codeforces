#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int n, m, k;
vector<vector<ll> > f;

struct data
{
    vector<int> x, y, cost;
    int n;
};

ll get(int xx, int yy)
{
    //cout << "GET " << xx << " " << yy << "\n";
    ll ans = 0;
    for (int x = xx; x >= 0; x = (x & (x + 1)) - 1) {
        for (int y = yy; y >= 0; y = (y & (y + 1)) - 1) {
            ans += f[x][y];
        }
    }
    //cout << "GET " << xx << " " << yy << " " << ans << "\n";
    return ans;
}

void update(int xx, int yy, int val)
{
    //cout << "UPD " << xx << " " << yy << " " << val << '\n';
    for (int x = xx; x < n; x = (x | (x + 1))) {
        for (int y = yy; y < m; y = (y | (y + 1))) {
            f[x][y] += ll(val);
        }
    }
}

struct query
{
    vector<char> mask;
    int xmin, ymin, xmax, ymax;
    ll ans;
};

int main()
{

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    //ios_base::sync_with_stdio(false);
    //cin.tie(0);

    scanf("%d%d%d", &n, &m, &k);

    f = vector<vector<ll> >(n, vector<ll>(m));

    vector<data> v(k);
    for (int i = 0; i < k; ++i) {
        scanf("%d", &v[i].n);
        v[i].x.resize(v[i].n);
        v[i].y.resize(v[i].n);
        v[i].cost.resize(v[i].n);
        for (int j = 0; j < v[i].n; ++j) {
            scanf("%d%d%d", &v[i].x[j], &v[i].y[j], &v[i].cost[j]);
            --v[i].x[j], --v[i].y[j];
        }
    }

    int q;
    scanf("%d\n", &q);
    //cout << "!" << q << "\n";

    vector<char> curr(k, true);
    vector<query> queries;
    char s[10];
    while (q--) {
        scanf("%s", s);
        if (s[0] == 'S') {
            int id;
            scanf("%d\n", &id);
            --id;
            curr[id] ^= 1;
            continue;
        }
        int xmin, ymin, xmax, ymax;
        scanf("%d%d%d%d\n", &xmin, &ymin, &xmax, &ymax);
        --xmin, --ymin, --xmax, --ymax;
        //cout << xmin << " " << ymin << " " << xmax << " " << ymax << "\n";
        queries.pb({curr, xmin, ymin, xmax, ymax, 0});
    }

    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < v[i].n; ++j) {
            update(v[i].x[j], v[i].y[j], v[i].cost[j]);
        }
        //cout << i << "\n";
        for (int j = 0; j < sz(queries); ++j) {
            if (!queries[j].mask[i]) {
                continue;
            }
            //cout << "!!!!!!!!!" << queries[j].xmin << " " << queries[j].xmax << " " << queries[j].ymin << " " << queries[j].ymax << "\n";
            //cout << j << "\n";
            ll ans = get(queries[j].xmax, queries[j].ymax);
            //cout << "!" << ans << "\n";
            //cout << j << "\n";
            if (queries[j].xmin) {
                ans -= get(queries[j].xmin - 1, queries[j].ymax);
            }
            //cout << "!" << ans << "\n";
            //cout << j << "\n";
            if (queries[j].ymin) {
                ans -= get(queries[j].xmax, queries[j].ymin - 1);
            }
            //cout << "!" << ans << "\n";
            //cout << j << "\n";
            if (queries[j].xmin && queries[j].ymin) {
                ans += get(queries[j].xmin - 1, queries[j].ymin - 1);
            }
            //cout << "!" << ans << "\n";
            queries[j].ans += ans;
            //cout << i << " " << j << " " << queries[j].ans << "\n";
        }
        for (int j = 0; j < v[i].n; ++j) {
            update(v[i].x[j], v[i].y[j], -v[i].cost[j]);
        }
    }

    for (int i = 0; i < sz(queries); ++i) {
        printf("%lld\n", queries[i].ans);
    }

}