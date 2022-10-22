#include <bits/stdc++.h>
using namespace std;
#define dbgv(v) cout<<#v<<" = "; f(i,0,v.size()) cout<<v[i]<<" "; cout<<endl
#define dbga(a,x,y) cout<<#a<<" = "; f(i,x,y) cout<<a[i]<<" "; cout<<endl
#define erorp(x) cout<<#x<<"={"<<x.F<<" , "<<x.S<<"}"<<endl
#define eror(x) cout<<#x<<'='<<(x)<<endl
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define f(i,a,b) for(int i=a;i<b;i++)
#define nb(x) __builtin_popcount(x)
#define all(v) v.begin(),v.end()
#define bit(n,k) (((n)>>(k))&1)
#define Add(x,y) x=(x+y)%mod
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

const int N=1e5+99;

int n,q,a[N];

struct lazy{
	int lz[10];
	lazy(int x=0,int y=0){
		iota(lz,lz+10,0);
		lz[x]=y;
	}
	void reset(){
		iota(lz,lz+10,0);
	}
	void upd(lazy A){
		f(i,0,10) lz[i]=A.lz[lz[i]];
	}
} lz[N<<2];
struct node{
	int cnt[10];
	node(){
		fill(cnt,cnt+10,0);
	}
	node friend operator + (node A,node B){
		f(i,0,10) A.cnt[i]+=B.cnt[i];
		return A;
	}
	void upd(lazy A){
		int pnt[10];
		fill(pnt,pnt+10,0);
		f(i,0,10) pnt[A.lz[i]]+=cnt[i];
		f(i,0,10) cnt[i]=pnt[i];
	}
	int get(){
		int ans=0;
		f(i,0,10) ans+=i*cnt[i];
		return ans;
	}
} seg[N<<2];

void update(int id,lazy A){
	lz[id].upd(A);
	seg[id].upd(A);
}
void shift(int id){
	update(id<<1,lz[id]);
	update(id<<1|1,lz[id]);
	lz[id].reset();
}
void build(int id=1,int l=1,int r=n+1){
	if(l+1==r){
		int pow=1;
		while(a[l]){
			seg[id].cnt[a[l]%10]+=pow;
			pow*=10;
			a[l]/=10;
		}
		return ;
	}
	int mid=(l+r)>>1;
	build(id<<1,l,mid);
	build(id<<1|1,mid,r);
	seg[id]=seg[id<<1]+seg[id<<1|1];
}
void change(int L,int R,lazy A,int id=1,int l=1,int r=n+1){
	if(r<=L || R<=l) return ;
	if(L<=l && r<=R){
		update(id,A);
		return ;
	}
	shift(id);
	int mid=(l+r)>>1;
	change(L,R,A,id<<1,l,mid);
	change(L,R,A,id<<1|1,mid,r);
	seg[id]=seg[id<<1]+seg[id<<1|1];
}
int get(int L,int R,int id=1,int l=1,int r=n+1){
	if(r<=L || R<=l) return 0;
	if(L<=l && r<=R){
		return seg[id].get();
	}
	shift(id);
	int mid=(l+r)>>1;
	return get(L,R,id<<1,l,mid)+get(L,R,id<<1|1,mid,r);
}
int32_t main(){
	ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>n>>q;
	f(i,1,n+1){
		cin>>a[i];
	}
	build();
	while(q--){
		int type,l,r,x,y;
		cin>>type;
		if(type==1){
			cin>>l>>r>>x>>y; r++;
			lazy A(x,y);
			change(l,r,A);
		}
		if(type==2){
			cin>>l>>r; r++;
			cout<<get(l,r)<<endl;
		}
	}
}