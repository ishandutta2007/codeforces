#include <iostream>
#include<algorithm>

using namespace std;

long long n,m,a[20000],ans;

int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=0;i<m;i++)
    {
        int v,u;
        cin>>v>>u;
        ans+=min(a[v],a[u]);
    }
    cout<<ans<<endl;
}