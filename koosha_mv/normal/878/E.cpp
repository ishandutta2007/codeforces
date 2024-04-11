#include <bits/stdc++.h>
using namespace std;
#define erorp(x) cout<<#x<<"={"<<(x.F)<<" , "<<x.S<<"}"<<endl
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl
#define eror(x) cout<<#x<<'='<<(x)<<endl
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define f(i,a,b) for(int i=a;i<b;i++)
#define nb(x) __builtin_popcount(x)
#define maxm(a,b) a=max(a,b)
#define minm(a,b) a=min(a,b)
#define Add(x,y) x=(x+y)%mod
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first
#define int ll
 
const int N=1e5+99,inf=2e9,mod=1e9+7,lg=17,lgm=32;
 
int n,q,a[N],sum[N];
pair<int,int> par[lg][N];
 
ll pow(ll x,ll y,ll mod){return(!y?1:pow(x*x%mod,y/2,mod)*(y&1?x:1))%mod;}
 
int Get(int l,int r){
	int res=(sum[l]-sum[r+1]+mod)%mod;
	res=1ll*res*pow(mod/2+1,l,mod)%mod;
	return res;
}
 
void find(){
	f(i,1,n+1){
		int x=i,res=0;
		while(1){
			if(i!=x && (res>=inf)){
				break;
			}
			res=2ll*res+a[x];
			if(res<=0 || x==1){
				par[0][i].F=x-1;
				break;
			}
			x--;
		}
		par[0][i].S=Get(par[0][i].F+1,i);
		f(j,1,lg){
			par[j][i].F=par[j-1][par[j-1][i].F].F;
			par[j][i].S=(par[j-1][i].S+par[j-1][par[j-1][i].F].S)%mod;
		}
	}	
}
 
main(){
	cin>>n>>q;
	f(i,1,n+1){
		cin>>a[i];
	}
	int Pow=1;
	f(i,1,n+1){
		Pow=2ll*Pow%mod;
		int res=abs(a[i])*Pow%mod;
		if(a[i]<0) res=mod-res;
		sum[i]=res;
	}
	f_(i,n,1){
		Add(sum[i],sum[i+1]);
	}
	find();
	f(T,0,q){
		int l, r, res=0, ans=0;
		cin >> l >> r;
		l++;
		f_(i,lg-1,0){
			if(par[i][r].F>=l){
				Add(ans,par[i][r].S);
				r=par[i][r].F;
			}
		}
		Add(ans,Get(l,r));
		cout<<(2ll*ans+a[l-1]+mod)%mod<<'\n';
	}
}