#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;

int main()
{

    //ifstream cin("input.txt");
	//ofstream cout("output.txt");
    //freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll a, b, c, d;
    cin >> a >> b >> c >> d; //

    ll dx = abs(a - c), dy = abs(b - d);
    ll x, y;
    cin >> x >> y;

    if (dx % x || dy % y) {
        cout << "NO\n";
        return 0;
    }

    dx /= x, dy /= y;
    cout << (dy % 2 == dx % 2 ? "YES\n" : "NO\n");

}