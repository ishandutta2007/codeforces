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

    ll a, b, c;
    cin >> a >> b >> c;

    if (a != 0) {
        ll d2 = b * b - (ll)(4) * a * c;
        if (d2 < 0) {
            cout << "0\n";
            return 0;
        }
        if (d2 == 0) {
            ld ans = -b;
            ans /= a;
            ans /= 2;
            cout << "1\n";
            cout << fixed;
            cout.precision(12);
            cout << ans << "\n";
            return 0;
        }
        ld d = sqrt(d2 * 1.0);
        ld x = -b - d, y = -b + d;
        x /= a, x /= 2;
        y /= a, y /= 2;
        if (x > y) {
            swap(x, y);
        }
        cout << "2\n";
        cout << fixed;
        cout.precision(12);
        cout << x << "\n" << y << "\n";
        return 0;
    }

    if (b == 0) {
        if (c == 0) {
            cout << "-1\n";
        } else {
            cout << "0\n";
        }
        return 0;
    }

    ld ans = -c;
    ans /= b;
    cout << "1\n";
    cout << fixed;
    cout.precision(12);
    cout << ans << "\n";

}