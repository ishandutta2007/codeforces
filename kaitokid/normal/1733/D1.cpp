#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,x,y;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
      string a,b;
      cin>>n>>x>>y>>a>>b;
      vector<int>g;
      for(int i=0;i<n;i++)
            if(a[i]!=b[i])g.push_back(i);
      int u=g.size();
      if(u%2)
      {
          cout<<-1<<endl;
          continue;
      }
      if((u==2) && (g[1]==(g[0]+1)))
      {
          ll res=min(x,2*y);
         cout<<res<<endl;
        continue;
      }
      y*=(u/2);
      cout<<y<<endl;
    }
    return 0;
}