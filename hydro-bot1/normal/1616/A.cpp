// Hydro submission #62972a17b0c5e75beb158296@1654073879969
#include<bits/stdc++.h>
using namespace std;
int s[101];
int main()
{
    int t,n,m,a,i,j;
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>n;
        for(j=0;j<101;j++)
        s[j]=0;m=0;
        for(j=0;j<n;j++)
        cin>>a,s[abs(a)]++;
        for(j=1;j<101;j++)
        m+=min(s[j],2);
        printf("%d\n",m+min(s[0],1));
    }
    return 0;
}