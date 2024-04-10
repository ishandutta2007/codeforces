// Hydro submission #6274cc0bbda16328ffbaf8ef@1651821579582
#include<bits/stdc++.h>
using namespace std;
int b[300];
int main()
{
    int t,n,i,j,k;
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>n;
        for(j=0;j<n;j++)
        cin>>b[j];
        for(j=0,k=n-1;j<k;j++,k--)
        printf("%d %d ",b[j],b[k]);
        if(n%2) printf("%d",b[(n+1)/2-1]);
        cout<<endl;
    }
    return 0;
}