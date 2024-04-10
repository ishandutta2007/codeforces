#include <iostream>
#include <map>
#include <set>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <fstream>
#include <bitset>
#include <queue>
#include <stack>
#include <deque>
#include <complex>
#include <iomanip>
#include <stdio.h>
#include <string.h>
#include <random>
#include <functional>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

ll a, m;

void solve()
{
    cin >> a >> m;
    ll g = __gcd(a, m);
    m /= g;
    ll phi = m;
    for (ll i = 2; 1LL * i * i <= m; i++)
    {
        if (m % i == 0)
        {
            phi = (phi / i) * (i - 1);
            while (m % i == 0) m /= i;
        }
    }
    if (m > 1) phi = (phi / m) * (m - 1);
    cout << phi << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
}