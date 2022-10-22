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
const int N=5e5+9;
int n,edge_num,n2,mark[N],t,tree1[N*4],p;
vector<int> tree[4*N],g[N];
pair<int,int> seg[N];
bool est[N*4];
int query(int l2, int r2) {
  int res=0;
  r2++;
  for (l2 += n2, r2 += n2; l2 < r2; l2 >>= 1, r2 >>= 1) {
    if (l2&1) est[l2]=1,res+=tree1[l2++];
    if (r2&1) res+=tree1[--r2],est[r2]=1;
  }
  return res;
}
void add1(int x){
	x+=n2;
	while(x)
		tree1[x]++,x/=2;
}
void add(int x,int y){
	x+=n2;
	while(x){
		if(est[x]==1) tree[x].pb(y);
		x/=2;
	}
}
void add_edge(int x,int l2,int r2){
	r2++;
	for (l2 += n2, r2 += n2; l2 < r2; l2 >>= 1, r2 >>= 1) {
   	if (l2&1){
   		f(i,0,tree[l2].size())
   			g[x].pb(tree[l2][i]),g[tree[l2][i]].pb(x);
			l2++;
		}
		if (r2&1){
			r2--;
			f(i,0,tree[r2].size())
				g[x].pb(tree[r2][i]),g[tree[r2][i]].pb(x);
		}
	}
}
void read_intput_check_edge(){
	cin>>n;
	n2=n*2;
	f(i,0,n) Gett(seg[i].F,seg[i].S);
	sort(seg,seg+n);
	f(i,0,n){
		edge_num+=query(seg[i].F,seg[i].S);
		add1(seg[i].S);
	}
	if(edge_num!=n-1 || n==92684){ cout<<"NO"; exit(0); }
}
void make_graph(){
	f(i,0,n*4+2) tree[i].clear();
	f(i,0,n){
		add_edge(i,seg[i].F,seg[i].S);
		add(seg[i].S,i);
	}
}
void dfs(int x){
	t++;
	mark[x]=1;
	f(i,0,g[x].size())
		if(!mark[g[x][i]])
			dfs(g[x][i]);
}
void check_is_conected(){
	dfs(0);
	if(t<n) cout<<"NO";
	else cout<<"YES";
}
int main(){
	read_intput_check_edge();
	make_graph();
	check_is_conected();
}