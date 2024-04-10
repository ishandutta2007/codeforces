#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

typedef long long ll;

int main()
{

    int n;
    cin >> n;

    ll a[100500];
    ll sum = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }

    ll k = sum / n;
    ll extra = 0;
    ll ans = 0;

    for (int i = 0; i < n; i++)
    {
        extra += (k - a[i]);
        ans += abs(extra);
    }

    cout << ans;

}