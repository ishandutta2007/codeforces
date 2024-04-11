#include <bits/stdc++.h>
using namespace std;
#define erorp(x) cout<<#x<<"={"<<(x.F)<<" , "<<x.S<<"}"<<endl;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define is_bit(x,y) (x%(1<<(y+1))>=(1<<y))
#define eror(x) cout<<#x<<'='<<(x)<<endl;
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define Add(x,y) x=(x+y)%mod
#define f(i,a,b) for(int i=a;i<b;i++)
#define get(x) scanf("%I64d",&x);
#define gett(x) scanf("%d",&x);
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int N=2e5+99,mod=1e9+7;

int n,mv,sum,ans,e,l[N],r[N];

ll pow(ll x,ll y,ll mod){return(!y?1:pow(x*x%mod,y/2,mod)*(y&1?x:1))%mod;}

int E(int x){
	int res,t=min(r[x],r[x-1])-max(l[x],l[x-1])+1,
	t1=r[x]-l[x]+1,t2=r[x-1]-l[x-1]+1;
	maxm(t,0);
	res=1ll*t*pow(t1,mod-2,mod)%mod*pow(t2,mod-2,mod)%mod;
	res=(mod+1-res)%mod;
	return res;
}
int E2(int x){
	int l0=r[x-1]-l[x-1]+1,l1=r[x]-l[x]+1,l2=r[x+1]-l[x+1]+1;
	int res,t0,t3=min(min(r[x-1],r[x]),r[x+1])-max(max(l[x-1],l[x]),l[x+1])+1,
	t1=min(r[x-1],r[x])-max(l[x-1],l[x])+1,t2=min(r[x],r[x+1])-max(l[x],l[x+1])+1;
	maxm(t1,0);
	maxm(t2,0);
	maxm(t3,0)
	t2-=t3,t1-=t3;
	t0=r[x]-l[x]+1-t1-t2-t3;
	res=1ll*t0*l0%mod*l2%mod;
	Add(res,1ll*t1*(l0-1)%mod*l2%mod);
	Add(res,1ll*t2*l0%mod*(l2-1)%mod);
	Add(res,1ll*t3*(l0-1)%mod*(l2-1)%mod);
	res=1ll*res*pow(l0,mod-2,mod)%mod*pow(l1,mod-2,mod)%mod*pow(l2,mod-2,mod)%mod;
	return res;
}
int main(){
	ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);	
	cin>>n;
	f(i,1,n+1)
		cin>>l[i];
	f(i,1,n+1)
		cin>>r[i];
	f(i,1,n+1){
		Add(mv,E(i));
		if(i<n){
			Add(ans,E2(i));
		}
		if(i>2){
			Add(sum,E(i-2));
			Add(ans,1ll*sum*E(i)%mod);
		}
	}
	cout<<(2ll*ans%mod+mv)%mod;
}