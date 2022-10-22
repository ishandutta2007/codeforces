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

const int N=1000,inf=1e16;

int n,t,res,a[N][N];

void solve(int x,int y){
	minm(res,a[x][y]);
	minm(res,a[x+n-1][y]);
	minm(res,a[x][y+n-1]);
	minm(res,a[x+n-1][y+n-1]);
	
}
void Main(){
	int ans=0;
	cin>>n;
	f(i,0,2*n){
		f(j,0,2*n){
			cin>>a[i][j];
			if(n<=i && n<=j){
				ans+=a[i][j];
				a[i][j]=0;
			}
		}
	}
	res=inf;
	solve(0,n);
	solve(n,0);
	cout<<res+ans<<'\n';
}

main(){
	//t=1;
	cin>>t;
	while(t--){
		Main();
	}
}