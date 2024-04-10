#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
int l[200009],r[200009],c[200009];
vector<int>add[500009],rm[500009];
int cl[500009],fr[200009],pr[500009],bf[500009],nx[500009];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=1;i<=n+2;i++)fr[i]=0;
        vector<int>hs;
        for(int i=0;i<n;i++)
        {
            cin>>l[i]>>r[i]>>c[i];
            hs.push_back(l[i]);
            hs.push_back(r[i]);
        }
        vector<int>h;
        sort(hs.begin(),hs.end());
        h.push_back(hs[0]);
        for(int i=1;i<hs.size();i++)if(hs[i]>hs[i-1])h.push_back(hs[i]);
        int g=h.size();
        for(int i=0;i<=g;i++){add[i].clear();rm[i].clear();}

        for(int i=0;i<n;i++)
        {
            l[i]=lower_bound(h.begin(),h.end(),l[i])-h.begin();
            r[i]=lower_bound(h.begin(),h.end(),r[i])-h.begin();
            add[l[i]].push_back(c[i]);
            rm[r[i]].push_back(c[i]);

        }
        set<int>dd;
        for(int i=0;i<g;i++)
        {
            pr[i]=0;
            if(i>0)pr[i]=pr[i-1];
            for(int j=0;j<add[i].size();j++)
            {
                if((++fr[add[i][j]])==1)dd.insert(add[i][j]);
            }
            if(dd.size()>1){cl[i]=n+1;pr[i]++;}
            else
                cl[i]=(*dd.begin());
            for(int j=0;j<rm[i].size();j++)
            {
                if((--fr[rm[i][j]])==0)dd.erase(rm[i][j]);
            }

        }
        bf[0]=-1;
        for(int i=1;i<g;i++)
            if(cl[i]!=cl[i-1])bf[i]=i-1;else bf[i]=bf[i-1];
        nx[g-1]=-1;
        for(int i=g-2;i>=0;i--)
            if(cl[i]!=cl[i+1])nx[i]=i+1;else nx[i]=nx[i+1];

        for(int i=0;i<n;i++)
        {
            int g=pr[r[i]];
            if(l[i]>0)g-=pr[l[i]-1];
            if(g>0){cout<<0<<" ";continue;}
            int ans=INT_MAX;
            int u=bf[l[i]];
            if(u!=-1)ans=min(ans,h[l[i]]-h[u]);
            u=nx[r[i]];
            if(u!=-1)ans=min(ans,h[u]-h[r[i]]);
            cout<<ans<<" ";
        }
    cout<<endl;
     }
    return 0;
}