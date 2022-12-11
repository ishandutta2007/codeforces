#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back
#define sz(a) static_cast<int>((a).size())
#define all(a) (a).begin(), (a).end()
#define forn(i, n) for (int i = 0; i < n; ++i)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pii;

int main()
{

    ios::sync_with_stdio(false);

    //ifstream cin("division.in");
    //ofstream cout("division.out");

    int n;
    cin >> n;
    vector<vector<ll> > d(n, vector<ll>(n));
    ll sum = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> d[i][j];
            if (i < j) {
                sum += d[i][j];
            }
        }
    }

    int q;
    cin >> q;
    while (q--) {
        int u, v;
        ll l;
        cin >> u >> v >> l;
        --u, --v;
        vector<vector<ll> > dnew = d;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                ll r = min(d[i][u] + l + d[v][j], d[i][v] + l + d[u][j]);
                if (r < d[i][j]) {
                    sum -= d[i][j];
                    sum += r;
                    dnew[i][j] = dnew[j][i] = r;
                }
            }
        }
        d = dnew;
        cout << sum << " ";
    }

}