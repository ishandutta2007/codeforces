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

int main()
{

    //ifstream cin("input.txt");
    //freopen("input.txt", "r", stdin);

    //ios_base::sync_with_stdio(false);
    //cin.tie(0);

    int n;
    scanf("%d", &n);

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }

    map<int, int> m;
    ll ans = 0;

    for (int i = 0; i < n; ++i) {
        for (int x = 0; x < 31; ++x) {
            if (m.count((1 << x) - a[i])) {
                ans += m[(1 << x) - a[i]];
            }
        }
        ++m[a[i]];
    }

    cout << ans << "\n";

}