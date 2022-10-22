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
#define int ll

const int N=1e6+99,inf=2e9;

int n,t;
pair<int,int> a[N],ans[N];

main(){
	ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>n;
	f(i,0,n){
		cin>>a[i].F;
		a[i].S=i;
	}
	sort(a,a+n);
	f(i,0,n){
		int id=a[i].S;
		ans[id].F=inf;
		ans[id].S=max(a[i].F-a[0].F,a[n-1].F-a[i].F);
		if(i>0) minm(ans[id].F,a[i].F-a[i-1].F);
		if(i+1<n) minm(ans[id].F,a[i+1].F-a[i].F);
	}
	f(i,0,n) cout<<ans[i].F<<" "<<ans[i].S<<endl;
}