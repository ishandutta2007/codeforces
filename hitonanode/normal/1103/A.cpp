#include <bits/stdc++.h>
using namespace std;

int main()
{
    string S;
    cin >> S;
    int v = 1, h = 1;
    for (auto c : S)
    {
        if (c == '0')
        {
            printf("1 %d\n", v);
            v++;
            if (v > 4) v -= 4;
        }
        else
        {
            printf("3 %d\n", h);
            h += 2;
            if (h > 4) h -= 4;
        }
    }
}