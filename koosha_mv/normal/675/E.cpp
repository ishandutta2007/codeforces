#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(int i=a;i<b;i++)
#define get(x) scanf("%I64d",&x);
#define gett(x) scanf("%d",&x);																																														
#define ops(x) cout<<x<<" !"<<endl;
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int N=1e5+9;

int n,a[N],sub[N],tree[N*2];
vector<int> g[N];
ll ans;

void make(){
	f_(i,n-1,0){
		if(a[tree[i*2]]>a[tree[i*2+1]])
			tree[i]=tree[i*2];
		else
			tree[i]=tree[i*2+1];
	}
}
int query(int l, int r) {
	int res=0;
	r++;
	for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
   	if (l&1){
   		if(a[tree[l]]>a[res]) res=tree[l];
   		l++;
   	}
   	if (r&1)
   		if(a[tree[--r]]>a[res]) res=tree[r];
	}
  	return res;
}
void dfs(int u){
	sub[u]=1;
	f(i,0,g[u].size()){
		dfs(g[u][i]);
		sub[u]+=sub[g[u][i]];
	}
	ans+=1ll*sub[u]*(n-(a[u]));
}

int main(){
	cin>>n;
	f(i,1,n) {cin>>a[i]; tree[i+n-1]=i; }
	tree[n*2-1]=n,a[n]=n;
	make();
	
	f(i,1,n){
		int u=query(i,a[i]-1);
		g[u].pb(i);
	}
	ans=1ll*n*(n-1)/2ll;
	dfs(n);
	cout<<ans;
}