// Hydro submission #6274cae5bda16328ffbaf792@1651821285858
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,n,m,a,b,c,d,i,j;
    cin>>t;bool f;
    for(i=0;i<t;i++)
    {
        cin>>n>>m;
        f=false;
        for(j=0;j<n;j++)
        {
            cin>>a>>b>>c>>d;
            if(!f&&b==c)
            f=true;
        }
        if(m%2) f=false;
        printf(f?"YES\n":"NO\n");
    }
    return 0;
}