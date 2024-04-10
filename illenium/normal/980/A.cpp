#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;
int main()
{
    string s;
    cin >> s;
    int l = 0,p = 0;
    for (int i = 0;i < s.size();i++)
    {
        if (s[i] == 'o') p++;
        else l++;
    }
    if (l == 0 || p == 0) puts("Yes");
    else 
    {
        if (p > l) puts("no");
        else if (l % p == 0) puts("yes");
        else puts("no");
    }
    return 0;
}