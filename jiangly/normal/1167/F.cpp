// remote judge by luogu
// the 9th submit
// please no UKE
#include<bits/stdc++.h>
typedef long long ll,int64,LL;
const int inf=1e9;
namespace FastIO{
	const int BUF_SIZE=1<<24;
	char buf[BUF_SIZE],*p1,*p2;
	inline char gc(){
		return p1==p2?p2=(p1=buf)+fread(buf,1,BUF_SIZE,stdin):0,p1==p2?-1:*p1++;
	}
	inline int read_int(){
		int ans=0;
		char c=gc();
		bool sign=0;
		for(;(~c)&&!isdigit(c);c=gc())
			sign=(c=='-');
		for(;isdigit(c);c=gc())
			ans=(ans<<3)+(ans<<1)+(c^'0');
		if(sign)
			ans=-ans;
		return ans;
	}
	inline char read_char(){
		char c=gc();
		for(;isspace(c);)
			c=gc();
		return c;
	}
	inline int read_string(char*p){
		char*q=p;
		char c=gc();
		for(;isspace(c);c=gc());
		for(;(~c)&&!isspace(c);c=gc())
			*q++=c;
		*q=0;
		return q-p;
	}
}
using namespace FastIO;
namespace algo{
	template<class T>inline const T&min(const T&a,const T&b){
		return a<b?a:b;
	}
	template<class T>inline const T&max(const T&a,const T&b){
		return a>b?a:b;
	}
	template<class T>inline void swap(T&a,T&b){
		T c=a;
		a=b;
		b=c;
	}
	int gcd(int a,int b){
		return b?gcd(b,a%b):a;
	}
	inline int sq(int x){
		return x*x;
	}
}
using namespace algo;
const int MAXN=500000,P=1e9+7;
int n;
int a[MAXN+1],tp[MAXN+1];
namespace seg{
	typedef struct seg_node{
		seg_node*lc,*rc;
		int l,r,tag,sum;
	}node;
	int tot_node;
	node node_pool[MAXN<<1];
	node*rt;
	node*new_node(int l,int r){
		node*p=node_pool+tot_node++;
		p->l=l;
		p->r=r;
		return p;
	}
	void build(node*p){
		if(p->l==p->r)
			return;
		int mid=p->l+p->r>>1;
		p->lc=new_node(p->l,mid);
		p->rc=new_node(mid+1,p->r);
		build(p->lc);
		build(p->rc);
	}
	void add(node*p,int x){
		p->tag+=x;
		p->sum=(p->sum+1ll*x*(p->r-p->l+1))%P;
	}
	void push_down(node*p){
		if(!p->tag)
			return;
		add(p->lc,p->tag);
		add(p->rc,p->tag);
		p->tag=0;
	}
	void build(){
		rt=new_node(1,n);
		build(rt);
	}
	void update(node*p){
		p->sum=(p->lc->sum+p->rc->sum)%P;
	}
	void add_range(node*p,int l,int r,int x){
		if(p->l>=l&&p->r<=r)
			return add(p,x);
		if(p->l>r||p->r<l)
			return;
		push_down(p);
		add_range(p->lc,l,r,x);
		add_range(p->rc,l,r,x);
		update(p);
	}
	int query_sum(node*p,int l,int r){
		if(p->l>=l&&p->r<=r)
			return p->sum;
		if(p->l>r||p->r<l)
			return 0;
		push_down(p);
		return (query_sum(p->lc,l,r)+query_sum(p->rc,l,r))%P;
	}
}
bool cmp(int i,int j){
	return a[i]<a[j];
}
void solve(){
	n=read_int();
	for(int i=1;i<=n;++i)
		a[i]=read_int();
	for(int i=1;i<=n;++i)
		tp[i]=i;
	std::sort(tp+1,tp+n+1,cmp);
	seg::build();
	int ans=0;
	for(int i=1;i<=n;++i){
		int x=tp[i];
		seg::add_range(seg::rt,x,n,1);
		ans=(ans+(1ll*x*seg::query_sum(seg::rt,x,n)%P-(x?1ll*(n-x+1)*seg::query_sum(seg::rt,1,x-1)%P:0)+P)%P*a[x])%P;
	}
	printf("%d\n",ans);
}
int main(){
	solve();
	return 0;
}