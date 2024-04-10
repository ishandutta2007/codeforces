// Hydro submission #62972b1fb0c5e75beb1584e4@1654074144029
#include<bits/stdc++.h>
using namespace std;
int x[1000];
int main()
{
    int t,n,m,s1,s2,l,i,j,k;
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>n>>l;
        for(j=0;j<n;j++)
        cin>>x[j];
        m=0;
        for(k=l;k>0;k--)
        {
            s1=0,s2=0;
            for(j=0;j<n;j++)
            x[j]>>k-1&1?s2++:s1++;
            m=m*2+(s1<s2);
        }
        printf("%d\n",m);
    }
    return 0;
}