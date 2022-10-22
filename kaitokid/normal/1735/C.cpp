#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[109];
bool vis[109];
bool g[27];
bool ch()
{
    memset(g,0,sizeof g);
    for(int i=0;i<26;i++)
    {
        if(g[i])continue;
        g[i]=true;
        int u=a[i],d=1;
        while((u!=-1) && (u!=i) &&(g[u]==0))
        {
            g[u]=true;
            d++;
            u=a[u];

        }
        if(u==i && d<26)return false;
    }
    return true;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
     int t;
     cin>>t;
    while(t--)
    {
        memset(a,-1,sizeof a);
        memset(vis,0,sizeof vis);
        int n;
        string s;
        cin>>n>>s;
        string ans="";
        for(int i=0;i<n;i++)
        {
            int u=s[i]-'a';
            if(a[u]!=-1){ans+=char('a'+a[u]);continue;}
            for(int j=0;j<26;j++)
            {
                if(vis[j])continue;
                a[u]=j;
                if(ch())break;
                a[u]=-1;
            }
            vis[a[u]]=true;
            ans+=char('a'+a[u]);
        }

        cout<<ans<<endl;
    }

    return 0;
}