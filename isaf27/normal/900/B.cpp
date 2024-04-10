#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double ld;

const int M = 3 * 1e5 + 1;
const int BIG = 2 * 1e9 + 1;
const ll INF = 2 * 1e18;
const ll MOD = 1e9 + 7;
const int two = 2;
const int four = 4;
const ld pi = acos(-1.0);
const ld eps = 1e-5;

int main()
{
    #ifndef ONLINE_JUDGE
    //*
    #define fname "test"
    freopen(fname".in", "r", stdin);
    freopen(fname".out", "w", stdout); /**/
    #endif // ONLINE_JUDGE
    ll a, b, c;
    cin >> a >> b >> c;
    a %= b;
    for (int i = 0; i < 100000; i++)
    {
        int x = (10 * a) / b;
        if (x == c)
        {
            cout << i + 1;
            return 0;
        }
        a = (10 * a) % b;
    }
    cout << "-1";
    return 0;
}