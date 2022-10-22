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

const int N=1e5+99;

int n,m,Min,a[N],b[N];
vector<int> ans;

bool check1(int x){
	int now=0;
	f(i,1,n+1){
		if(b[i-1]>a[i]) return 0;
		b[i]=max(b[i-1]+x,a[i]);
	}
	return 1;
}
bool check2(int x,int t=0){
	if(t) ans.pb(m);
	int now=m;
	f_(i,n,1){
		now=max(b[i-1],now-x);
		if(a[i]<now) return 0;
		if(t) ans.pb(now);
	}
	if(now>0) return 0;
	return 1;
		
}

int32_t main(){
	ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>m>>n;
	f(i,1,n+1) cin>>a[i];
	int l=0,r=m+1;
	while(l+1<r){
		int mid=(l+r)>>1;
		if(check1(mid)) l=mid;
		else r=mid;
	}
	check1(l);
	Min=l;
	l=Min-1,r=m+1;
	while(l+1<r){
		int mid=(l+r)>>1;
		if(check2(mid)) r=mid;
		else l=mid;
	}
	check2(r,1);
	f_(i,ans.size()-1,1){
		cout<<ans[i]<<" "<<ans[i-1]<<endl;
	}
}