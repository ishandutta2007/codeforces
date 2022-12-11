#include <bits/stdc++.h>

using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define mp make_pair
#define pb push_back

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main()
{

    //freopen("input.txt", "r", stdin);

    int n;
    ll k;
    cin >> n >> k;

    k %= (2 * n);

    vector<pll> a(n);
    pll m;
    cin >> m.first >> m.second;

    for (int i = 0; i < n; ++i) {
        cin >> a[i].first >> a[i].second;
    }

    int i = 0;
    while (k--) {
        m.first = 2 * a[i].first - m.first;
        m.second = 2 * a[i].second - m.second;
        ++i;
        if (i == n) {
            i = 0;
        }
    }

    cout << m.first << " " << m.second << "\n";

}