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
#define bit(x) (1ll<<(x*1ll))
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int N=2e5+9,sq=450;

ll n,t,l,r,mid,cnt=1,a[N],ans[N],tree[N*2],d[N],c[N],tdd[N*5];
vector<int> s,v[N*5];
vector<pair<int,int> > g[N];

ll query(int l, int r) {
	ll res=0;
	r++;
	for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
   	if (l&1)
   		res+=tree[l++];
   	if (r&1)
   		res+=tree[--r];
	}
  return res;
}
void add(ll x,ll y){
	x+=n;
	while(x)
		tree[x]+=y,x/=2;
}
void add(ll x){
	if(tdd[a[x]]<=sq){
		add(x,a[x]);
		f(j,0,v[a[x]].size())
			add(v[a[x]][j],a[x]*2);
	}
	v[a[x]].pb(x);
}
ll solve(ll x,ll y){
	l=-1,r=v[x].size();
	while(l+1<r){
		mid=(l+r)/2;
		if(v[x][mid]<y) l=mid;
		else r=mid;
	}
	return (v[x].size()-r)*(v[x].size()-r)*x;
}
ll Get_ans(ll x,ll y){
	ll ans=0;
	ans=query(x,y);
	
	f(i,0,s.size())
		ans+=solve(s[i],x);
	return ans;
}

int main(){
	cin>>n>>t;
	f(i,0,n){
		gett(a[i]);
		tdd[a[i]]++;
	}
	f(i,1,N*5){
		if(tdd[i]>sq)
			s.pb(i);
	}
	f(i,0,t){
		Gett(l,r);
		l--,r--;
		g[r].pb(mp(l,i));
	}
	f(i,0,n){
		add(i);
		f(j,0,g[i].size())
			ans[g[i][j].S]=Get_ans(g[i][j].F,i);
	}
	print(ans,t);
}