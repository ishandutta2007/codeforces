#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll a[(1<<18)+30];
ll n,x;
multiset<ll>st;
bool bl=false;
int main()
{
    ios::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        if(bl)a[i]=x;else a[i]=0;
        if(x==-1)bl=true;
    }

    ll u=n,ans=a[n];
    while(u>1)
    {
        ll v=u/2;
        for(int i=v;i<u;i++)st.insert(a[i]);
        ans+=(*st.begin());
        st.erase(st.begin());
        u=v;
    }
    cout<<ans;
    return 0;
}