#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        vector<int>a,b;
        for(int i=0;i<n;i++)
        {
            int x;
            cin>>x;
            if(x>=0)a.push_back(x);
            else b.push_back(-x);
        }
       sort(a.begin(),a.end());
       sort(b.begin(),b.end());
       reverse(a.begin(),a.end());
       reverse(b.begin(),b.end());
       vector<ll>g;
       for(int i=0;i<a.size();i++)
           if(i%k==0 )g.push_back(a[i]);
       for(int i=0;i<b.size();i++)
           if(i%k==0 )g.push_back(b[i]);
      ll ans=0;
      sort(g.begin(),g.end());
      for(int i=0;i+1<g.size();i++)
            ans+=2*g[i];
      int u=g.size();
      ans+=g[u-1];
      cout<<ans<<endl;

    }
    return 0;
}