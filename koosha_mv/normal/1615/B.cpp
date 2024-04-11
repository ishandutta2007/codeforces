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

const int N=3e5+99;

int n,t,a[30][N];

int E(int l,int r,int L,int R){
	return max(0ll,min(r,R)-max(l,L)+1);
}
void Main(){
	int l,r,ans=0;
	cin>>l>>r;
	f(i,0,30){
		maxm(ans,a[i][r]-a[i][l-1]);
	}
	cout<<r-l+1-ans<<'\n';
}

main(){
	f(i,0,30){
		f(j,1,N){
			a[i][j]=a[i][j-1]+((j&(1<<i))>0);
		}
	}
	//t=1;
	cin>>t;
	while(t--){
		Main();
	}	
}