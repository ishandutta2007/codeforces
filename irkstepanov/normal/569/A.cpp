#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back

#define all(a) (a).begin(), (a).end()
#define sz(a) (int) (a).size()

using namespace std;

typedef long long ll;

int main()
{

    ll s, t, q;
    cin >> t >> s >> q;

    int ans = 1;
    ll v = s;
    while (q * v < t)
    {
        ++ans;
        v *= q;
    }

    cout << ans << "\n";

}