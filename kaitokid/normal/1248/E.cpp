#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
set<pair<ll,ll> > st;
priority_queue <pair<ll,ll> ,vector<pair<ll,ll> >,greater <pair<ll,ll> > > pr;
deque<pair<ll,ll> >dq;
ll ans[100009];
ll n,p,x;
int main()
{
    ios::sync_with_stdio(0);
    cin>>n>>p;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        pr.push(make_pair(x,i));

    }
    ll t=0;
while(!pr.empty())
{
    ll d=pr.top().first;

        while(!dq.empty()&&max(dq.front().first+p,p+t)<=d)
        {
            t=max(dq.front().first+p,p+t);
            ans[dq.front().second]=t;

            dq.pop_front();
           while(!pr.empty()&&pr.top().first<=t){ st.insert(make_pair(pr.top().second,pr.top().first));
    pr.pop();}

        while(!st.empty()&&(dq.empty()||dq.back().second>(*st.begin()).first))
            {dq.push_back(make_pair((*st.begin()).second,(*st.begin()).first));st.erase(st.begin());}

        }
while(!pr.empty()&&pr.top().first<=d){ st.insert(make_pair(pr.top().second,pr.top().first));
    pr.pop();}

        while(!st.empty()&&(dq.empty()||dq.back().second>(*st.begin()).first))
            {dq.push_back(make_pair((*st.begin()).second,(*st.begin()).first));st.erase(st.begin());}



}
while(!dq.empty())
    {
        while(!dq.empty())
        {
            t=max(dq.front().first+p,p+t);
            ans[dq.front().second]=t;
            dq.pop_front();
        }

        while(!st.empty()&&(dq.empty()||dq.back().second>(*st.begin()).first)){dq.push_back(make_pair((*st.begin()).second,(*st.begin()).first));st.erase(st.begin());}

    }
    for(int i=0;i<n;i++)cout<<ans[i]<<" ";
    return 0;
}