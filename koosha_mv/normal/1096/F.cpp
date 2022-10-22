#include <bits/stdc++.h>
using namespace std;
#define dbgv(v) cout<<#v<<" = "; f(i,0,v.size()) cout<<v[i]<<" "; cout<<endl
#define dbga(a,x,y) cout<<#a<<" = "; f(i,x,y) cout<<a[i]<<" "; cout<<endl
#define erorp(x) cout<<#x<<"={"<<x.F<<" , "<<x.S<<"}"<<endl
#define eror(x) cout<<#x<<'='<<(x)<<endl
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define f(i,a,b) for(int i=a;i<b;i++)
#define nb(x) __builtin_popcount(x)
#define all(v) v.begin(),v.end()
#define bit(n,k) (((n)>>(k))&1)
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

const int N=5e6+99,mod=998244353;

int n,t,cnt,ans,a[N],A[N],B[N],mark[N],fenwik[N];

ll pow(ll x,ll y,ll mod){return(!y?1:pow(x*x%mod,y/2,mod)*(y&1?x:1))%mod;}

void add(int x, int val){ for (x++;x>0;x-=x&-x) fenwik[x]+=val; }
int get(int x) { int res=0; for(x++;x<N;x+=x&-x) res+=fenwik[x]; return res; }

int32_t main(){
	ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>n;
	f(i,1,n+1) mark[i]=1;
	f(i,1,n+1){
		cin>>a[i];
		cnt+=(a[i]==-1);
		if(a[i]>0){
			mark[a[i]]=0;
			Add(ans,get(a[i]));
			add(a[i],1);
		}
	}
	f(i,1,n+1) A[i]=A[i-1]+mark[i];
	f_(i,n,1) B[i]=B[i+1]+mark[i];
	Add(ans,1ll*cnt*(cnt-1)/2%mod*pow(2,mod-2,mod)%mod);
	int now=0;
	f(i,1,n+1){
		if(mark[i]==0) now+=B[i];
	}
	f(i,1,n+1){
		if(a[i]==-1){
			Add(ans,1ll*now*pow(cnt,mod-2,mod)%mod);
		}
		else{
			now-=B[a[i]];
			now+=A[a[i]];
		}
	}
	cout<<ans;
}