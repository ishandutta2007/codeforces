#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll p[35];
vector<ll> ans;
int main()
{
    ios::sync_with_stdio(0);
    int t;
ll u=1,v=1;
ans.push_back(1);
while(v<=1e18)
{
    u=u*2+1;

    v+=u*(u+1)/2;
    ans.push_back(v);
    //cout<<v<<endl;
}

    cin>>t;
    while(t--)
    {
   ll n;
   cin>>n;
 ll res=upper_bound(ans.begin(),ans.end(),n)-ans.begin();
 cout<<res<<endl;
    }
    return 0;
}