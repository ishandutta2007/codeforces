#include <bits/stdc++.h>
#include <string.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;
typedef pair<ll, int> pll;

const int inf = 1e9;

int main()
{

    //ifstream cin("input.txt");
    //freopen("input.txt", "r", stdin);

    //ios_base::sync_with_stdio(false);
    //cin.tie(0);

    int n, m;
    scanf("%d%d", &n, &m);

    vector<vector<int> > g(n);
    vector<int> pr(2 * n * n, -1);

    for (int i = 0; i < m; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        --u, --v;
        g[u].pb(v);
        g[v].pb(u);
    }

    pr[2 * (n - 1)] = 2 * (n - 1);
    queue<int> q;
    q.push(2 * (n - 1));

    while (!q.empty()) {
        int v = q.front();
        q.pop();
        int a = (v / 2) / n, b = (v / 2) % n;
        if (v & 1) {
            for (int x : g[b]) {
                if (x != a) {
                    int val = 2 * (a * n + x);
                    if (pr[val] == -1) {
                        pr[val] = v;
                        q.push(val);
                    }
                }
            }
        } else {
            for (int x : g[a]) {
                int val = 2 * (x * n + b) + 1;
                if (pr[val] == -1) {
                    pr[val] = v;
                    q.push(val);
                }
            }
        }
    }

    if (pr[2 * (n - 1) * n] == -1) {
        printf("-1\n");
        return 0;
    }

    vector<int> ans;
    int curr = 2 * (n - 1) * n;
    while (curr != 2 * (n - 1)) {
        ans.pb(curr);
        curr = pr[curr];
    }
    ans.pb(2 * (n - 1));
    reverse(all(ans));

    vector<int> a, b;
    for (int i = 0; i < sz(ans); ++i) {
        a.pb((ans[i] / 2) / n);
        b.pb((ans[i] / 2) % n);
    }

    a.resize(unique(all(a)) - a.begin());
    b.resize(unique(all(b)) - b.begin());
    printf("%d\n", sz(a) - 1);
    for (int x : a) {
        printf("%d ", x + 1);
    }
    printf("\n");
    for (int x : b) {
        printf("%d ", x + 1);
    }
    printf("\n");

}