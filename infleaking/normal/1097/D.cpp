#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
typedef long long ll;
const ll mo=1e9+7;
ll n,k,t;
ll d[100][2];
ll s[100][100];
ll ans,s1,inv[100];
ll power(ll a,ll b){
	ll ans=1;
	while (b){
		if (b&1)ans=ans*a%mo;
		a=a*a%mo;
		b>>=1;
	}return ans;
}
void dfs(ll x,ll p,ll ax){
	if (x>t){
		ans=(ans+p%mo*ax)%mo;
		s1=(s1+ax)%mo;
		return;
	}
	for (ll i=0;i<=d[x][1];i++){
		dfs(x+1,p,ax*s[x][i]%mo);
		p=p*d[x][0];
	}
}
int main(){
//	freopen("a.in","r",stdin);
	cin>>n>>k;
	for (ll i=1;i<=100;i++)inv[i]=power(i,mo-2);
	for (ll i=2;i*i<=n;i++){
		if (n%i==0){
			d[++t][0]=i;
			while (n%i==0){
				n=n/i;
				d[t][1]++;
			}
		}
	}
	if (n>1){
		d[++t][0]=n;
		d[t][1]=1;
	}
	for (ll i=1;i<=t;i++){
		s[i][d[i][1]]=1;
		for (ll u=1;u<=k;u++)
		for (ll j=0;j<=d[i][1];j++){
			ll sx=s[i][j]*inv[j+1]%mo;s[i][j]=0;
			for (ll k=0;k<=j;k++)s[i][k]=(s[i][k]+sx)%mo;
		}
	}
	dfs(1,1,1);
	int ans1=ans;
	printf("%d\n",ans1);
}