// Hydro submission #6274cfccbda16328ffbafdbf@1651822540938
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,r,b,d,mx,i;
    long long mn;
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>r>>b>>d;
        mn=min(r,b);
        mx=max(r,b);
        printf(mn*(d+1)<mx?"NO\n":"YES\n");
    }
    return 0;
}