#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int spr[100009][19],n;
map<int,ll>ans;
int go(int st,int x)
{
    for(int i=18;i>=0;i--)
    {
        if(st+(1<<i)>n)continue;
        if(spr[st][i]%x)continue;
        st+=(1<<i);
    }
    return st-1;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=0;i<n;i++)cin>>spr[i][0];
    for(int j=1;(1<<j)<=n;j++)
      for(int i=0;i+(1<<j)<=n;i++)
        spr[i][j]=__gcd(spr[i][j-1],spr[i+(1<<(j-1))][j-1]);

    for(int i=0;i<n;i++)
    {
        int st=i,g=spr[i][0];
        while(st<n)
        {
            g=__gcd(g,spr[st][0]);
            int u=go(st,g);
            ans[g]+=u-st+1;
            st=u+1;
        }
    }
    int q;
    cin>>q;
    while(q--)
    {
        int x;
        cin>>x;
        cout<<ans[x]<<endl;
    }
    return 0;
}