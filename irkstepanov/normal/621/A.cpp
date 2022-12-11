#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back
#define sz(a) static_cast<int>((a).size())
#define all(a) (a).begin(), (a).end()
#define forn(i, n) for (int i = 0; i < n; ++i)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pii;

int main()
{

    ios::sync_with_stdio(false);

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    int n;
    cin >> n;

    vector<ll> odd;
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        ll a;
        cin >> a;
        if (a % 2) {
            odd.pb(a);
        } else {
            ans += a;
        }
    }

    sort(all(odd));
    reverse(all(odd));
    if (sz(odd) % 2) {
        odd.pop_back();
    }

    for (ll a : odd) {
        ans += a;
    }

    cout << ans << "\n";

}