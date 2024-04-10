#include<bits/stdc++.h>
#define fo(i,a,b)for(int i=a,_e=b;i<=_e;++i)
#define fd(i,a,b)for(int i=b,_e=a;i>=_e;--i)
#define ll long long
#define pb push_back
#define P pair<int,int>
#define fi first
#define se second
#define NO return printf("No"),0
using namespace std;
const int N=1e5+5,mo=1e9+7;
int t;
ll n,k,las,las2;
unordered_map<ll,ll>f,la;
inline ll _(ll l,ll r){
	return (l+r)*(r-l+1)/2;
}
ll F(ll n,ll &las){
	if(n<=k){
		las=k*(k+1)/2;
		return 0;
	}
	if(f.count(n)){
		las=la[n];
		return f[n];
	}
	ll s=n/k,ans,y,su,las2;
	ll a=F(s,las),d;
	//ll b=F(s-1,las2);
	if(las==s){
		d=(s-a)/k;
		y=(s-a)%k;
		ans=d;
		su=_(s-y,s-1)+_(s+1,s+k-y);
		if(su<=n)++ans;
	}else{
		d=(s-a)/k;
		y=(s-a)%k;
		if(!y)--d;
		y=y?y:k;
		ans=d;
		su=_(s-y+1,s+k-y);
		if(las<s&&s-y<las)su-=las-(s-y);
		if(las>s&&las<=s+k-y)su-=las-(s+k-y+1);
		if(su<=n)++ans;
	}
	las=su;
	la[n]=las;
	return f[n]=ans;
}
int main(){
	ios::sync_with_stdio(false);
	cin>>t;
	for(;t--;){
		cin>>n>>k;
		if(n==1){
			printf("1\n");
			continue;
		}
		ll a=F(n,las);//,b=F(n-1,las2);
		f.clear();
		la.clear();
		if(las==n)printf("%lld\n",a*(k+1));
		else{
			ll d=(n-a)/k-((n-a)%k==0);
			ll y=(n-a)%k;
			printf("%lld\n",d*(k+1)+(y?y:k));
		}
	}
}