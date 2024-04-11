#include <bits/stdc++.h>
using namespace std;
#define dbgv(v) cout<<#v<<" = "; f(i,0,v.size()) cout<<v[i]<<" "; cout<<endl
#define dbga(a,x,y) cout<<#a<<" = "; f(i,x,y) cout<<a[i]<<" "; cout<<endl
#define erorp(x) cout<<#x<<"={"<<(x.F)<<" , "<<x.S<<"}"<<endl
#define eror(x) cout<<#x<<'='<<(x)<<endl
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define f(i,a,b) for(int i=a;i<b;i++)
#define nb(x) __builtin_popcount(x)
#define all(v) v.begin(),v.end()
#define Add(x,y) x=(x+y)%mod
#define maxm(a,b) a=max(a,b)
#define minm(a,b) a=min(a,b)
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first
#define int ll

const int N=2e5+99,mod=998244353,lg=30;
 
int n,d,Pow[N],a[N],Bit[N];
 
int count(int l,int r){
	return lower_bound(a,a+n,r)-lower_bound(a,a+n,l);
}
int calc(int l,int r,int h){
	int s=l^((d>>h)<<h),t=s+r-l,e=(s+t)/2,mid=(l+r)/2,res=0,clr=count(l,r),cst=count(s,t);
	if(l+1==r || min(clr,cst)==0){
		return Pow[clr+cst*(l!=s)];
	}
	if(l==s){
		if(Bit[h-1]){
			res=calc(l,mid,h-1);
		}
		else{
			res=(calc(l,mid,h-1)+calc(mid,r,h-1)-1)%mod;
		}
	}
	else{
		if(Bit[h-1]){
			res=1ll*calc(l,mid,h-1)*calc(mid,r,h-1)%mod;
		}
		else{
			res=(calc(l,mid,h-1)+calc(mid,r,h-1)-1)%mod;
			Add(res,1ll*(Pow[count(s,e)]-1)*(Pow[count(e,t)]-1)+1ll*(Pow[count(l,mid)]-1)*(Pow[count(mid,r)]-1));
		}
	}
	return res;
}
 
main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	Pow[0]=1; f(i,1,N) Pow[i]=2ll*Pow[i-1]%mod;
	cin>>n>>d;
	f(i,0,n) cin>>a[i];
	f(i,0,lg) Bit[i]=((d&(1<<i))>0);
	sort(a,a+n);
	cout<<(calc(0,(1<<lg),lg)+mod-1)%mod;
}