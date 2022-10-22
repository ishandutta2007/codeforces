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

const int N=1e5+99;

int n,m,s[N],t[N],par[N];
vector<int> e1,e2;
vector<int> v,ans;

int Get_par(int u){
	if(par[u]<0) return u;
	return par[u]=Get_par(par[u]);
}
void merge(int u,int v){
	u=Get_par(u),v=Get_par(v);
	if(u==v) return ;
	if(par[u]>par[v]) swap(u,v);
	par[u]+=par[v];
	par[v]=u;
}
void p(){
	cout<<"ANS : ";
	f(i,0,ans.size()) cout<<ans[i]+1<<" "; cout<<endl;
}
int main(){
	cin>>n>>m;
	if(n%2==0) return cout<<-1,0;
	f(i,0,m){
		char c;
		cin>>s[i]>>t[i]>>c;
		if(c=='M') e1.pb(i);
		else e2.pb(i);
	}
	
	fill(par,par+N,-1);
	
	f(i,0,e1.size()){
		merge(s[e1[i]],t[e1[i]]);	
	}
	f(i,0,e2.size()){
		if(Get_par(s[e2[i]])!=Get_par(t[e2[i]])){
			v.pb(e2[i]);
			merge(s[e2[i]],t[e2[i]]);
		}
	}
	if(par[Get_par(1)]!=-n || v.size()>n/2) return cout<<-1,0;
	
	fill(par,par+N,-1);
	
	f(i,0,v.size()){
		ans.pb(v[i]);
		merge(s[v[i]],t[v[i]]);
	}
	f(i,0,e2.size()){
		if(ans.size()<n/2 && Get_par(s[e2[i]])!=Get_par(t[e2[i]])){
			ans.pb(e2[i]);
			merge(s[e2[i]],t[e2[i]]);
		}
	}
	if(ans.size()<n/2) return cout<<-1,0;
	f(i,0,e1.size()){
		if(Get_par(s[e1[i]])!=Get_par(t[e1[i]])){
			merge(s[e1[i]],t[e1[i]]);
			ans.pb(e1[i]);
		}
	}
	cout<<ans.size()<<endl;
	f(i,0,ans.size()) cout<<ans[i]+1<<" ";
}