#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main()
{

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll n, k;
    cin >> n >> k;
    vector<ll> v;

    for (ll d = 1; d * d <= n; ++d) {
        if (n % d == 0) {
            v.pb(d);
            if (d * d != n) {
                v.pb(n / d);
            }
        }
    }

    sort(all(v));
    if (k > sz(v)) {
        cout << "-1\n";
    } else {
        cout << v[k - 1] << "\n";
    }

}