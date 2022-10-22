#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod=1e9+7;
ll p[200009];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	p[0]=1;
	for(int i=1;i<=200002;i++)p[i]=(2*p[i-1])%mod;
int t;
cin>>t;
while(t--)
{

int n,m;
cin>>n>>m;
ll s=0;
for(int i=0;i<m;i++)
{
    ll l,r,x;
    cin>>l>>r>>x;
    s|=x;
}
ll ans=0;
for(ll i=0;i<40;i++)
    if(s&(1LL<<i)){ll d=(1<<i);ans+=p[n-1]*d;ans%=mod;}
cout<<ans<<endl;


}
	return 0;
}