#include <iostream>

using namespace std;

long long n,m,p[100],x,y,ans[100];

int main()
{
    cin>>n>>m;
    p[0]=1;
    for(int i=1;i<=n;i++)
        p[i]=p[i-1]*2;
    x=0,y=n-1;
    for(int i=1;i<=n;i++)
    {
        if(m>p[n-i-1])
        {
            ans[y]=i;
            y--;
            m-=p[n-i-1];
        }
        else
            ans[x++]=i;
    }
    for(int i=0;i<n;i++)
        cout<<ans[i]<<" ";
    cout<<endl;
}