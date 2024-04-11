#include <bits/stdc++.h>
using namespace std;
#define erorp(x) cout<<#x<<"={"<<(x.F)<<" , "<<x.S<<"}"<<endl
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl
#define eror(x) cout<<#x<<'='<<(x)<<endl
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define f(i,a,b) for(int i=a;i<b;i++)
#define nb(x) __builtin_popcount(x)
#define maxm(a,b) a=max(a,b)
#define minm(a,b) a=min(a,b)
#define Add(x,y) x=(x+y)%mod
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int N=1e6+99;
const ll inf=1e15;

int n,u,v,a[N];
ll ans=inf,b[N],c[N];

int M(int x,int y){
	if((x+1)%y==0 || (x-1)%y==0) return 1;
	if(x%y==0) return 0;
	return -1;
}
void calc(int x){
	f(i,1,n+1){
		b[i]=b[i-1];
		if(M(a[i],x)==-1) b[i]=inf;
		else b[i]+=v*M(a[i],x);
		minm(b[i],inf);
	}
	f_(i,n,1){
		c[i]=c[i+1];
		if(M(a[i],x)==-1) c[i]=inf;
		else c[i]+=v*M(a[i],x);	
		minm(c[i],inf);
	}
	f_(i,n,1){
		c[i]=c[i]-1ll*u*(n+1-i);
		minm(c[i],c[i+1]);	
	}
	f(i,0,n+1){
		minm(ans,b[i]+c[i+1]+1ll*u*(n-i));
	}
}
void solve(int x){
	for(int i=2;i*i<=x;i++){
		if(x%i==0){
			calc(i);
			while(x%i==0)
				x/=i;
		}
	}
	if(x>1) calc(x);
}

int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n>>u>>v;
	f(i,1,n+1) cin>>a[i];
	f(i,-1,2){
		solve(a[1]+i);
		solve(a[n]+i);
	}
	cout<<ans;
}
/*
6 1 100
8 17 34 51 170 85
*/