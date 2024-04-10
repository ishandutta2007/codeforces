#include <iostream>
#include <cstdio>
#include <algorithm>
#include <bitset>
#include <vector>
#include <queue>
#include <cmath>
#include <set>
#include <map>

using namespace std;

const int MAX_N = 100001;

typedef long long ll;
#define filename "test"
#define fin for (int i = 0; i < n; i++)
#define fim for (int i = 0; i < m; i++)
#define fjn for (int j = 0; j < n; j++)
#define fjm for (int j = 0; j < m; j++)

string s;

int main()
{
    //freopen(filename".in", "r", stdin);
    //freopen(filename".out", "w", stdout);
    cin >> s;
    ll ans = 0;
    int r = s.length();
    for (int i = 0; i < r - 1; i++)
    {
        int x = 10 * (s[i] - '0') + (s[i + 1] - '0');
        if (x % 4 == 0)
            ans += i + 1;
    }
    for (int i = 0; i < r; i++)
        if ((s[i] - '0') % 4 == 0)
            ans++;
    cout << ans;
    return 0;
}