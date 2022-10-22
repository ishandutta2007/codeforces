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

const int N=2e5+99;

int n,t,a[N];
ll ans;
map<pair<int,int>,int> mark[N];

int get(int x,int dp=n+1,int pd=0){
	if(x==n+1) return 1;
	if(mark[x].count(mp(dp,pd))) return mark[x][mp(dp,pd)];
	int ndp=0,npd=n+1;
	if(a[x-1]<a[x]){
		ndp=dp;
	}
	else{
		npd=pd;
	}
	if(pd<a[x]){
		maxm(ndp,a[x-1]);
	}
	if(dp>a[x]){
		minm(npd,a[x-1]);
	}
	if(ndp==0 && npd==n+1) return 1;
	return mark[x][mp(dp,pd)]=get(x+1,ndp,npd)+1;
}

int32_t main(){
	ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>n;
	f(i,1,n+1) cin>>a[i];
	f_(i,n,1){
		ans+=get(i+1);
	}
	cout<<ans;
}