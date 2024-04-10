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

const int inf = 2e9 + 10;

int main()
{

    //ifstream cin("input.txt");
    //freopen("input.txt", "r", stdin);

    //ios_base::sync_with_stdio(false);
    //cin.tie(0);

    int n, m;
    scanf("%d%d", &n, &m);

    vector<int> a(n), b(m);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    for (int j = 0; j < m; ++j) {
        scanf("%d", &b[j]);
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int pos = lower_bound(all(b), a[i]) - b.begin();
        int val = inf;
        if (pos < m) {
            val = min(val, b[pos] - a[i]);
        }
        if (pos > 0) {
            val = min(val, a[i] - b[pos - 1]);
        }
        ans = max(ans, val);
    }
    cout << ans << "\n";

}