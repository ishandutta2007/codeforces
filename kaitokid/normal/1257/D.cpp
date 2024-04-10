#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll t,n,m,a[200009],dd[200009];
//set<pair<int,int> >st;
//map<int,int> mp;
int main()
{
    ios::sync_with_stdio(0);
    cin>>t;
    while(t--)
    {
    cin>>n;
    ll mx1=0,mx2=0;
    for(int i=1;i<=n;i++)
        {cin>>a[i];mx1=max(mx1,a[i]);dd[i]=0;}
        cin>>m;
        for(int i=0;i<m;i++)
        {ll x,y;
        cin>>x>>y;
        mx2=max(mx2,x);
        //st.insert(make_pair(x,y));
  dd[y]=max(x,dd[y]);
        }
    if(mx1>mx2){cout<<-1<<endl;continue;}
    for(int i=n-1;i>0;i--)dd[i]=max(dd[i],dd[i+1]);
    ll ans=1,now=0,lo=0;
    for(int i=1;i<=n;i++)
    {
        now=max(now,a[i]);
        lo++;
        //set<pair<int,int> >:: iterator it=st.lower_bound(make_pair(now,lo));
        if(dd[lo]<now){ans++;lo=1;now=a[i];}
    }
    cout<<ans<<endl;
    }
    return 0;
}