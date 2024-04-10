#include<bits/stdc++.h>
#define ri register int
#define pb push_back
#define fi first
#define se second
using namespace std;
const int rlen=1<<18|1;
char buf[rlen],*ib=buf,*ob=buf;
#define gc() (((ib==ob)&&(ob=(ib=buf)+fread(buf,1,rlen,stdin)),ib==ob)?-1:*ib++)
typedef long long ll;
typedef pair<int,int> pii;
int mod;
inline int add(int a,int b){return (a+=b)<mod?a:a-mod;}
inline void Add(int&a,int b){a=add(a,b);}
inline int dec(int a,int b){return (a-=b)<0?a+mod:a;}
inline void Dec(int&a,int b){a=dec(a,b);}
inline int mul(int a,int b){return (ll)a*b%mod;}
inline void Mul(int&a,int b){a=(ll)a*b%mod;}
inline int ksm(int a,int p){int ret=1;for(;p;p>>=1,Mul(a,a))(p&1)&&(Mul(ret,a),1);return ret;}
inline int read(){
	int ans=0;
	char ch=gc();
	while(!isdigit(ch))ch=gc();
	while(isdigit(ch))ans=((ans<<2)+ans<<1)+(ch^48),ch=gc();
	return ans;
}
const int N=2e5+5;
int n;
struct Node{
	int l,r,id;
	friend inline bool operator<(Node a,Node b){return a.r^b.r?a.r<b.r:a.l<b.l;}
}a[N];
int ans[N],vl[N<<1],sig;
inline int find(int x){return lower_bound(vl+1,vl+sig+1,x)-vl;}
pii stk[N];
int top=0,tot=0;
inline void insert(int l,int r){
	++tot;
	int idl=tot,idr=tot;
	while(top){
		if(l>a[stk[top].se].r)break;
		if(l>=a[stk[top].fi].l){
			stk[top].se=tot;
			return;
		}
		idl=stk[top].fi;
		--top;
	}
	stk[++top]=pii(idl,idr);
}
int main(){
	#ifdef ldxcaicai
	freopen("lx.in","r",stdin);
	#endif
	for(ri tt=read();tt;--tt){
		n=read();
		sig=0;
		for(ri i=1;i<=n;++i)vl[++sig]=a[i].l=read(),vl[++sig]=a[i].r=read();
		sort(vl+1,vl+sig+1);
		sig=unique(vl+1,vl+sig+1)-vl-1;
		for(ri i=1;i<=n;++i)a[i].l=find(a[i].l),a[i].r=find(a[i].r),a[i].id=i;
		sort(a+1,a+n+1);
		top=tot=0;
		for(ri i=1;i<=n;++i)insert(a[i].l,a[i].r);
		if(top==1){
			cout<<-1;
		}
		else{
			for(ri i=1;i<=top;++i){
				for(ri j=stk[i].fi;j<=stk[i].se;++j){
					ans[a[j].id]=2-(i&1);
				}
			}
			for(ri i=1;i<=n;++i)cout<<ans[i]<<' ';
		}
		puts("");
	}
	return 0;
}