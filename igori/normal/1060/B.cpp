#include <iostream>
#include <string>
#include <vector>

using namespace std;
typedef long long ll;
string s;
ll ds(ll x)
{
    ll a = 0;
    while (x > 0)
    {
        a += x % 10;
        x /= 10;
    }
    return a;
}
int main() {
    ll n;
    cin >> n;
    if (n < 10)
    {
        cout << n;
        return 0;
    }
    ll c = 9;
    ll ans = 0;
    for (int i = 0; c <= n; i++)
    {
        if (ds(c) + ds(n - c) > ans)
            ans = ds(c) + ds(n - c);
        c = (c + 1) * 10 - 1;
    }
    cout << ans;
}