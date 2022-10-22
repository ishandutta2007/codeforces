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

const int N=1e6+99,inf=1e18;

int n,m,a[N];

int cost(int x,int k){
	int d=x/k;
	return d*d*(k-x%k)+(d+1)*(d+1)*(x%k);
}
pair<int,int> calc(int x,int k){
	int l=1,r=x+1;
	while(l+1<r){
		int mid=(l+r)>>1;
		if(cost(x,mid-1)-cost(x,mid)>=k) l=mid;
		else r=mid;
	}
	//eror(cost(x,l-1));
	//eror(cost(x,l));
	return {l-1,cost(x,l)};
}
int check(int x){
	int res=0;
	f(i,1,n+1){
		res+=calc(a[i],x).S;
	}
	return res<=m;
}

int32_t main(){
	ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>n;
	f(i,1,n+1) cin>>a[i]; cin>>m;
	f_(i,n,1) a[i]=a[i]-a[i-1];
	//cout<<check(4)<<endl;
	//return 0;
	//int prt=999999978;
	//eror(cost(a[1],prt)-cost(a[1],prt+1));
	int l=0,r=inf;
	while(l+1<r){
		int mid=(l+r)>>1;
		if(check(mid)) l=mid;
		else r=mid;
	}
	int ans=0,sum=-m;
	f(i,1,n+1){
		pair<int,int> p=calc(a[i],r);
		ans+=p.F;
		sum+=p.S;
	}
	if(sum>0) ans+=(sum+l-1)/l;
	cout<<ans;
}