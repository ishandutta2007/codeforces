#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,x,bit[100009][2];
void add(int x,int id,int val)
{
    while(x<=n)
    {
        bit[x][id]+=val;
        x+=(x&(-x));
    }
}
ll cal(int x,int id)
{
    ll res=0;
    while(x>0)
    {
        res+=bit[x][id];
        x-=(x&(-x));
    }
    return res;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    ll res=0,num=0;
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        x=n-x+1;
        num+=cal(x,0);
        res+=(n-i+1)*cal(x,1);
        add(x,0,1);
        add(x,1,i);
    }
    double ans=num,g=n*(n+1)/2;
    ans-=(res+0.0)/g;
    for(int i=1;i<=n;i++)
    {
        double u=((n-i+1.0)/g)*((i+0.0)*(i-1.0)/4.0);
        ans+=u;
    }
    cout<<fixed<<setprecision(10)<<ans;
    return 0;
}