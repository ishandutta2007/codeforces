#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long ll;

int main()
{
    ll n;
    cin >> n;
    int t = 1;
    for (ll i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            t = 0;
        }
    }
    if (t)
    {
        cout << n;
        return 0;
    }
    ll g = 0;
    for (ll i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            g = __gcd(g, i);
            g = __gcd(g, n / i);
        }
    }
    cout << g;
}