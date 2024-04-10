// Hydro submission #6274ce52997df5291339d725@1651822163018
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,n,k,i,j;
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>n>>k;
        printf("%d\n",n-k+k/2);
        for(j=k+1;j<=n;j++)
        printf("%d ",j);
        for(j=k-1;j*2>=k;j--)
        printf("%d ",j);
        cout<<endl;
    }
    return 0;
}