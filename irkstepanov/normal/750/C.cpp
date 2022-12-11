#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;

const ll inf = 1e18;

int main()
{

    //ifstream cin("input.txt");

    //freopen("input.txt", "r", stdin);

    ll l = -inf, r = inf;

    int n;
    cin >> n;
    ll d = 0;

    while (n--) {
        ll x;
        cin >> x;
        int p;
        cin >> p;
        if (p == 1) {
            l = max(l, 1900LL - d);
        } else {
            r = min(r, 1899LL - d);
        }
        d += x;
    }

    if (l > r) {
        cout << "Impossible\n";
        return 0;
    }

    if (r == inf) {
        cout << "Infinity\n";
        return 0;
    }

    cout << r + d << "\n";

}