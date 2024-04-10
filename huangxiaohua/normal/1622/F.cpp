#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll i,j,k,n,m,t,p[1005000],f[1005000],g[1005000],x,y,no[1005000],res;
map<ll,ll>mp;
void show(){
	cout<<res<<'\n';
	for(i=1;i<=n;i++)if(!no[i])cout<<i<<' ';
	exit(0);
}
#define chk() for(i=1;i<=n;i++){if(mp.count(g[i]^y)){res-=2;no[mp[g[i]^y]]=no[i]=1;show();}}
int main(){
	mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count()+1);
	uniform_int_distribution<ll>lim(1,1e18);
	ios::sync_with_stdio(0);
	for(i=1;i<=1000000;i++)f[i]=lim(rng);
	for(i=2;i<=1000000;i++)if(!p[i])for(j=i;j<=1000000;j+=i)p[j]=i;
	cin>>n;
	if(p[n]==n)n--;
	res=n;
	for(i=1;i<=n;i++){
		for(j=i;j-1;j/=p[j]){x^=f[p[j]];if((n+1-i)&1)y^=f[p[j]];}
		mp[x]=i;g[i]=x;
	}
	if(!y)show();
	if(mp.count(y)){res--;no[mp[y]]=1;show();}
	chk();y^=g[n];n--;res=n;chk();
}//