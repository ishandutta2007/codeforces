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
 
const int N=1e6+99;
 
int n,q,t,a[N],l[N],k[N],cnt[N],ans[N],seg[4*N];
vector<int> g[N],v[N];
set<int> mark[N];
 
int Get(int L,int R,int id=1,int l=1,int r=n+1){
   if(r<=L || R<=l || L==R) return 0;
   if(L<=l && r<=R){
      return seg[id];
   }
   int mid=(l+r)>>1;
   return Get(L,R,id*2+0,l,mid)+Get(L,R,id*2+1,mid,r);
}
int query(int val,int id=1,int l=1,int r=n+1){
   if(l+1==r) return l;
   int mid=(l+r)/2;
   if(seg[id*2+0]>=val){
   	return query(val,id*2+0,l,mid);
	}
	val-=seg[id*2+0];
	return query(val,id*2+1,mid,r);
}
void Add(int x,int val,int id=1, int l=1,int r=n+1){
   if(l<=x && x<r){
      seg[id]+=val;
      if(l+1==r) return ;
		int mid=(l+r)>>1;
  		Add(x,val,id*2+0,l,mid);
   	Add(x,val,id*2+1,mid,r);   
   }
   return ;
}
void del(int x){
	//cout<<"- "<<x<<" "<<cnt[x]<<endl;
	if(cnt[x]==0) return ;
	Add(cnt[x],-1);
	mark[cnt[x]].erase(x);
}
void add(int x){
	if(cnt[x]==0) return ;
	Add(cnt[x],1);
	mark[cnt[x]].insert(x);
}
void dfs(int x){
	del(a[x]);
	cnt[a[x]]++;
	add(a[x]);
	for(auto u : v[x]){
		k[u]+=Get(1,l[u]);
		//eror(seg[1]);
		if(seg[1]>=k[u]){
			int p=query(k[u]);
			ans[u]=*mark[p].begin();
		}
		
	}
	for(auto u : g[x]){
		dfs(u);
	}
	del(a[x]);
	cnt[a[x]]--;
	add(a[x]);
}
 
main(){
	ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n>>q;
		f(i,1,n+1) cin>>a[i];
		f(i,2,n+1){
			int p;
			cin>>p;
			g[p].pb(i);
		}
		f(i,0,q){
			int u;
			cin>>u>>l[i]>>k[i];
			v[u].pb(i);
			ans[i]=-1;
		}
		dfs(1);
		f(i,0,q){
			cout<<ans[i]<<' ';
		}
		
		f(i,1,n+1){
			cnt[i]=0;
			v[i].clear();
			g[i].clear();
			mark[i].clear();
		}
		f(i,1,4*n+9) seg[i]=0;
	}
}
/*
1
3 1
1 1 1
1 2
3 1 1
 
1
5 1
1 2 1 1 2
1 1 2 2
3 1 1
 
1
5 1
1 2 1 1 2
1 1 2 2
2 1 2
*/