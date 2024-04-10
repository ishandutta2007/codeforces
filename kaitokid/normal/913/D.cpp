#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll n,t,k;
pair<ll,pair<ll,ll> >r[200009];
bool ch(ll k)
{
    if(k==0)return true;
    ll tm=t,res=0;
    for(int i=0;i<n;i++)
    {
        if(r[i].first>tm)return false;
        if(r[i].second.first<k)continue;
        res++;
        tm-=r[i].first;
        if(res==k)return true;


    }

  return false;
}

int main()
{
    ios::sync_with_stdio(0);
    cin>>n>>t;
    for(int i=0;i<n;i++)
    {
        cin>>r[i].second.first>>r[i].first;

        r[i].second.second =i+1;
    }
    sort(r,r+n);
    ll fr=0,en=n;
    while(en!=fr)
    {
    ll mid=(fr+en+1)/2;
    if(ch(mid))fr=mid;
    else en=mid-1;


    }
    cout<<fr<<endl<<fr<<endl;
    ll res=0;
    for(int i=0;i<n;i++)
    {
         if(res==fr)return 0;
        if(r[i].second.first<fr)continue;
        res++;
        cout<<r[i].second.second<<" ";


    }
    return 0;
}