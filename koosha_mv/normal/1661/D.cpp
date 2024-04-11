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

const int N=1e6+99,inf=1e15;

int n,k,t,ans,sum,a[N],b[N];

int32_t main(){
	ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>n>>k;
	f_(i,n,1) cin>>a[i];
	//dbga(a,1,n+1);
	f(i,1,n+1){
		sum-=t;
		t-=b[i];
		a[i]=max(0ll,a[i]-sum);
		//eror(a[i]);
		if(i<=n-k){
			int p=(a[i]+k-1)/k;
			t+=p;
			ans+=p;
			sum+=p*k;
			b[i+k]+=p;
			//cout<<i<<" "<<p<<endl;
		}
	}
	int mx=0;
	f(i,n-k+1,n+1){
		maxm(mx,(a[i]+n-i)/(n-i+1));
	}
	cout<<ans+mx;
}