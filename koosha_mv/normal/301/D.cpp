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

const int N=2e5+9;

int n,m,l,r,ans[N],a[N],mark[N],tree[N*2];
vector<int> g[N];
vector<pair<int,int> > q[N];

int query(int l, int r) {
	int res=0;
	r++;
	for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
   	if (l&1)
   		res+=tree[l++];
   	if (r&1)
   		res+=tree[--r];
	}
	return res;
}
void add_edge(int x,int y){
	if(x<y) swap(x,y);
	g[x].pb(y);
}
void add(int x){
	x+=n;
	while(x)
		tree[x]++,x/=2;
}

int main(){
	cin>>n>>m;
	f(i,0,n){ gett(a[i]); mark[a[i]]=i; }
	f(i,0,n)
		for(int j=1;j*j<=a[i];j++)
			if(a[i]%j==0){
				add_edge(i,mark[j]);
				if(j*j!=a[i])
					add_edge(i,mark[a[i]/j]);
			}
	f(i,0,m){
		Gett(l,r);--l,--r;
		q[r].pb(mp(l,i));
	}
	f(i,0,n){
		f(j,0,g[i].size()) add(g[i][j]);
		f(j,0,q[i].size())
			ans[q[i][j].S]=query(q[i][j].F,i);
	}
	print(ans,m);
}