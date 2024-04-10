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

    ll n, a, b, c, d;
    cin >> n >> a >> b >> c >> d;

    ll xmax = n;
    ll xmin = 1;
    xmax = min(xmax, n - (b - c));
    xmin = max(xmin, 1 - (b - c));

    xmax = min(xmax, n - (a - d));
    xmin = max(xmin, 1 - (a - d));

    xmax = min(xmax, n -(a + b - c - d));
    xmin = max(xmin, 1 - (a + b - c - d));

    ll x = 0;
    if (xmax >= xmin) {
        x = xmax - xmin + 1;
    }
    cout << x * n << "\n";

}