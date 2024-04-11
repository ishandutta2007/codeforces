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

const int N=2e6+99;

int n,t,a[N],b[N];

void solve(int x,int s){
	int l=0,r=x-1,now=x;
	f(i,0,N){
		int p=lower_bound(b+1,b+n+1,now)-b;
		//eror(now);
		//eror(p);
		minm(r,now-b[p-1]-1);
		if(p<=n) maxm(l,now+x+i-1-b[p]);
		if(p>n) break;
		now+=2*(x+i);
	}
	if(r<l) return ;
	if(a[1]<=s+r){
		cout<<max(0ll,s+l-a[1]);
		exit(0);
	}
}
int32_t main(){
	ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>n;
	f(i,1,n+1) cin>>a[i];
	f(i,1,n+1) b[i]=a[i]-a[1]; 
	//dbga(b,1,n+1);
	f(i,2,N) solve(i,(i-1)*(i-1));
}