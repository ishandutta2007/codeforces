#include <bits/stdc++.h>
using namespace std;
int a[200009],n;
int pr[200009],h[200008];
int ans,l,r;
void go(int x,int y)
{
    if(x>y)return;
    if(h[y]==h[x-1])
    {
        if(pr[y]-pr[x-1]>ans){ans=pr[y]-pr[x-1];l=x-1;r=n-y;return;}
    }
   int u=x,v=y;
   while(h[v]!=h[u-1])v--;
   //cout<<u<<" "<<v<<endl;
   if(pr[v]-pr[u-1]>ans){ans=pr[v]-pr[u-1];l=u-1;r=n-v;}
   u=x,v=y;
   while(h[v]!=h[u-1])u++;
  // cout<<u<<" "<<v<<endl;
   if(pr[v]-pr[u-1]>ans){ans=pr[v]-pr[u-1];l=u-1;r=n-v;}

}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        vector<int>g;
        g.push_back(0);
        h[0]=1;
        for(int i=1;i<=n;i++)
            {cin>>a[i];
            pr[i]=pr[i-1];
            h[i]=h[i-1];
            if((a[i]==2) || (a[i]==-2))pr[i]++;
            if(a[i]<0)h[i]=1-h[i];
            if(a[i]==0)g.push_back(i);
            }
            g.push_back(n+1);
            ans=0,l=n,r=0;
            for(int i=0;i+1<g.size();i++)go(g[i]+1,g[i+1]-1);

            cout<<l<<" "<<r<<endl;
    }
    return 0;
}