#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod=998244353;
int a[100009];
ll fr[100009];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        for(int i=0;i<n;i++)cin>>a[i];
        vector<pair<ll,ll> >r;
        r.push_back({a[n-1],1});
        ll ans=0;
        for(int i=n-2;i>=0;i--)
        {
            vector<ll>u;
            for(int j=0;j<r.size();j++)
            {
                ll p=r[j].first,q=r[j].second;
                ll d=(a[i]+p-1)/p;
                ans+=(((((d-1)*q)%mod)*(i+1))%mod);
                ans%=mod;
                fr[a[i]/d]+=q;
                fr[a[i]/d]%=mod;
                u.push_back(a[i]/d);

            }
           fr[a[i]]++;
           u.push_back(a[i]);
           r.clear();
           for(int j=0;j<u.size();j++)
           {
               if(fr[u[j]]==0)continue;
               r.push_back({u[j],fr[u[j]]});
               fr[u[j]]=0;
           }

        }
       cout<<ans<<endl;

    }

    return 0;
}