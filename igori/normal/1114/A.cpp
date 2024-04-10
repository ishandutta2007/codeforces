#pragma GCC optimize("O2")
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <cstring>
#include <cmath>
#include <stdio.h>
#include <time.h>
#include <iomanip>
#include <bitset>

using namespace std;
typedef long long ll;
ll x, y, z, a, b, c;
signed main()
{
    cin >> x >> y >> z;
    cin >> a >> b >> c;
    if (a >= x && a + b >= x + y && a + b + c >= x + y + z)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
}