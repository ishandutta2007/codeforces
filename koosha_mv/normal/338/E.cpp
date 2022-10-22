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
#define int ll

const int N=1e6+99,inf=1e9;

int n,m,k,ans,a[N],pos[N],fen[N],seg[N],lazy[N];
vector<int> b;
vector<pair<int,int> > cmp;

void addf(int x, int val) { for(x++;x<N;x+=x&-x) fen[x]+=val; }
int getf(int x) { int res=0; for (x++;x>0;x-=x&-x) res+=fen[x]; return res; }

int merge(int u,int v){
	return min(u, v);
}
void shift(int id){
   seg[id*2+0]+=lazy[id];
   seg[id*2+1]+=lazy[id];
   lazy[id*2+0]+=lazy[id];
   lazy[id*2+1]+=lazy[id];
   lazy[id]=0;
}
void add(int L,int R,int val,int id=1,int l=0,int r=n){
   if(r<=L || R<=l) return ;
   if(L<=l && r<=R){
      lazy[id]+=val;
      seg[id]+=val;
      return ;   
   }
   int mid=(l+r)>>1;
   shift(id);
   add(L,R,val,id*2+0,l,mid);
   add(L,R,val,id*2+1,mid,r);
   seg[id]=merge(seg[id*2+0],seg[id*2+1]);
}
int query(int L,int R,int id=1,int l=0,int r=n){
   if(r<=L || R<=l) return inf;
   if(L<=l && r<=R){
      return seg[id];
   }
   shift(id);
   int mid=(l+r)>>1;
   return merge(query(L,R,id*2+0,l,mid),query(L,R,id*2+1,mid,r));
}
void change(int x,int val){
	int last=query(x,x+1);
	add(x,x+1,val-last);
}
void Add(int x,int id){
	int pos = lower_bound(cmp.begin(), cmp.end(), mp(x,id)) - cmp.begin(), max_behind = b.end() - lower_bound(b.begin(), b.end(), k-x);
	change(pos, max_behind - getf(pos));
	add(pos,n,-1);
	addf(pos, 1);
}
void Del(int x,int id){
	int pos = lower_bound(cmp.begin(), cmp.end(), mp(x,id)) - cmp.begin();
	addf(pos, -1);
	add(pos, n, 1);
	change(pos, inf);
}

main(){
	fill(seg, seg+N, inf);
	cin >> n >> m >> k;
	f(i,0,m){
		int x;
		cin >> x;
		b.pb(x);
	}
	f(i,0,n){
		cin >> a[i];
		cmp.pb(mp(a[i], i));
	}
	sort(b.begin(), b.end());
	sort(cmp.begin(), cmp.end());
	f(i,0,n){
		Add(a[i],i);

		if(i>=m) Del(a[i-m], i-m);
		if(i + 1 >= m){
			if(seg[1] >= 0) ans++;
		}
	}
	cout << ans;
}