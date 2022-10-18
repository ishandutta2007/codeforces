#include <bits/stdc++.h>

using namespace std;

int main()
{
    int x1, x2, y1, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    int x3 = abs(x2-x1);
    int y3 = abs(y2-y1);
    int r = min(x3, y3);
    r += max(x3, y3) - r;
    cout << r;
}