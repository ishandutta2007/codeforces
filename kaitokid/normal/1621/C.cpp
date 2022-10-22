#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool vis[100009];
int ans[100009];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i=1;i<=n;i++)vis[i]=0;
        int g=0;
        for(int i=1;i<=n;i++)
        {
            if(vis[i])continue;
            vector<int>v;
            g++;
            cout<<"? "<<i<<endl;
            fflush(stdout);
            int x;
            cin>>x;
            while(!vis[x])
            {
                vis[x]=true;
                v.push_back(x);
                 g++;
                 cout<<"? "<<i<<endl;
                fflush(stdout);
                cin>>x;
            }
            int d=v.size();
            for(int j=0;j<d;j++){ans[v[j]]=v[((j+1)%d)];}


        }
       cout<<"! ";
       for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
       cout<<endl;
       fflush(stdout);

    }
    return 0;
}