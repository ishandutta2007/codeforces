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

const int N=1e6+99;

int n,t,a[N],b[N],c[N];

int solve(int s){
	int res=0;
	f(i,2,n){
		if(bit(i,0)!=s) continue ;
		res+=max(a[i],max(a[i-1]+1,a[i+1]+1))-a[i];
	}
	return res;
}
void Main(){
	cin>>n;
	f(i,1,n+1) cin>>a[i];
	int ans=solve(0);
	b[1]=0;
	c[n]=0;
	if(bit(n,0)==0){
		minm(ans,solve(1));
		f(i,2,n+1){
			b[i]=b[i-1];
			if(bit(i,0)==bit(2,0)){
				b[i]+=max(a[i],max(a[i-1]+1,a[i+1]+1))-a[i];
			}
		}
		f_(i,n-1,1){
			c[i]=c[i+1];
			if(bit(i,0)==bit(n-1,0)){
				c[i]+=max(a[i],max(a[i-1]+1,a[i+1]+1))-a[i];
			}
		}
		f(i,2,n){
			minm(ans,b[i]+c[i+1]);
		}
	}
	cout<<ans<<'\n';
}

int32_t main(){
	ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>t;
	while(t--){
		Main();
	}
}