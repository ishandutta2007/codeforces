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

const int N=1e6+99;

int n,t,par[N];
pair<int,int> a[N];

int get(int u){
	if(par[u]<0) return u;
	return par[u]=get(par[u]);
}
void merge(int u,int v){
	u=get(u),v=get(v);
	par[u]+=par[v];
	par[v]=u;
}
void Main(){
	cin>>n;
	f(i,1,n+1) par[i]=-1;
	f(i,1,n+1){
		cin>>a[i].F;
		a[i].S=i;
	}
	sort(a+1,a+n+1);
	reverse(a+1,a+n+1);
	f(i,1,n+1){
		int u=a[i].S;
		if(par[u]!=-1) continue ;
		f(j,0,a[i].F){
			int v;
			cout<<"? "<<u<<endl;
			cin>>v;
			int b=0;
			merge(u,v);
			if(par[get(u)]<-j-2) break ; 
		}
	}
	cout<<"! ";
	f(i,1,n+1) cout<<get(i)<<" "; cout<<endl;
}

int32_t main(){
	ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>t;
	while(t--){
		Main();
	}
}