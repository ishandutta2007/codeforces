#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back
#define all(a) (a).begin(), (a).end()
#define sz(a) (int) (a).size()
#define openStream(in, out) ifstream cin(in); ofstream cout(out);

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pii;

int main()
{

    int n;
    cin >> n;

    ll ans = 0;
    ll a = 0;
    vector<ll> b(n);
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }

    for (int i = 0; i < n; ++i) {
        if (a != b[i]) {
            ans += abs(a - b[i]);
            a = b[i];
        }
    }

    cout << ans << "\n";

}