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

const int N=(1<<21)+9;

int n,m,t,e,a[N],mx[N],mark[N];
ll ans;
vector<int> tree[N];

void merge(int x,int u,int v){
	int p1=0,p2=0;
	while(p1<tree[u].size() || p2<tree[v].size()){
		if(p2==tree[v].size() || (p1!=tree[u].size() && tree[u][p1]<tree[v][p2]))
			tree[x].pb(tree[u][p1++]);
		else
			tree[x].pb(tree[v][p2++]);
	}
	tree[x].pb(a[x]);
}
void make_tree(){
	f(i,1,n*2+1) mx[i]=0; ans=0;
	f(i,n/2,n)
		tree[i].clear(),tree[i].pb(a[i]);
	f_(i,n/2-1,1)
		tree[i].clear(),merge(i,i*2,i*2+1);
}
int binary_search(int x,int k){
	int l=-1,r=tree[x].size()-1,mid;
	while(l+1<r){
		mid=(l+r)/2;
		if(tree[x][mid]<=k) l=mid;
		else r=mid;
	}
	return tree[x][r];
}
void solve(int x){
	int p=binary_search(x,max(mx[x*2],mx[x*2+1]));
	mark[p]=t;
	ans+=p,mx[x]=p;
}

int main(){
	cin>>t;t++;e=t;
	while(--t){
		cin>>n>>m;
		n=(1<<n),m=(1<<m);
		f(i,1,n) gett(a[i]);
		make_tree();
		f_(i,m-1,1)
			solve(i);
		cout<<ans<<'\n';
		f_(i,n-1,1)
			if(mark[a[i]]!=t)
				cout<<i<<" ";
		cout<<'\n';
	}
}