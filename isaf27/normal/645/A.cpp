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
    string s1, s2, s3, s4;
    cin >> s1 >> s2 >> s3 >> s4;
    string s, t;
    if (s1[0] != 'X')
        s += s1[0];
    if (s1[1] != 'X')
        s += s1[1];
    if (s2[1] != 'X')
        s += s2[1];
    if (s2[0] != 'X')
        s += s2[0];
    if (s3[0] != 'X')
        t += s3[0];
    if (s3[1] != 'X')
        t += s3[1];
    if (s4[1] != 'X')
        t += s4[1];
    if (s4[0] != 'X')
        t += s4[0];
    s1 = s;
    string r0 = s.substr(0, 1);
    string r1 = s.substr(1, 1);
    string r2 = s.substr(2, 3);
    s2 = r1 + r2 + r0;
    //cerr << s2;
    s3 = r2 + r0 + r1;
    if (s1 == t)
    {
        cout << "YES";
        return 0;
    }
    if (s2 == t)
    {
        cout << "YES";
        return 0;
    }
    if (s3 == t)
    {
        cout << "YES";
        return 0;
    }
    cout << "NO";
    return 0;
}