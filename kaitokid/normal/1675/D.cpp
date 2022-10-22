#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,pr[200009];
bool nt[200009],vis[200009];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=1;i<=n;i++)nt[i]=vis[i]=0;
        for(int i=1;i<=n;i++)
        {
            cin>>pr[i];
            if(i!=pr[i])nt[pr[i]]=true;
        }
        int m=0;
        for(int i=1;i<=n;i++)if(!nt[i])m++;
        cout<<m<<endl;
        for(int i=1;i<=n;i++)
        {
            if(nt[i])continue;
            vector<int>g;
            int u=i;
            while(!vis[u])
            {
                g.push_back(u);
                vis[u]=true;
                if(pr[u]==u)break;
                u=pr[u];
            }
            int r=g.size();
            cout<<g.size()<<endl;
            for(int j=r-1;j>=0;j--)cout<<g[j]<<" ";
            cout<<endl;

        }
    }

    return 0;

}