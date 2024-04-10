#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <string>

#define pb push_back

using namespace std;

int main()
{

    string s;
    cin >> s;

    int d[100500];
    d[0] = 0;

    for (int r = 1; r < s.size(); r++)
        d[r] = d[r - 1] + (s[r - 1] == s[r]);

    int m;
    cin >> m;
    while (m--)
    {
        int l, r;
        cin >> l >> r;
        l--, r--;
        cout << d[r] - d[l] << "\n";
    }

}