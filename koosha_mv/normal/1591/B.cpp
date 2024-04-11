#include <bits/stdc++.h>
using namespace std;
#define erorp(x) cout<<#x<<"={"<<(x.F)<<" , "<<x.S<<"}"<<endl
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl
#define eror(x) cout<<#x<<'='<<(x)<<endl
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define f(i,a,b) for(int i=a;i<b;i++)
#define nb(x) __builtin_popcount(x)
#define Add(x,y) x=(x+y)%mod;
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

int n,t,ans,now,b[N],mx[N];
pair<int,int> a[N];

main(){
	ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>t;
	while(t--){
	ans=0;
	cin>>n;
	f(i,0,n){
		cin>>a[i].F;
		a[i].S=i;
		b[i]=a[i].F;
		now=a[i].F;
	}
	sort(a,a+n);
	mx[n-1]=a[n-1].S;
	f_(i,n-2,0){
		mx[i]=max(mx[i+1],a[i].S);
	}
	while(now!=a[n-1].F){
		//eror(now);
		int p=upper_bound(a,a+n,mp(now,N))-a;
		now=b[mx[p]];
		ans++;
	}
	cout<<ans<<endl;
	
	}
}