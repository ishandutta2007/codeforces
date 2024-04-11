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
#define pii pair<int,int>

const int N=2e6+99;

int n,t,a[N],p[N],prv[N],nxt[N],lazy[N];
ll ans;
pii seg[N];

pii merge(pii u,pii v){
	if(u.F==v.F) return mp(u.F,u.S+v.S);
	return min(u,v);
}
void build(int id=1,int l=1,int r=n+1){
	if(l+1==r){
		seg[id]=mp(0,1);
		return ;
	}
	int mid=(l+r)/2;
	build(id*2+0,l,mid);
	build(id*2+1,mid,r);
	seg[id]=merge(seg[id*2+0],seg[id*2+1]);
}
void shift(int id){
   seg[id*2+0].F+=lazy[id];
   seg[id*2+1].F+=lazy[id];
   lazy[id*2+0]+=lazy[id];
   lazy[id*2+1]+=lazy[id];
   lazy[id]=0;
}
void add(int L,int R,int val,int id=1, int l=1,int r=n+1){
   if(r<=L || R<=l) return ;
   if(L<=l && r<=R){
      lazy[id]+=val;
      seg[id].F+=val;
      return ;   
   }
   int mid=(l+r)>>1;
   shift(id);
   add(L,R,val,id*2+0,l,mid);
   add(L,R,val,id*2+1,mid,r);
   seg[id]=merge(seg[id*2+0],seg[id*2+1]);
}
pii query(int L,int R,int id=1,int l=1,int r=n+1){
   if(r<=L || R<=l) return mp(N,N);
   if(L<=l && r<=R){
      return seg[id];
   }
   shift(id);
   int mid=(l+r)>>1;
   return merge(query(L,R,id*2+0,l,mid),query(L,R,id*2+1,mid,r));
}

int main(){
	
	cin>>n;
	f(i,1,n+1){
		int x,y;
		cin>>x>>y;
		a[x]=y;
		p[y]=x;
	}
	p[n+1]=n+1;
	f(i,1,n+1){
		nxt[i]=p[a[i]+1];
		prv[p[a[i]+1]]=i;
	}
	build();
	f(i,1,n+1){
		if(nxt[i]>i){
			add(1,i+1,1);
		}
		else{
			add(nxt[i]+1,i+1,1);
		}
		if(prv[i]>0 && prv[i]<i){
			add(1,prv[i]+1,-1);
		}
		pii res=query(1,i+1);
		if(res.F==1){
			ans+=res.S;
		}
	}
	cout<<ans;
}
/*
3
1 1
2 2
3 3
*/