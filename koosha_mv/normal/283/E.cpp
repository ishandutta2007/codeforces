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
#define Add(x,y) x=(x+y)%mod;
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
 
const int N=3e5+99;
 
int n,k,l,r,p,u,c,a[N],s[N],t[N],sz[N],tree[N],fenwik[N],tree_up[N],last_update[N],last[N];
vector<int> add[N],rem[N];
ll ans;

void update(int x,int val) { ++x;  while(x<=N)  {  fenwik[x]+=val;  x+=(x&-x);  } }
int query_fen(int x) {  ++x;  int res=0;  while(x>0)  {  res+=fenwik[x];  x-=(x&-x);  } return res; }
 
int lower_bound(int x){
	int l=-1,r=n,mid;
	while(l+1<r){
		mid=(l+r)/2;
		if(a[mid]<x) l=mid;
		else r=mid;
	}
	return r;
}
void make(){
	f(i,n,2*n)
		s[i]=t[i]=i-n,sz[i]=1;
	f_(i,n-1,1)
		s[i]=s[i*2],t[i]=t[i*2+1],sz[i]=t[i]-s[i]+1;
}
int query_up(int l) {
	int res=0;
	if(l>0)
		res=query_fen(l-1);
	return c-res;
}
void update_node(int x){
	if(last[x]==c) return ;
	int o=query_up(t[x]);
	if((last_update[x]+o)%2) tree[x]=sz[x]-tree[x];
	last_update[x]=o%2;
	last[x]=c;
}
int query(int l, int r) {
	int res=0;r++;
	for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
   	if (l&1){ update_node(l); res+=tree[l++]; }
   	if (r&1){ update_node(--r); res+=tree[r]; }
	}
	return res;
}
void change_node(int x,int an){
	if(x==0) return ;
	if(an<t[x]){
		int le=an-s[x]+1;
		update_node(x);
		tree[x]=tree[x]+le-query(s[x],an)*2;	
	}
	change_node(x/2,an);
	if(x-n==an){
		c++;
		update(an,1);
	}
}
void change_interval(int l,int r){
	c++;
	change_node(r+n,r);l--;
	c++;
	if(l>=0)
		change_node(l+n,l);
}
void solve(){
	ans=1ll*n*(n-1)*(n-2)/6;
	change_interval(0,n-1);
	p=1;
	f(i,0,n){
		f(j,0,add[i].size()) change_interval(i,add[i][j]),p++;
		f(j,0,rem[i].size())	change_interval(rem[i][j],i-1),p++;
		u=query(0,n-1)-(p%2);
		ans=ans-1ll*u*(u-1)/2;
		change_interval(i,i);
	}
	cout<<ans;
}
 
int main(){
	cin>>n>>k;
	make();
	f(i,0,n) gett(a[i]);
	sort(a,a+n);
	f(i,0,k){
		cin>>l>>r;
		l=lower_bound(l);
		r=lower_bound(r+1)-1;
		if(r>=0){
			add[l].pb(r);
			rem[r+1].pb(l);
		}
	}
	solve();
}