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
    int n;
    cin >> n;
    int x1 = 0;
    int x2 = 0;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        if (a < 0)
            x1++;
        else
            x2++;
    }
    if (x1 <= 1 || x2 <= 1)
        cout << "Yes";
    else
        cout << "No";
    return 0;
}