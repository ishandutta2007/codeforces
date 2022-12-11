#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define mp make_pair
#define pb push_back

#define fori for (int i = 0; i < n; ++i)
#define forj for (int j = 0; j < n; ++j)

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

ll gcd(ll a, ll b)
{
    if (a < b) {
        swap(a, b);
    }
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

int main()
{

    //ifstream cin("input");
    //ofstream cout("output");

    //freopen("input", "r", stdin);

    ll n, a, b, p, q;
    cin >> n >> a >> b >> p >> q;

    ll g = gcd(a, b);
    ll t = a * b / g;

    ll cool = n / t;
    ll aa = n / a - cool;
    ll bb = n / b - cool;

    ll ans = max(p, q) * cool + p * aa + q * bb;
    cout << ans << "\n";

}