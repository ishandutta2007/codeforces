#include<bits/stdc++.h>
using namespace std;
#define N 200020
#define M 1000100
typedef long long ll;
int n,a[N],p[N],Q;
vector<int> fac[N];
ll ans[M];
class BIT{
	int b[N];
	inline int lowbit(int x){
		return x&(-x);
	}
public:
	inline void Add(int x,int d){
		while(x<=n)b[x]+=d,x+=lowbit(x);
	}
	inline int Ask(int x){
		int ans=0;
		while(x)ans+=b[x],x-=lowbit(x);
		return ans;
	}
}B;
struct node{
	int ch[2];
}t[N];
struct Range{
	int op,l,r;
	Range(int _op,int _l,int _r):op(_op),l(_l),r(_r){}
};
vector<Range> c[N];
vector<pair<Range,int> > q[N];
void Add(int l1,int r1,int l2,int r2){
	if(l1>r1||l2>r2)return;
	c[l1].emplace_back(1,l2,r2);
	c[r1+1].emplace_back(-1,l2,r2);
}
void dfs(int u,int l,int r){
	if(!u)return;
	dfs(t[u].ch[0],l,u-1);
	dfs(t[u].ch[1],u+1,r);
	vector<pair<int,int> > A;
	for(auto x:fac[a[u]]){
		if(1LL*x*x>=a[u])continue;
		int y=a[u]/x;
		int px=p[x],py=p[y];
		if(px>py)swap(px,py);
		if(px>=l&&px<=r&&py>=l&&py<=r){
			A.emplace_back(px,py);
		}
	}
	sort(A.begin(),A.end(),greater<pair<int,int> >());
	int re=r+1;
	
	for(int i=0;i<(int)A.size();++i){
		re=min(re,A[i].second);
		int nxt=(i==(int)A.size()-1?1:A[i+1].first+1);
		Add(max(l,nxt),min(u,A[i].first),max(u,re),r);
	}
}
class Segment_Tree{
public:
	int Len;
	struct node{
		ll sum;
		int len,tot;
		int cov;
		int add1,add2;
		inline void Add1(int d){
			sum+=len*d;
			add1+=d;
		} 
		inline void Add2(int d){
			sum+=tot*d;
			if(cov)add1+=d;
			else add2+=d;
		}
	}t[N<<3];
	#define ls u<<1
	#define rs u<<1|1
	inline void pushdown(int u){
		if(t[u].add1){
			t[ls].Add1(t[u].add1);
			t[rs].Add1(t[u].add1);
			t[u].add1=0;
		}
		if(t[u].add2){
			t[ls].Add2(t[u].add2);
			t[rs].Add2(t[u].add2);
			t[u].add2=0;
		}
	}
	inline void update(int u){
		t[u].sum=t[ls].sum+t[rs].sum;
		t[u].len=t[ls].len+t[rs].len;
		if(t[u].cov){
			t[u].tot=t[u].len;
		}
		else{
			t[u].tot=t[ls].tot+t[rs].tot;
		}
	}
	void build(int u,int L,int R){
		if(L==R){
			t[u].len=1;
			t[u].sum=0;
			return;
		}
		int mid=(L+R)>>1;
		build(ls,L,mid);
		build(rs,mid+1,R);
		update(u);
	}
	void _adt(int u,int L,int R,int l,int r,int w){
		if(L>=l&&R<=r){
			pushdown(u);
			t[u].cov= w==1;
			if(t[u].cov){
				t[u].tot=t[u].len;
			}
			else{
				t[u].tot=t[ls].tot+t[rs].tot;
			}
			return;
		}
		pushdown(u);
		int mid=(L+R)>>1;
		if(l<=mid)_adt(ls,L,mid,l,r,w);
		if(r>mid)_adt(rs,mid+1,R,l,r,w);
		update(u);
	}
	ll _query(int u,int L,int R,int l,int r){
		if(L>=l&&R<=r){
			return t[u].sum;
		}
		pushdown(u);
		int mid=(L+R)>>1;
		ll tot=0;
		if(l<=mid)tot+=_query(ls,L,mid,l,r);
		if(r>mid)tot+=_query(rs,mid+1,R,l,r);
		return tot;
	}
	void init(int _n){
		Len=_n;
		build(1,1,Len);
	}
	ll Query(int l,int r){
		return _query(1,1,Len,l,r);
	}
	void Adt(int l,int r,int w){
		_adt(1,1,Len,l,r,w);
	}
}T;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>Q;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		p[a[i]]=i;
	}
	static int st[N],top;
	for(int i=1;i<=n;++i){
		while(top&&a[i]>a[st[top]])t[i].ch[0]=st[top--];
		if(top)t[st[top]].ch[1]=i;
		st[++top]=i;
	}
	for(int i=1;i<=n;++i){
		for(int j=i;j<=n;j+=i){
			fac[j].push_back(i);
		}
	}
	dfs(st[1],1,n);
	for(int i=1;i<=Q;++i){
		int l,r;
		cin>>l>>r;
		q[r].emplace_back(Range(1,l,r),i);
		q[l-1].emplace_back(Range(-1,l,r),i);
	}
	T.init(n);
	for(int i=1;i<=n;++i){
		for(auto [op,l,r]:c[i]){
			if(op==-1){
				T.Adt(l,r,op);
			}
		}
		for(auto [op,l,r]:c[i]){
			if(op==1){
				T.Adt(l,r,op);
			}
		}
		T.t[1].Add2(1);
		for(auto [H,id]:q[i]){
			auto [op,l,r]=H;
			ans[id]+=op*T.Query(l,r);
		}
	}
	for(int i=1;i<=Q;++i){
		cout<<ans[i]<<'\n';
	}
	return 0;
}