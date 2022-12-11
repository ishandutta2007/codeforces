#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pll;

int main()
{

    //freopen("input.txt", "r", stdin);

    ll a, b, c;
    cin >> a >> b >> c;

    if (c == 0) {
        if (a == b) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
        return 0;
    }

    ll d = b - a;
    if (d % c != 0) {
        cout << "NO\n";
        return 0;
    }

    d /= c;
    if (d < 0) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
    }

}