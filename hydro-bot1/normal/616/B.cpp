// Hydro submission #625507a9ac286d0a56b8603a@1649739704992
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int c,n,m,i,j,mn,mx=1;
    cin>>n>>m;
    for(i=0;i<n;i++)
    {
        mn=1000000000;
        for(j=0;j<m;j++)
        {
            cin>>c;
            if(c<mn)
            mn=c;
        }
        if(mn>mx)
        mx=mn;
    }
    printf("%d\n",mx);
    return 0;
}