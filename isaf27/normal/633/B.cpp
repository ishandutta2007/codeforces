#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <bitset>
#include <queue>
#include <set>
#include <map>

using namespace std;

#define y1 dksfbskfkjskj
#define x1 hfkhhfshorifh
#define x2 vilgvjjvskljf
#define y2 uhdsufsfhiosh

int func(int n)
{
    int ans = 0;
    int st = 5;
    while (st <= n)
    {
        ans += n / st;
        st *= 5;
    }
    return ans;
}

int main()
{
    int m;
    cin >> m;
    //if (m == 1)
    //{
    //    cout << "6\n5 6 7 8 9";
    //    return 0;
    //}
    int l = 1;
    int r = 1e9;
    while (r - l > 1)
    {
        int h = (l + r) / 2;
        if (func(h) < m)
            l = h;
        else
            r = h;
    }
    int k1 = r;
    l = 1;
    r = 1e9;
    while (r - l > 1)
    {
        int h = (l + r) / 2;
        if (func(h) > m)
            r = h;
        else
            l = h;
    }
    int k2 = l;
    cout << k2 - k1 + 1 << endl;
    for (int i = k1; i <= k2; i++)
        cout << i << " ";
    return 0;
}