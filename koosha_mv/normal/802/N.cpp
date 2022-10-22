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

const int N=1e6+99;

int n,k,ans,a[N],b[N],ps[N],marka[N],markb[N];

void do_it(){
	int p=n-1,u=n,v=n,id=n;
	b[n]=N*N*N;
	f_(i,n-1,0){
		while(0<=p && (i<=p || 0<ps[p])){
			if(!markb[p] && (id==n || b[p]<b[id])){
				id=p;
			}
			p--;
		}
		if(!marka[i] && id<n && (u==n || a[i]+b[id]<a[u]+b[v])){
			u=i,v=id;
		}
	}
	marka[u]=1;
	markb[v]=1;
	ans+=a[u]+b[v];
	f(i,u,n) ps[i]++;
	f(i,v,n) ps[i]--;
}

main(){
	cin>>n>>k;
	f(i,0,n) cin>>a[i];
	f(i,0,n) cin>>b[i];	
	f(i,0,k){
		do_it();
	}
	cout<<ans;
}
/*
8 2
3 8 7 9 9 4 6 8
2 5 9 4 3 8 9 1
*/