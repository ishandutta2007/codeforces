// Hydro submission #6274cd55997df5291339d25b@1651821910351
#include<bits/stdc++.h>
using namespace std;
int s[100];
int main()
{
    int t,n,a,mx,i,j;
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>n;
        for(j=0;j<n;j++)
        s[j]=0;mx=0;
        for(j=0;j<n;j++)
        {
            cin>>a;
            s[a-1]++;
        }
        for(j=0;j<n;j++)
        mx=max(mx,s[j]);
        printf("%d\n",mx);
    }
    return 0;
}