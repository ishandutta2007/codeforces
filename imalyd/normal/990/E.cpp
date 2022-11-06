#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define debug(x) cout<<(#x)<<"="<<(x)<<" "
#define enter cout<<endl
const ll N=1000005,inf=1ll<<60;
ll n,m,k,f[N],a[N],ans=inf,l=1,cnt=1;
ll rd(){
	ll a=0;
	char ch=getchar();
	while(!isdigit(ch))ch=getchar();
	while(isdigit(ch))a=(a<<1)+(a<<3)+(ch^48),ch=getchar();
	return a;
}
ll check(ll x){
	for(ll i=0,tot=1;;i=f[i+x],++tot){//debug(i),enter;
		if(n<=i+x)return tot*a[x];
		//if(i==j)return inf;
	}
}
int main(){//freopen("5.in","r",stdin);
	n=rd(),m=rd(),k=rd();
	while(m--)f[rd()]=1;
	if(f[0]){printf("-1");return 0;}
	for(ll i=0;i<n;i++){if(f[i])f[i]=f[i-1],l=max(l,++cnt);else f[i]=i,cnt=1;}//debug(l),enter;
	for(ll i=1;i<=k;i++)a[i]=rd();
	for(ll i=l;i<=k;i++)ans=min(ans,check(i));//,debug(li[i].n),debug(check(li[i].n)),enter;
	if(ans==inf)ans=-1;
	cout<<ans;
	return 0;
}