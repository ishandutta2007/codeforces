#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
stack<pair<ll,ll> >st;
ll n,m[500009],an1[500009],an2[500009];
int main()
{
    ios::sync_with_stdio(0);
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>m[i];
    ll ans=0;
    for(int i=0;i<n;i++)
    {ll u=1;
        while(!st.empty()&&st.top().first>=m[i]){u+=st.top().second;ans-=st.top().first*st.top().second;st.pop();}
        ans+=u*m[i];
        st.push({m[i],u});
        an1[i]=ans;
    }
    while(!st.empty())st.pop();
    ans=0;
    for(int i=n-1;i>=0;i--)
    {ll u=1;
        while(!st.empty()&&st.top().first>=m[i]){u+=st.top().second;ans-=st.top().first*st.top().second;st.pop();}
        ans+=u*m[i];
        st.push({m[i],u});
        an2[i]=ans;
    }
    ans=0;
    ll q=0;
    for(int i=0;i<n;i++)if(ans<an1[i]+an2[i]-m[i]){q=i;ans=an1[i]+an2[i]-m[i];}
    for(int i=q-1;i>=0;i--)m[i]=min(m[i],m[i+1]);
    for(int i=q+1;i<n;i++)m[i]=min(m[i],m[i-1]);
    for(int i=0;i<n;i++)cout<<m[i]<<" ";
    return 0;
}