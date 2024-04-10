#include <iostream>

using namespace std;

int main()
{
    int n,m,p,a[1010]={0};
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin >>u>>v;
        a[u]=1;
        a[v]=1;
    }
    for(int i=1;i<=n;i++)
        if(a[i]==0)
        {
            p=i;
            break;
        }
    cout<<n-1<<endl;
    for(int i=1;i<=n;i++)
    {
        if(i!=p)
            cout<<p<<" "<<i<<endl;
    }
}