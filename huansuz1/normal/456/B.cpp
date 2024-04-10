#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <string>
#include <cstdio>
#include <cmath>
#include <map>
#include <set>

using namespace std;

int n, m, a[500000], k;
string s;

int main()
{
    cin >> s;

    n = s.length();

    for (int i = 0; i < n; i++)
        a[i + 1] = int(s[i]) - 48;

    for (int i = 1; i <= n; i++)
    {
        k *= 10;
        k += a[i];
    
        k %= 4;
    }
    if (k == 0)
    {
        cout << 4 << endl;
    }
    else cout << 0 << endl;


    return 0;
}