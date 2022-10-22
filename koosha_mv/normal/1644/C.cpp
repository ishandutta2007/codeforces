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

const int N=5050,inf=1e10;

int n,x,t,a[N],Max[N];

void Main(){
	cin>>n>>x;
	f(i,1,n+1) Max[i]=-inf;
	f(i,1,n+1) cin>>a[i];
	f(i,1,n+1){
		int sum=0;
		f(j,i,n+1){
			sum+=a[j];
			maxm(Max[j-i+1],sum);
		}
	}
	f(i,0,n+1){
		int res=0;
		f(j,0,n+1){
			maxm(res,Max[j]+x*min(j,i));
		}
		cout<<res<<" ";
	}
	cout<<endl;
	f(i,0,n+1) Max[i]=0;
}

main(){
	ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
	cin>>t;
	while(t--){
		Main();
	}
}