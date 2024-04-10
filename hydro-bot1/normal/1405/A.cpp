// Hydro submission #6274c9bc997df5291339c8f9@1651820989097
#include<bits/stdc++.h>
using namespace std;
int p[100];
int main()
{
    int t,n,i,j;
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>n;
        for(j=0;j<n;j++)
        cin>>p[j];
        for(j=n-1;j+1;j--)
        printf("%d ",p[j]);
        cout<<endl;
    }
    return 0;
}