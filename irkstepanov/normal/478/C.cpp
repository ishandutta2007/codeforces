#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;

int main()
{

    ll r, g, b;
    cin >> r >> g >> b;

    if (r > 2 * (g + b)) r = 2 * (g + b);
    if (g > 2 * (r + b)) g = 2 * (r + b);
    if (b > 2 * (g + r)) b = 2 * (g + r);

    cout << (r + g + b) / 3 << "\n";

}