#include <bits/stdc++.h>

using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define mp make_pair
#define pb push_back

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ld, ld> pll;

int main()
{

    //ifstream cin("input.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll n, d, m, l;
    cin >> n >> d >> m >> l;

    ll x = 0, y = l;
    ll curr = 0;

    while (x <= (n - 1) * m) {
        if (curr >= x && curr <= y) {
            ll k = (y - curr) / d + 1;
            curr += k * d;
            continue;
        }
        x += m, y += m;
    }

    cout << curr << "\n";

}