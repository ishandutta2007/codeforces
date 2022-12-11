#include <bits/stdc++.h>

#define sz(a) static_cast<int>(a.size())
#define all(a) (a).begin(), (a).end()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int main()
{

    ll n, b, p;
    cin >> n >> b >> p;

    ll ans1 = 0, ans2 = n * p;
    while (n > 1) {
        ll k = 0;
        for (; (1 << k) <= n; ++k) ;
        --k;
        ans1 += 2 * b * (1 << (k - 1));
        ans1 += (1 << (k - 1));
        n -= (1 << (k - 1));
    }

    cout << ans1 << " " << ans2 << "\n";

}