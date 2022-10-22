#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define is_bit(x,y) (x%(1<<(y+1))>=(1<<y))
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(int i=a;i<b;i++)
#define get(x) scanf("%I64d",&x);
#define gett(x) scanf("%d",&x);																																														
#define ops(x) cout<<x<<" !"<<endl;
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define Add(x,y) x=(x+y)%mod;
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first
 
const int N=5e5+99,Max=1e7+200,mod=1e9+7;
 
int n,bad,ans,a[N],Pow[N],d[Max],cnt[Max];
vector<int> p,comp[N];
 
//math
int fac[N],ifac[N];
ll pow(ll x,ll y,ll mod){if(y==0) return 1; ll p=pow(x,y/2,mod);return ((p*p%mod)*(1+(y%2)*(x-1)))%mod;}
void make_fac(){fac[0]=1; f(i,1,N) fac[i]=1ll*fac[i-1]*i%mod; ifac[N-1]=pow(fac[N-1],mod-2,mod);f_(i,N-2,0) ifac[i]=1ll*ifac[i+1]*(i+1ll)%mod;}
int C(int k,int n){if(k>n) return 0; return 1ll*fac[n]*ifac[n-k]%mod*ifac[k]%mod;}
 
void make_p(){
	Pow[0]=1;
	f(i,1,N) Pow[i]=2ll*Pow[i-1]%mod;
	f(i,2,sqrt(Max)){
		bool b=1;
		f(j,2,i)
			if(i%j==0)
				b=0;
		if(b) p.pb(i);
	}
}
void find_comp(int an,int x){
	for(int i=0;p[i]*p[i]<=x;i++)
		if(x%p[i]==0){
			comp[an].pb(p[i]);
			while(x%p[i]==0)
				x/=p[i];
		}
	if(x>1) comp[an].pb(x);
	f(mask,0,(1<<comp[an].size())){
		int product=1,c=0;
		f(i,0,comp[an].size())
			if(is_bit(mask,i))
				product*=comp[an][i],c^=1;
		d[product]=c,cnt[product]++;
	}
}
void mv(){
	ans=1ll*Pow[n-1]*n%mod;
	f(i,2,n+1)
		Add(bad,1ll*C(i,n)*i%mod);
	f(i,2,Max)
		if(cnt[i]){
			if(d[i]){
				Add(ans,mod-(1ll*cnt[i]*Pow[cnt[i]-1]%mod));
				f(j,1,cnt[i]+1)
					Add(bad,mod-(1ll*C(j,cnt[i])*(n-j)%mod));
			}
			else{
				Add(ans,1ll*cnt[i]*Pow[cnt[i]-1]%mod);
				f(j,1,cnt[i]+1)
					Add(bad,1ll*C(j,cnt[i])*(n-j)%mod);
			}
		}
	Add(ans,mod-bad);
	cout<<ans;
}
 
int main(){
	make_p();
	make_fac();
	cin>>n;
	f(i,0,n){
		gett(a[i]);
		find_comp(i,a[i]);
	}
	mv();
}