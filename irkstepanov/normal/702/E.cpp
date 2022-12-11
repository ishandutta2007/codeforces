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

const ll inf = 1e18 + 100;
const int rmax = 40;

int main()
{

    //ifstream cin("input.txt");
    //freopen("input.txt", "r", stdin);

    //ios_base::sync_with_stdio(false);
    //cin.tie(0);

    int n;
    ll k;
    scanf("%d%lld", &n, &k);
    vector<int> g(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &g[i]);
    }
    vector<ll> w(n);
    for (int i = 0; i < n; ++i) {
        scanf("%lld", &w[i]);
    }

    vector<vector<ll> > s(n, vector<ll>(rmax)), m(n, vector<ll>(rmax));
    vector<vector<int> > p(n, vector<int>(rmax));
    for (int i = 0; i < n; ++i) {
        s[i][0] = w[i];
        m[i][0] = w[i];
        p[i][0] = g[i];
    }

    for (int r = 1; r < rmax; ++r) {
        for (int i = 0; i < n; ++i) {
            int t = p[i][r - 1];
            s[i][r] = s[i][r - 1] + s[t][r - 1];
            m[i][r] = min(m[i][r - 1], m[t][r - 1]);
            p[i][r] = p[t][r - 1];
        }
    }

    for (int i = 0; i < n; ++i) {
        ll sum = 0, minn = inf;
        ll t = k;
        int v = i;
        for (int r = rmax - 1; r >= 0; --r) {
            if ((1LL << r) <= t) {
                sum += s[v][r];
                minn = min(minn, m[v][r]);
                v = p[v][r];
                t -= (1LL << r);
            }
        }
        printf("%lld %lld\n", sum, minn);
    }

}