#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll n,k,ans[200009];
deque<pair<ll,ll> >dq,dq2;
string s;
void go(ll a,ll b)
{
    while(!dq.empty()&&dq.back().first>=a)dq.pop_back();
    dq.push_back(make_pair(a,b));
}
int main()
{
ios::sync_with_stdio(0);
cin>>n>>k>>s;
dq2.push_back(make_pair(0,k+1));
for(int i=1;i<=n;i++)
{
    while(dq2.front().second<i)dq2.pop_front();
    if(s[i-1]=='1'){go(dq2.front().first+i,i+k);}
    while(!dq.empty()&&dq.front().second<i)dq.pop_front();
    ans[i]=ans[i-1]+i;
    if(!dq.empty())ans[i]=min(ans[i],dq.front().first);
while(!dq2.empty()&&dq2.back().first>=ans[i])dq2.pop_back();
dq2.push_back(make_pair(ans[i],i+k+1));
//cout<<ans[i]<<endl;
}

cout<<ans[n];
    return 0;
}