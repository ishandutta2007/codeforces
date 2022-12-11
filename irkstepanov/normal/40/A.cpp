#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define pb push_back
#define sz(a) (int)(a).size()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef double ld;

int main() {

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    ll x, y;
    cin >> x >> y;

    ll r2 = x * x + y * y;
    ll r = ll(sqrt(ld(r2)));

    for (ll u = r - 2; u <= r + 2; ++u) {
        if (u * u == r2) {
            cout << "black\n";
            return 0;
        }
    }

    if (y < 0) {
        y *= (-1), x *= (-1);
    }

    if (x > 0) {
        cout << (r % 2 == 0 ? "black\n" : "white\n");
    } else {
        cout << (r % 2 == 1 ? "black\n" : "white\n");
    }

}