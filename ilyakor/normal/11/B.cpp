#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <cstring>
#include <cstdio>
#include <cassert>
#include <queue>
#include <bitset>
//#include <cmath>
#include <sstream>
#include <string>
#include <vector>

#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()

using namespace std;

typedef pair<int, int> ii;
typedef long long int64;
typedef vector<int> vi;

int main()
{
    int64 n;
    cin >> n;
    if (n < 0) n = -n;
    for (int64 res = 0; ; res++)
    {
        int64 tmp = res * (res + 1);
        tmp /= 2LL;
        tmp = n + tmp;
        if (tmp % 2) continue;
        int64 t = tmp / 2LL;
        if (t <= (res * (res + 1)) / 2LL)
        {
            cout << res << "\n";
            return 0;
        }
    }
    return 0;
}