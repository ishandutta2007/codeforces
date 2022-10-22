#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll n;
string s;
vector <ll>v1,v2;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>s;
    if(n==1){cout<<0;return 0;}
    for(ll i=0;i<n;i++)
    {
        if(s[i]=='A')v1.push_back(i);
        else v2.push_back(i);
    }
    ll ans=n*(n-1)/2;
    ll u=0;
   if(!v1.empty()) for(int i=0;i<v1.size()-1;i++)ans-=max((v1[i+1]-v1[i]-1)*2-1,u);
    if(!v1.empty()){ans-=n-1-v1[v1.size()-1];ans-=max(u,v1[0]-1);}
    if(!v2.empty())
    for(int i=0;i<v2.size()-1;i++)ans-=max(u,(v2[i+1]-v2[i]-1)*2-1);

    if(!v2.empty()){ans-=n-1-v2[v2.size()-1];ans-=max(u,v2[0]-1);}
cout<<ans;
    return 0;
}