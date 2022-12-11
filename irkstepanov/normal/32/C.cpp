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
typedef pair<ll, ll> pll;

int main()
{

    //ifstream cin("input.txt");
    //freopen("input.txt", "r", stdin);

    //ios_base::sync_with_stdio(false);
    //cin.tie(0);

    int n, m, s;
    cin >> n >> m >> s;

    ll xx = 0;
    ll yy = 0;

    for (int x = 0; x < s && x < n; ++x) {
        int cnt = (n - x - 1) / s;
        if (cnt == (n - 1) / s) {
            ++xx;
        }
    }
    for (int y = 0; y < s && y < m; ++y) {
        int cnt = (m - y - 1) / s;
        if (cnt == (m - 1) / s) {
            ++yy;
        }
    }

    cout << xx * yy * (ll)((n - 1) / s + 1) * (ll)((m - 1) / s + 1) << "\n";

}