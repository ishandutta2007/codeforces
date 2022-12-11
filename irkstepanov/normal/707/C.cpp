#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main()
{

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    //ios_base::sync_with_stdio(false);
    //cin.tie(0);

    ll a;
    cin >> a;

    if (a == 1 || a == 2) {
        cout << "-1\n";
        return 0;
    }

    ll d = 1;
    while (a % 2 == 0) {
        d *= 2;
        a /= 2;
    }

    if (a == 1) {
        cout << ll(3) * d / ll(4) << " " << ll(5) * d / ll(4) << "\n";
        return 0;
    }

    ll x = (a * a + 1) / 2;
    cout << d * x << " " << d * (x - 1) << "\n";

}