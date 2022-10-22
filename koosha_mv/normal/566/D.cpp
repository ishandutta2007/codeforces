#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define is_bit(x,y) (x%(1<<(y+1))>=(1<<y))
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(int i=a;i<b;i++)
#define get(x) scanf("%I64d",&x);
#define gett(x) scanf("%d",&x);																																														
#define ops(x) cout<<x<<" !"<<endl
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define Add(x,y) x=(x+y)%mod
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int N=1e6+99;

int n,q,x,y,type,par[N];
set<int> tree[N];

void make(){
	f(i,0,n-1){
		int c=i+n-1;
		while(c)
			tree[c].insert(i),c/=2;
	}
}
void del(int u){
	int c=u+n-1;
	while(c)
		tree[c].erase(u),c/=2;
}
int Get_par(int u){
	if(par[u]<0) return u;
	return (par[u]=Get_par(par[u]));
}
void merge(int u,int v){
	if(Get_par(u)==Get_par(v)) return ;
	u=Get_par(u),v=Get_par(v);
	if(par[u]>par[v]) swap(u,v);
	par[u]+=par[v];
	par[v]=u;
}
void do_it(int u){
	while(tree[u].size()){
		int el=*tree[u].begin();
		merge(el,el+1);
		del(el);
	}
}
void query(int l,int r){
	for(l += (n-1), r += (n-1); l < r; l >>= 1, r >>= 1) {
   	if(l&1) do_it(l),l++;
   	if(r&1) r--,do_it(r);
	}
}

int main(){
	fill(par,par+N,-1);
	cin>>n>>q;
	make();
	f(i,0,q){
		gett(type);
		Gett(x,y);
		x--,y--;
		if(type==1)
			merge(x,y);
		if(type==2)
			query(x,y);
		if(type==3)
			cout<<(Get_par(x)==Get_par(y) ? "YES" : "NO" )<<'\n';
	}
}