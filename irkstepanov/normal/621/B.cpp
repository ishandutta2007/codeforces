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

    map<int, int> a, b;
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        ++a[x - y];
        ++b[x + y];
    }

    ll ans = 0;
    for (map<int, int>::iterator it = a.begin(); it != a.end(); ++it) {
        ans += (ll)(it->second) * (ll)(it->second - 1) / 2;
    }
    for (map<int, int>::iterator it = b.begin(); it != b.end(); ++it) {
        ans += (ll)(it->second) * (ll)(it->second - 1) / 2;
    }

    cout << ans << "\n";

}