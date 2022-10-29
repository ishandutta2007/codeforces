#include <bits/stdc++.h>
#define pb push_back
using namespace std;

int main()
{
    long a,b,c=0;
    cin>>a>>b;
    while(a<=b)
    {
        a*=3;
        b*=2;
        c++;
    }
    cout<<c;
    return 0;
}