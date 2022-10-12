#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <cstring>
#include <cmath>
#include <stdio.h>
#include <time.h>
#include <iomanip>
#include <bitset>

using namespace std;

typedef long long ll;

string a, b, s;

int main()
{
    cin >> a >> b >> s;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] <= '9' && '0' <= s[i])
        {
            cout << s[i];
            continue;
        }
        for (int j = 0; j < 26; j++)
        {
            if (a[j] == s[i])
            {
                cout << b[j];
            }
        }
        for (int j = 0; j < 26; j++)
        {
            if (a[j] - 'a' + 'A' == s[i])
            {
                cout << (char)(b[j] - 'a' + 'A');
            }
        }
    }
}