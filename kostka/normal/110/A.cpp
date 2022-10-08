#include "bits/stdc++.h"

using namespace std;

bool check(string a)
{
    int x = 0;
    for(int i=0; a[i]; i++)
    {
        if(a[i]=='4')
            x++;
        if(a[i]=='7')
            x++;
    }
    return ((x==4) || (x==7));
}

int main()
{
    string x;
    cin >> x;
    puts(check(x) ? "YES" : "NO");
    return 0;
}