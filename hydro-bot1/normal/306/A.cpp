// Hydro submission #6253d139ca53060146716f99@1649660218056
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i,n,m,t;
    cin>>n>>m;
    t=n%m;n/=m;
    for(i=0;i<m;i++)
    {
        if(t-->0) printf("%d ",n+1);
        else printf("%d ",n);
    }
    cout<<endl;
    return 0;
}