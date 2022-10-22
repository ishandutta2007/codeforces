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

const int N=5e6+99;

int n,t,ans,a[N/10],b[N/10];

main(){
	ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	f(i,0,4) cin>>b[i];
	f(i,0,N){
		f(j,0,4) a[j]=b[j];
		if(i>a[0] || i>a[2] || i>a[3]) break;
		a[0]-=i;
		a[2]-=i;
		a[3]-=i;
		int t=min(a[0],a[1]);
		maxm(ans,(t<<5)+(i<<8));
	}
	cout<<ans;
}