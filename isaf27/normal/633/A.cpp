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

int main()
{
    long long a, b, c;
    cin >> a >> b >> c;
    for (long long x = 0; x <= 10000; x++)
        for (long long y = 0; y <= 10000; y++)
            if (a * x + b * y == c)
    {
        cout << "Yes";
        return 0;
    }
    cout << "No";
    return 0;
}