#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
ll a[200009];
ll mx[200009];
ll pr[200009];
ll ans[200009];
ll x[200009];
vector<int>qq[200009];
ll suf[200009];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

        int n;
        cin>>n;
        for(int i=1;i<=n;i++)
         {cin>>a[i];a[i]=max(i-a[i]+1,1LL);}
        for(int i=1;i<=n;i++)
        {
            mx[i]=max(mx[i-1],1LL*a[i]);
            pr[i]=pr[i-1]+mx[i];
        }


        int q;
        cin>>q;
        for(int i=1;i<=q;i++)
        {
            int p;
            cin>>p>>x[i];
            x[i]=max(1LL,p-x[i]+1);
            qq[p].push_back(i);

        }

        set<pair<ll,ll> >st;
        st.insert({INT_MAX,n+1});
        for(int i=n;i>=1;i--)
        {


            for(int j=0;j<qq[i].size();j++)
            {
                ll u=qq[i][j];
                ll g=max(mx[i-1],x[u]);
                set<pair<ll,ll> >::iterator it=st.lower_bound({g,0});
                ans[u]=pr[i-1]+suf[(*it).second]+((*it).second-i)*1LL*g;
            }
            while(!st.empty() && (*st.begin()).first<a[i])st.erase(st.begin());
            suf[i]=suf[(*st.begin()).second]+((*st.begin()).second-i)*1LL*a[i];
            st.insert({a[i],i});
        }
        for(int i=1;i<=q;i++)
        {
            ll res=n*1LL*(n+1)/2;
            res+=n;
            res-=ans[i];
            cout<<res<<endl;
        }

    return 0;

}