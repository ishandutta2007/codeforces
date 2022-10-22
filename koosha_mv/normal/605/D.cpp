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
#define ops(x) cout<<x<<" !"<<endl;
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define Add(x,y) x=(x+y)%mod;
#define lst(x) x[x.size()-1]
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int N=5e5+99,M=2e5+2;

int n,v,fa,a[N],b[N],c[N],d[N],sa[N],sb[N],sc[N],sd[N],par[N],mark[N],dist[N];
vector<pair<int,int> > tree[N];
map<int,int> ta,tb;
vector<int> ans;
queue<int> q;

void add(int x,int y,int an){
	x+=M;
	for(;x;x/=2)
		tree[x].pb(mp(y,an));
}
void make(){
	f(i,1,2*M){
		sort(tree[i].begin(),tree[i].end());
		reverse(tree[i].begin(),tree[i].end());
	}
}
void do_it(){
	int cnt1=0,cnt2=0,cnt3=0,cnt4=0;
	sort(sa,sa+1+n+n);
	sort(sb,sb+1+n+n);
	f(i,0,2*n+1){
		if(i==0 || sa[i]!=sa[i-1]) ta[sa[i]]=cnt1++;
		if(i==0 || sb[i]!=sb[i-1]) tb[sb[i]]=cnt2++;
	}
	f(i,1,n+1){
		a[i]=ta[a[i]];
		b[i]=tb[b[i]];
		c[i]=ta[c[i]];
		d[i]=tb[d[i]];
		add(a[i],b[i],i);
	}
}
void mv(int x,int y){
	while(tree[x].size() && lst(tree[x]).F<=y){
		if(mark[lst(tree[x]).S])
			tree[x].pop_back();
		else{
			q.push(lst(tree[x]).S);
			par[lst(tree[x]).S]=v;
			dist[lst(tree[x]).S]=fa+1;
			mark[lst(tree[x]).S]=1;
			tree[x].pop_back();
		}
	}
}
void query(int l, int r,int c) {
	r++;
	for (l += M, r += M; l < r; l >>= 1, r >>= 1) {
   	if (l&1) mv(l++,c);
   	if(r&1) mv(--r,c); 
	}
}
void bfs(){
	q.push(0);
	while(q.size()){
		int u=q.front();
		v=u,q.pop();
		fa=dist[u];
		query(0,c[u],d[u]);
	}
	v=n;
	while(ans.size()<dist[n]){
		ans.pb(v);
		v=par[v];
	}
	reverse(ans.begin(),ans.end());
}

int main(){
	cin>>n;
	f(i,1,n+1){
		Gett(a[i],b[i]);
		Gett(c[i],d[i]);
		sa[i*2-1]=a[i],sb[i*2-1]=b[i];
		sa[i*2]=c[i],sb[i*2]=d[i];
	}
	do_it();
	make();
	bfs();
	cout<<(dist[n]==0 ? -1 : dist[n])<<endl;
	print(ans,ans.size());
}