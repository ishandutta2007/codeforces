// Hydro submission #6274cbf5997df5291339cf72@1651821558630
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,n,k,i,j;
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>n>>k;
        for(j=0;j<n;j++)
        printf("%c",97+j%3);
        cout<<endl;
    }
    return 0;
}