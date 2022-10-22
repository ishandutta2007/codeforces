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

const int N=2022;

int n,t,ans,a[N],par[N];

int getpar(int u){
	if(par[u]<0) return u;
	return par[u]=getpar(par[u]);
}
void merge(int u,int v){
	u=getpar(u),v=getpar(v);
	if(u==v) return ;
	if(par[u]>par[v]) swap(u,v);
	par[u]+=par[v];
	par[v]=u;
}

bool check(){
	fill(par,par+n+2,-1);
	f(i,1,n+1){
		f(j,i+1,n+1){
			if((a[i]&a[j])>0){
				merge(i,j);
			}
		}
	}
	if(par[getpar(1)]==-n) return 1;
	return 0;
}
void Print(){
	cout<<ans<<'\n';
	f(i,1,n+1) cout<<a[i]<<" "; cout<<'\n';
}
void Main(){
	ans=0;
	cin>>n;
	f(i,1,n+1){
		cin>>a[i];
		if(a[i]==0) a[i]++,ans++;
	}
	if(check()){
		Print();
		return ;
	}
	ans++;
	f(i,1,n+1){
		a[i]--;
		if(check()){
			Print();
			return ;
		}
		a[i]+=2;
		if(check()){
			Print();
			return ;
		}
		a[i]--;
	}
	int mx=0;
	f(i,1,n+1) maxm(mx,a[i]&-a[i]);
	f(i,1,n+1){
		if(mx==(a[i]&-a[i])){
			a[i]--;
			break ;
		}
	}
	ans++;
	f(i,1,n+1){
		a[i]--;
		if(check()){
			Print();
			return ;
		}
		a[i]+=2;
		if(check()){
			Print();
			return ;
		}
		a[i]--;
	}
}

int32_t main(){
	ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>t;
	while(t--){
		Main();
	}
}
/*
1
2
0 2
*/