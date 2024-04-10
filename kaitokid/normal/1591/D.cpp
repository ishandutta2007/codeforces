#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int bit[500009],n;
bool vis[500009];
void add(int x)
{
    while(x<=n)
    {
        bit[x]++;
        x+=(x&(-x));
    }
}
int cal(int x)
{
    int ans=0;
    while(x>0)
    {
        ans+=bit[x];
        x-=(x&(-x));
    }
   return ans;
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
        for(int i=0;i<=n+3;i++){bit[i]=0;vis[i]=0;}
        ll ans=0;
        bool rr=false;
        for(int i=0;i<n;i++)
        {
            int x;
            cin>>x;
            if(vis[x])rr=true;
            vis[x]=true;
            ans+=i-cal(x);
            add(x);
        }
        if(rr){cout<<"YES"<<endl;continue;}
       if(ans%2)cout<<"NO"<<endl;
       else cout<<"YES"<<endl;
    }
    return 0;
}