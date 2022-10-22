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
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first
 
const int N=1e6+99,M=1005;
 
int n,m,q,Time,a[N],s[N],t[N],lazy[N];
bitset<M> b,ans,def,prime,seg[N];
vector<int> g[N];
 
void Mod(int &x,int y){
	x+=y;
	if(x>=m) x-=m;
}
void dfs(int x,int par){
	s[x]=Time++;
	f(i,0,g[x].size()){
		if(g[x][i]!=par){
			dfs(g[x][i],x);
		}
	}
	t[x]=Time;
}
void Shift(int id,int shift){
	shift%=m;
	int x=m-shift;
	b=(seg[id]>>x);
	seg[id]=((seg[id]<<shift) | b);
	seg[id]&=def;
}
void shift(int id){
	Shift(id*2+0,lazy[id]);
	Shift(id*2+1,lazy[id]);
	Mod(lazy[id*2+0],lazy[id]);
	Mod(lazy[id*2+1],lazy[id]);
	lazy[id]=0;
}
void Add(int id,int L,int R,int l,int r,int val,int type){
   if(R<=l || r<=L) return ;
   if(L<=l && r<=R){
   	if(type==0){
   		seg[id][val]=1;
		}
		else{
			Shift(id,val);
			Mod(lazy[id],val);
		}
		return ;
	}
	int mid=(l+r)/2;
	shift(id);
	Add(id*2+0,L,R,l,mid,val,type);
	Add(id*2+1,L,R,mid,r,val,type);
	seg[id]=seg[id*2+0] | seg[id*2+1];
}
void Get(int id,int L,int R,int l,int r){
	if(R<=l || r<=L) return ;
   if(L<=l && r<=R){
   	ans|=seg[id];
   	return ;
	}
	int mid=(l+r)/2;
	shift(id);
	Get(id*2+0,L,R,l,mid);
	Get(id*2+1,L,R,mid,r);
	seg[id]=seg[id*2+0] | seg[id*2+1];
}
main(){
   f(i,2,M){
      prime[i]=1;
      f(j,2,i){
      	if(i%j==0){
      		prime[i]=0;
			}
		}
   }
   cin>>n>>m;
   f(i,1,n+1){
      cin>>a[i];
      a[i]%=m;
   }
   f(i,1,n){
      int u,v;
      cin>>u>>v;
      g[u].pb(v);
      g[v].pb(u);
   }
   dfs(1,0);
  	f(i,0,m) def[i]=1;
   f(i,1,n+1){
   	Add(1,s[i],s[i]+1,0,n,a[i],0);
	}
	cin>>q;
	f(i,0,q){
		int type,v,x;
		cin>>type>>v;
		if(type==1){
			cin>>x;
			x%=m;
			Add(1,s[v],t[v],0,n,x,1);
		}
		else{
			ans=0;
			Get(1,s[v],t[v],0,n);
			ans&=prime;
			cout<<ans.count()<<endl;
		}
	}
}