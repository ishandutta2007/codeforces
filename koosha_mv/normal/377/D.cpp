#include <bits/stdc++.h>
using namespace std;
#define erorp(x) cout<<#x<<"={"<<(x.F)<<" , "<<x.S<<"}"<<endl
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl
#define eror(x) cout<<#x<<'='<<(x)<<endl
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define f(i,a,b) for(int i=a;i<b;i++)
#define nb(x) __builtin_popcount(x)
#define maxm(a,b) a=max(a,b)
#define minm(a,b) a=min(a,b)
#define Add(x,y) x=(x+y)%mod
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int N=2e6+99,m=3e5+9;

int n,ans,L,R,s[N],a[N],t[N],lazy[N];
pair<int,int> seg[N];
vector<int> vs[N],va[N];

pair<int,int> merge(pair<int,int> u,pair<int,int> v){
	return max(u,v);
}
void build(int id=1,int l=1,int r=m){
	if(l+1==r){
		seg[id]=mp(0,l);
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
void add(int L,int R,int val,int id=1, int l=1,int r=m){
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


int main(){
	build();
	cin>>n;
	f(i,0,n){
		cin>>s[i]>>a[i]>>t[i];
		vs[s[i]].pb(i);
		va[a[i]].pb(i);
	}
	f(i,1,m){
		f(j,0,vs[i].size()){
			int x=vs[i][j];
			add(a[x],m,1);
			add(t[x]+1,m,-1);
		}
		if(seg[1].F>ans){
			//erorp(seg[1]);
			L=i,R=seg[1].S;
			ans=seg[1].F;
		}
		f(j,0,va[i].size()){
			int x=va[i][j];
			add(a[x],m,-1);
			add(t[x]+1,m,1);
		}
	}
	cout<<ans<<endl;
	f(i,0,n){
		if(s[i]<=L && R<=t[i] && L<=a[i] && a[i]<=R){
			cout<<i+1<<" ";
		}
	}
}