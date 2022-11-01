#include<bits/stdc++.h>
#define fo(i,a,b)for(int i=a,_e=b;i<=_e;++i)
#define fd(i,a,b)for(int i=b,_e=a;i>=_e;--i)
#define ll long long
#define P pair<int,int>
#define fi first
#define se second
#define pb push_back
using namespace std;
const int N=1e5+5;
int n;
ll k,ans;
ll a[N],b[N];
ll sum,sum2;
ll ck(ll mid){
	static ll cnt;
	cnt=0;
	fo(i,1,n){
		ll c=mid-a[i]+1;
		if(c>0)b[i]=0;else{
			ll x=(sqrtl(-(long double)c/3*4+1)-1.)/2.;
			for(;x*x*3+x*3+c<=0;)++x;
			for(;x*x*3+x*3+c>0;)--x;
			b[i]=x+1;
		}
		b[i]=min(b[i],a[i]);
		cnt+=b[i];
	}
	return cnt;
}
int main(){
	ios::sync_with_stdio(0);
	cin>>n>>k;
	fo(i,1,n)cin>>a[i];
	for(ll l=-3e18,r=1e9,mid;mid=l+r>>1,l<=r;)
		if(ck(mid)>=k)ans=mid,l=mid+1;else r=mid-1;
	ll cnt=ck(ans);
	fo(i,1,n)if(cnt>k&&b[i]>0){
		ll x=b[i]-1;
		if(x*x*3+x*3+ans-a[i]+1==0)--b[i],--cnt;
	}
//	fo(i,1,n)sum+=(ll)b[i]*(-(ll)b[i]*b[i]+a[i]),sum2+=b[i];
//	cerr<<sum<<endl;
//	cerr<<sum2<<endl;
	fo(i,1,n)printf("%d ",b[i]);
}