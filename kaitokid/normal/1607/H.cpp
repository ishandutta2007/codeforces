#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
ll r[200009],cur[200009];
ll u[200009],v[200009];
vector<int> g[2000009];
set<int>st;
bool bl(int x,int y)
{
    return cur[x]+r[x]<cur[y]+r[y];
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
        ll ans=0;
        for(int i=0;i<n;i++)
        {
            ll x,y;
            cin>>x>>y>>m;
            ll p=min(x,m);
            x-=p;
            y-=(m-p);
            u[i]=p;
            v[i]=m-p;
            r[i]=min(p,y);
            cur[i]=x;
            g[x+y].push_back(i);
            st.insert(x+y);
        }
        for(set<int>::iterator it=st.begin();it!=st.end();it++)
        {
            ans++;
            int k=(*it);
            sort(g[k].begin(),g[k].end(),bl);
            int hh=g[k][0];
            u[hh]-=r[hh];
            v[hh]+=r[hh];
            ll lst=cur[hh]+r[hh];
            for(int i=1;i<g[k].size();i++)
            {
                int hh=g[k][i];
                if(cur[hh]>lst){ans++;
                u[hh]-=r[hh];
                v[hh]+=r[hh];
                lst=cur[hh]+r[hh];
                continue;
                }

             int ff=lst-cur[hh];
             u[hh]-=ff;
             v[hh]+=ff;
            }
           g[k].clear();
        }
        st.clear();

      cout<<ans<<endl;
      for(int i=0;i<n;i++)cout<<u[i]<<" "<<v[i]<<endl;
    }
    return 0;
}