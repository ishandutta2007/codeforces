#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int) (a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;

int main()
{

    int n;
    map<int, int> x, y;
    map<pair<int ,int>, int> m;
    scanf("%d", &n);

    while (n--) {
        int a, b;
        scanf("%d%d", &a, &b);
        ++x[a];
        ++y[b];
        ++m[mp(a, b)];
    }

    ll ans = 0;
    for (auto& it : x) {
        ans += (ll)(it.second) * (ll)(it.second - 1) / 2;
    }
    for (auto& it : y) {
        ans += (ll)(it.second) * (ll)(it.second - 1) / 2;
    }
    for (auto& it : m) {
        ans -= (ll)(it.second) * (ll)(it.second - 1) / 2;
    }

    cout << ans << "\n";

}