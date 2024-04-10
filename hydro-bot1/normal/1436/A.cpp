// Hydro submission #6274cb48997df5291339cda8@1651821384290
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,n,m,a,i,j,s;
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>n>>m;s=0;
        for(j=0;j<n;j++)
        cin>>a,s+=a;
        printf(s-m?"NO\n":"YES\n");
    }
    return 0;
}