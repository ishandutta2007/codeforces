#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll s,x,dif,f[66],a[5],ans;

int main()
{
    ios::sync_with_stdio(0);
cin>>x>>s;
if(x>s){cout<<-1;return 0;}
if((s-x)%2){cout<<-1;return 0;}
s-=x;
s/=2;
ll g=1;
for(ll i=0;i<63;i++)
    {if(x&(g<<i))f[i]++;
    if(s&(g<<i))f[i]+=2;
    ans=max(ans,f[i]);
    for(int j=0;j<f[i];j++)a[j]|=(g<<i);
    }
    cout<<ans<<endl;
    for(int i=0;i<ans;i++)cout<<a[i]<<" ";

    return 0;
}