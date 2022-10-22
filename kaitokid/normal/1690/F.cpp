#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,p[209];
bool vis[209];
int go(string x)
{
    int r=x.size();
    for(int k=1;k<=r;k++)
    {
        bool bl=true;
        for(int i=0;i<r;i++)if(x[i]!=x[(i+k)%r]){bl=false;break;}
        if(bl)return k;
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
        string s;
        cin>>n>>s;
        for(int i=1;i<=n;i++){cin>>p[i];vis[i]=false;}
        ll ans=0;
        for(int i=1;i<=n;i++)
        {
            if(vis[i])continue;
            string u="";
            int h=i;
            while(!vis[h]){u+=s[h-1];vis[h]=true;h=p[h];}
            ll g=go(u);
            if(ans==0)ans=g;
            else ans=(ans*1LL*g)/__gcd(ans,g);

        }
        cout<<ans<<endl;

    }
    return 0;
}