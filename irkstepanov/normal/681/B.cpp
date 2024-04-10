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

const int inf = 1e8;

int main()
{

    //ifstream cin("input");
    //ofstream cout("output");

    //freopen("input", "r", stdin);

    ll n;
    cin >> n;

    for (ll a = 0; a <= 100; ++a) {
        for (ll b = 0; b <= 1000; ++b) {
            ll c = n - (ll)1234567 * a - (ll)123456 * b;
            if (c >= 0 && c % 1234 == 0) {
                cout << "YES\n";
                return 0;
            }
        }
    }

    cout << "NO\n";

}