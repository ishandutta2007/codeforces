#include<bits/stdc++.h>
#define ll long long
#define int ll
#define ld long double
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define REP(i,j) for(int i=0;i<j;++i)
#define REPA(i,j) for(int i=1;i<=j;++i)
#define vi vector<int>
#define pii pair<int,int>
#define all(a) a.begin(),a.end()
using namespace std;
const int INF=0x3f3f3f3f;
//const ll INF=0x3f3f3f3f3f3f3f3f;
const ll MOD=1e9+7;
inline void read(int &x){
//	short neg=1;
	x=0;
	char c=getchar();
	/*while(c<'0'||c>'9'){
		if(c=='-')neg=-1;
		c=getchar();
	}*/
	while(c>='0'&&c<='9'){
		x=(x<<3)+(x<<1)+(c^48);
		c=getchar();
	}
//	x*=neg;
}
ll quick_mod(ll A,ll B){//A^B
    ll ret=1;
    A%=MOD;
    while(B){
        if(B&1)ret=ret*A%MOD;
        B>>=1;
        A=A*A%MOD;
    }
    return ret;
}
inline void chkmin(ll &x,ll y){x=min(x,y);}
inline void chkmax(ll &x,ll y){x=max(x,y);}
inline void add(ll &x,ll y){x=(x+y)%MOD;}
inline ll rev(ll x){return quick_mod(x,MOD-2);}
inline int lowbit(int x){return x&(-x);}
const int MAXN=1e5+100;
int N,G,Rd,Q;
int M;
int l[MAXN];
pii qry[MAXN];
int nxt[MAXN];
int nxtt[MAXN];
int ans[MAXN];
int prv[MAXN];
class SEGMENTTREE{
public:
	struct node{
		int ls,rs;
		int val;
		inline void init(){
			ls=rs=0;
			val=N+1;
		}
	}seg[MAXN*90];
	int seg_cnt;
	int L,R;
	int o,P;
	int V;
	
	inline void init(){
		seg_cnt=1;
		L=G,R=Rd+G-1,o=0;
		seg[0].init();
		seg[1].init();
	}
	inline int new_node(){
//		assert(seg_cnt!=MAXN*64-1);
		seg[++seg_cnt].init();
		return seg_cnt;
	}
	inline void update(int pos){
		seg[pos].val=min(seg[seg[pos].ls].val,seg[seg[pos].rs].val);
	}
	void mdf(int pos,int l,int r){
//		cout<<"mdf1("<<l<<','<<r<<"):"<<seg[pos].val<<endl;
		if(l==r){
			if(V<seg[pos].val)seg[pos].val=V;
			return ;
		}
		int mid=(l+r)>>1;
		if(!seg[pos].ls)seg[pos].ls=new_node();
		if(!seg[pos].rs)seg[pos].rs=new_node();
		if(P<=mid)mdf(seg[pos].ls,l,mid);
		else mdf(seg[pos].rs,mid+1,r);
		update(pos);
//		cout<<"mdf2("<<l<<','<<r<<"):"<<seg[pos].val<<endl;
	}
	int ask(int pos,int l,int r){
		if(l>R||r<L)return N+1;
//		cout<<"ask("<<l<<','<<r<<"):"<<seg[pos].val<<endl; 
		if(L<=l&&r<=R)return seg[pos].val;
		int mid=(l+r)>>1;
		if(!seg[pos].ls)seg[pos].ls=new_node();
		if(!seg[pos].rs)seg[pos].rs=new_node();
		return min(ask(seg[pos].ls,l,mid),ask(seg[pos].rs,mid+1,r));
	}
	inline void move(int x){
		R=(R-x%M+M)%M;
		L=(L-x%M+M)%M;
		o=(o-x%M+M)%M; 
//		cout<<"l,r:"<<L<<' '<<R<<' '<<o<<endl;
	}
	inline void insert(int id){
		P=o;
//		cout<<"ins:"<<P<<' '<<id<<endl;
		V=id;
		mdf(1,0,M-1);
	}
	inline int query(){
		int l=L,r=R;
		int ret;
		if(l<=r)ret=ask(1,0,M-1);
		else{
			R=M-1;ret=ask(1,0,M-1);
			L=0,R=r;ret=min(ret,ask(1,0,M-1));
			L=l,R=r;
		}
		return ret;
	}
}T;
signed main(void){ 
	ios::sync_with_stdio(0);
	cin>>N>>G>>Rd;
	M=Rd+G;
	REP(i,N+1)cin>>l[i];
	prv[0]=0;
	REPA(i,N+1)prv[i]=prv[i-1]+l[i-1];
	cin>>Q;
	REP(i,Q)cin>>qry[i].fi,qry[i].se=i;
	sort(qry,qry+Q);
	T.init();
	nxtt[N+1]=0;
	for(int i=N;i>=0;--i){
		T.insert(i+1);
		T.move(l[i]);
		nxt[i]=T.query();
		if(nxt[i]==N+1)nxtt[i]=prv[nxt[i]]-prv[i];
		else nxtt[i]=nxtt[nxt[i]]+(prv[nxt[i]]-prv[i]+M-1)/M*M;
	}
	int lst=0;
	REP(i,Q){
		T.move(qry[i].fi-lst);lst=qry[i].fi;
		int p=T.query();
		if(p==N+1)ans[qry[i].se]=prv[p]-prv[0]+qry[i].fi;
		else ans[qry[i].se]=nxtt[p]+(prv[p]-prv[0]+qry[i].fi+M-1)/M*M;
	}
	REP(i,Q)cout<<ans[i]<<endl;
	return 0;
}
/*
think twice, code once;
think once, debug forever.
*/