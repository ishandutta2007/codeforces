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

const int N=2e5+99;

int n,m,q,ans=N,a[N],dp[N];
map<pair<int,int> ,int> mark;

void calc(int u,int v,int last,int cnt,int dist){
	if(u==n && v==m){
		minm(ans,dist);
		return ;
	}
	if(dist>25 && u!=n && v!=m) return ;
	int res=N;
	if(u<n && (v==m || last!=0 || cnt<2)){
		int x=u+v+mark[mp(u,v)];
		if(u<n && n<x){
			x=n;
		}
		calc(x,v,0,(last==0 ? cnt+1 : 1),dist+1);
	}	
	if(v<m && (u==n || last!=1 || cnt<2)){
		int x=u+v+mark[mp(u,v)];
		if(v<m && m<x){
			x=m;
		}
		calc(u,x,1,(last==1 ? cnt+1 : 1),dist+1);
	}
}

int main(){
	ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>n>>m>>q;
	f(i,0,q){
		int u,v;
		cin>>u>>v;
		mark[mp(u,v)]=1;
	}
	calc(1,1,0,0,0);
	cout<<ans;
}