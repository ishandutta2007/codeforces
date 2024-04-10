#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[2009],b[2009];
int ans[2008];
void go(int x,int u)
{
    for(int i=1;i<=x;i++)b[i]=a[i];
    for(int i=1;i<=x;i++)
    {
        int q=i+u;
        if(q>x)q-=x;
        a[i]=b[q];
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n;
        for(int i=1;i<=n;i++)cin>>a[i];
        for(int i=n;i>=1;i--)
        {
            int pos;
            for(int j=1;j<=i;j++)
            if(a[j]==i){pos=j;break;}
            ans[i]=(pos%i);
            go(i,ans[i]);
        }
        for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}