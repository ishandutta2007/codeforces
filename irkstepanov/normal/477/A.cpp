#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;

const ll mod = 1000000007;

int main()
{

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    ll a, b;
    cin >> a >> b;

    ll ans = b * (b - 1) / 2;
    ans %= mod;

    ll x = a * (a + 1) / 2;
    x %= mod;
    x *= b;
    x += a;
    x %= mod;

    ans *= x;
    ans %= mod;

    cout << ans << "\n";

}