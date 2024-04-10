#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    int x,y,z;
    cin>>x>>y>>z;
    int ans=min(x,min(y-1,z-2));
    cout<<3*ans+3;
    return 0;
}