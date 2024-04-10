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
const int MAX_N = 100001;

int n, k, a[MAX_N];
string s;

int kol_substr(int l, int r)
{
    if (l < 0)
        l = 0;
    if (r >= n)
        r = n - 1;
    return a[r + 1] - a[l];
}

int main()
{
    /*freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);/**/
    cin >> n >> k >> s;
    a[0] = 0;
    for (int i = 1; i <= n; i++)
        a[i] = a[i - 1] + (s[i - 1] == '0');
    int l = 0;
    int r = n;
    while (r - l > 1)
    {
        int h = (l + r) / 2;
        bool check = false;
        for (int i = 0; i < n; i++)
            if (kol_substr(i - h, i + h) >= k + 1 && s[i] == '0')
                check = true;
        if (check)
            r = h;
        else
            l = h;
    }
    cout << r;
    return 0;
}