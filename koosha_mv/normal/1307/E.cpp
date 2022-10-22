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
#define pii pair<int,int>

const int N=5005,mod=1e9+7;

int n,m,a[N],h[N],fav[N],cnt0[N],cnt1[N],mark[N][N];
pii ans;

pii solve(int x){
	if(x>0 && mark[a[x]][cnt0[a[x]]]==mark[a[x]][cnt0[a[x]]-1]) return {0,0};
	f(i,cnt0[a[x]],n+1) mark[a[x]][i]--;
	pair<int,int> ans={0,1};
	f(i,1,n+1){
		int u=mark[i][cnt1[i]],v=0;
		if(i!=a[x]){
			v=mark[i][cnt0[i]];
		}
		if(u<v) swap(u,v);
		if(u==0 && v==0) continue ;
		if(v==0){
			ans.F++,ans.S=1ll*ans.S*u%mod;
			continue ;
		}
		if(u==1){
			ans.F++,ans.S=2ll*ans.S%mod;
			continue ;
		}
		ans.F+=2;
		ans.S=1ll*ans.S*(u-1)*v%mod;
	}
	f(i,cnt0[a[x]],n+1) mark[a[x]][i]++;
	if(x!=0) ans.F++;
	return ans;
}
int32_t main(){
	ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>n>>m;
	f(i,1,n+1) cin>>a[i],cnt1[a[i]]++;
	f(i,1,m+1){
		cin>>fav[i]>>h[i];
		mark[fav[i]][h[i]]=1;
	}
	f(i,1,n+1) f(j,1,cnt1[i]+1) mark[i][j]+=mark[i][j-1];
	f(i,0,n+1){
		if(i>0) cnt0[a[i]]++,cnt1[a[i]]--;
		pii p=solve(i);
		if(p.F>ans.F) ans.F=p.F,ans.S=0;
		if(p.F==ans.F) Add(ans.S,p.S);
	}
	cout<<ans.F<<" "<<ans.S;
}