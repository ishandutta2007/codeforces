#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int>g[2];
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
        g[0].clear();
        g[1].clear();
        for(int i=0;i<n;i++)
        {
            int x;
            cin>>x;
            g[(x%2)].push_back(x);
        }
      bool ans=true;
      for(int i=1;i<g[0].size();i++)if(g[0][i]<g[0][i-1])ans=false;
      for(int i=1;i<g[1].size();i++)if(g[1][i]<g[1][i-1])ans=false;
    if(ans)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    }
    return 0;
}