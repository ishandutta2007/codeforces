#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
vector<pair<ll,ll> >a;
ll n,ans[200009];
set<ll>st;
ll go(ll x,ll y)
{
    if(y>x)return y-x;
    return n-x+y;
}
int main()
{
   ios::sync_with_stdio(0);
    cin>>n;
    for(int i=0;i<n;i++)
    {
       ll x;
       cin>>x;
       a.push_back(make_pair(x,i));
    }
    sort(a.begin(),a.end());
    int i=0,j=0;
    while(i<n)
    {
        while(a[j].first<((a[i].first+1)/2)){st.insert(a[j].second);j++;}
        if(st.empty()){ans[a[i].second]=-1;i++;continue;}

        set<ll>::iterator it=st.begin();
         ans[a[i].second]=go(a[i].second,(*it));
       it=st.lower_bound(a[i].second);
        if(it!=st.end())
            ans[a[i].second]=min(ans[a[i].second],go(a[i].second,(*it)));
        i++;
    }
    for(int i=n-1;i>=0;i--)
    {
        if(ans[i]==-1&&ans[(i+1)%n]!=-1){ans[i]=ans[(i+1)%n]+1;continue;}
        if(ans[(i+1)%n]!=-1)ans[i]=min(ans[i],ans[(i+1)%n]+1);
    }
    for(int i=n-1;i>=0;i--)
    {
        if(ans[i]==-1&&ans[(i+1)%n]!=-1){ans[i]=ans[(i+1)%n]+1;continue;}
        if(ans[(i+1)%n]!=-1)ans[i]=min(ans[i],ans[(i+1)%n]+1);
    }
    for(int i=n-1;i>=0;i--)
    {
        if(ans[i]==-1&&ans[(i+1)%n]!=-1){ans[i]=ans[(i+1)%n]+1;continue;}
        if(ans[(i+1)%n]!=-1)ans[i]=min(ans[i],ans[(i+1)%n]+1);
    }
    for(int i=n-1;i>=0;i--)
    {
        if(ans[i]==-1&&ans[(i+1)%n]!=-1){ans[i]=ans[(i+1)%n]+1;continue;}
        if(ans[(i+1)%n]!=-1)ans[i]=min(ans[i],ans[(i+1)%n]+1);
    }
    for(int i=0;i<n;i++)cout<<ans[i]<<" ";
    return 0;
}