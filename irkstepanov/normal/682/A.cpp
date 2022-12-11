#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define mp make_pair
#define pb push_back

#define fori for (int i = 0; i < n; ++i)
#define forj for (int j = 0; j < n; ++j)

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ld, ld> pll;

int main()
{

    //ifstream cin("input");
    //ofstream cout("output");

    //freopen("input", "r", stdin);

    int n, m;
    cin >> n >> m;

    vector<int> a(5), b(5);
    for (int i = 1; i <= m; ++i) {
        ++b[i % 5];
    }

    ll ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans += b[(5 - (i % 5)) % 5];
    }

    cout << ans << "\n";

}