#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;

const int nmax = 1010;

int dist[nmax];

struct object {
    int w, c;
    object() {}
    object(int w, int c) : w(w), c(c) {}
};

int solve(vector<object>& a, int k) {
    int n = sz(a);
    vector<ll> dp = {0};
    for (int i = 0; i < n; ++i) {
        vector<ll> nx = dp;
        for (int w = 0; w < sz(dp); ++w) {
            if (dp[w] == -1) {
                continue;
            }
            while (w + a[i].w >= sz(nx)) {
                nx.pb(-1);
            }
            nx[w + a[i].w] = max(nx[w + a[i].w], dp[w] + a[i].c);
        }
        dp.swap(nx);
    }
    ll ans = -1;
    for (int i = 0; i <= k && i < sz(dp); ++i) {
        ans = max(ans, dp[i]);
    }
    return ans;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //ifstream cin("input.txt");
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //ofstream cout("output.txt");

    memset(dist, -1, sizeof(dist));
    dist[1] = 0;

    queue<int> q;
    q.push(1);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int x = 1; x <= v; ++x) {
            int to = v + (v / x);
            if (to >= nmax) {
                continue;
            }
            if (dist[to] == -1) {
                dist[to] = dist[v] + 1;
                q.push(to);
            }
        }
    }
    /*for (int i = 1; i < nmax; ++i) {
        assert(dist[i] >= 0 && dist[i] <= 13);
    }
    cout << "YES\n";
    return 0;*/

    int tt;
    cin >> tt;

    while (tt--) {
        int n, k;
        cin >> n >> k;
        vector<object> a(n);
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            a[i].w = dist[x];
        }
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            a[i].c = x;
        }
        /*for (int i = 0; i < n; ++i) {
            cout << a[i].w << " " << a[i].c << "\n";
        }*/
        cout << solve(a, k) << "\n";
    }

}