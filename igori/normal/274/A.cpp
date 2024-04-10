#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>
#include <bitset>
#include <time.h>
//
using namespace std;
//
#define int long long
//
int n, a[105000], k;
map<int, int> cel;
//
signed main()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    for (int i = 0; i < n; i++)
    {
        if (a[i] % k == 0 && cel[a[i] / k] == 1)
            continue;
        cel[a[i]]++;
        a[n]++;
    }
    cout << a[n];
}