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
int n, a[5000];
//
signed main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    reverse(a + 1, a + n - 1);
    reverse(a, a + n);
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
}