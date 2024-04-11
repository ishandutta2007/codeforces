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

const int N=2e5+99;

int n,t,res,ans,a[N],cnt[N],dp[N],fenwik[N];
vector<int> v[N];

void upd(int x, int val){ for (x++;x>0;x-=x&-x) minm(fenwik[x],val); }
int get(int x) { int res=N; for(x++;x<N;x+=x&-x) minm(res,fenwik[x]); return res; }

int main(){
	fill(fenwik,fenwik+N,N);
	cin>>n;
	ans=n;
	f(i,1,n+1){
		cin>>a[i];
		v[a[i]].pb(i);
	}	
	dp[0]=0;
	upd(0,0);
	f(i,1,n+1){
		dp[i]=N;
		if(++cnt[a[i]]==1) res++; 
		if(cnt[a[i]]==v[a[i]].size()) res--;
		if(i==v[a[i]].back() && i!=v[a[i]][0]){
			dp[i]=min(get(v[a[i]][0]-1)+1,get(v[a[i]][0]))+1;
		}
		if(res==0 && v[a[i]].size()==1){
			ans--;
			dp[i]=dp[i-1];
		}
		upd(i,dp[i]);
		//cout<<i<<" "<<dp[i]<<endl;
	}
	//eror(ans);
	cout<<ans-dp[n];
}