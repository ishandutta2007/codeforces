#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long a,b,c;
cin>>a>>b>>c;

long long x=min(a, b+c);
long long y=min(c, a+b);
long long z=min(b, a+c);

cout<<x+y+z;

    return 0;
}