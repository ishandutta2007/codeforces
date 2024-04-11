#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(ll i=a;i<b;i++)
#define get(x) scanf("%I64d",&x);
#define gett(x) scanf("%d",&x);																																														
#define ops(x) cout<<x<<" !"<<endl;
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const ll N=2e5+9,d[4]={0,2,3,1};
ll t,n,a[3],b[4],se=3,yek=1,chr=4;
ll Xor(ll x,ll y){
	ll res=0;
	for(ll i=0;x || y;i++,x/=2,y/=2)
		res+=1ll*(1ll<<i)*(1ll*(x%2!=y%2));
	return res;
}
ll get_ans(ll l,ll r,ll x){
	if(l==r) return l;
	ll p=(r-l+1ll)/chr;
	f(i,1,5){
		if(x<=i*p)
			return get_ans(l+d[i-1]*p,l+d[i-1]*p+p-1ll,x-p*(i-1));
	}
}
void solve(ll x){
	ll sum=0,l,r;
	for(ll i=0;;i+=2){
		sum+=(1ll<<i);
		if(sum>=x){
			sum-=(1ll<<i),l=(1ll<<i)*2ll;
			break;
		}
	}
	r=l+(l/2ll)-1;
	a[0]=x-sum+(l/2ll)-1;
	a[1]=get_ans(l,r,x-sum);
	a[2]=Xor(a[0],a[1]);
}
int main(){
	cin>>t;
	while(t--){
		get(n);
		solve((n-1)/se+yek);
		cout<<a[(n-1)%3]<<endl;
	}
}