#include <bits/stdc++.h>
#include <string.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;
typedef pair<ll, int> pll;

int main()
{

    //ifstream cin("input.txt");
    //freopen("input.txt", "r", stdin);

    ll n, m;
    cin >> n >> m;

    vector<ll> cnt(11);
    for (ll i = 0; i < m; ++i) {
        ll a, b;
        cin >> a >> b;
        cnt[b] += a;
    }

    ll ans = 0;
    for (int i = 10; i; --i) {
        if (cnt[i] <= n) {
            ans += cnt[i] * i;
            n -= cnt[i];
        } else {
            ans += n * i;
            n = 0;
            break;
        }
    }

    cout << ans << "\n";

}