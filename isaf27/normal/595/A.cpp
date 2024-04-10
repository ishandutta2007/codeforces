#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <bitset>
#include <cmath>
#include <set>
#include <map>

using namespace std;

int main()
{
    /*freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);/**/
    int n, m;
    cin >> n >> m;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        for (int j = 0; j < m; j++)
            cin >> a >> b, ans += a | b;
    }
    cout << ans;
    return 0;
}