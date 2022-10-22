#include <bits/stdc++.h>

using namespace std;

int main()
{
int a,b,c;
cin>>a>>b>>c;
int g = min(a,b/2);
g = min(g,c/4);
cout<< g+2*g+4*g;
    return 0;
}