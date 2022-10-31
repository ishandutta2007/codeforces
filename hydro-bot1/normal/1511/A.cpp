// Hydro submission #6274cf1a997df5291339d8a4@1651822362319
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,n,r,s,i,j;
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>n;s=0;
        for(j=0;j<n;j++)
        {
            cin>>r;
            if(r-2) s++;
        }
        printf("%d\n",s);
    }
    return 0;
}