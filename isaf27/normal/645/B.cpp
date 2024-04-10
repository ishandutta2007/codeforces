#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <bitset>
#include <cmath>
#include <time.h>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>

using namespace std;

int main()
{
    /*freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);/**/
    long long n, k;
    cin >> n >> k;
    if (k >= n / 2)
        k = n / 2;
    long long s = n - 2 * k;
    if (s == 0)
        s = 1;
    cout << ((n * (n - 1)) / 2 - (s * (s - 1)) / 2);
    return 0;
}