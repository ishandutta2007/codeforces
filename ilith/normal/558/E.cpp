#include<bits/stdc++.h>
#define rgi register int
#define mid (l+r>>1)
#define iter set<node>::iterator
#define low lower_bound
#define upp upper_bound
using namespace std;
inline void read(){}template <typename T,typename... Ts> inline void read(T& A,Ts&... As){
	T x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	A=x*f,read(As...);
}
inline void write(char a){putchar(a);}
template <typename T> inline void write(T a){
	if(a<0ll)putchar('-'),a=-a;
	if(a>9ll)write(a/10ll);
	putchar(a%10ll+'0');
}
template <typename T,typename... Ts> inline void write(T A,Ts... As){write(A),write(As...);}
const int N=100010;
int n,m;
struct node{
	int l,r,id;
	bool operator<(node x)const{return l<x.l;}
};
set<node>s;
int ls[N<<7],rs[N<<7],rt[N<<5],st[N<<5],cnt,tot,sum[N<<7];
int q[N<<5],SZ;
inline int newnode(){
	return SZ?q[--SZ]:++cnt;
}
inline void del(int x){
	q[++SZ]=x,sum[x]=ls[x]=rs[x]=0;
}
int merge(int x,int y){
	if(!x||!y)return x^y;
	ls[x]=merge(ls[x],ls[y]),rs[x]=merge(rs[x],rs[y]);
	return sum[x]+=sum[y],/* del(y), */x;
}
void split(int x,int y,int k){
	if(!x||sum[x]==k)return;
	sum[y]=sum[x]-k,sum[x]=k;
	if(sum[ls[x]]>=k)swap(rs[x],rs[y]),split(ls[x],ls[y]=newnode(),k);
	else if(sum[ls[x]]+sum[rs[x]])split(rs[x],rs[y]=newnode(),k-sum[ls[x]]);
}
void upd(int& k,int l,int r,int x,int V){
	if(!k)k=newnode();
	if(r<x||l>x)return;
	if(r==x&&l==x)return void(sum[k]+=V);
	upd(ls[k],l,mid,x,V),upd(rs[k],mid+1,r,x,V);
	sum[k]=sum[ls[k]]+sum[rs[k]];
}
int ans[N],C;
void dfs(int k,int l,int r){
	if(!k)return;
	if(l==r){
		for(rgi i=0;i<sum[k];++i)ans[++C]=l;
		return ;
	}
	dfs(ls[k],l,mid),dfs(rs[k],mid+1,r);
}
inline void out(){
	C=0;
	for(iter it=s.begin();it!=s.end();++it){
		node p=*it;
		int now=C;
		dfs(rt[p.id],1,30);
		if(st[p.id])reverse(ans+now+1,ans+C+1);
	}
	for(rgi i=1;i<=C;++i)printf("%c",ans[i]+'a'-1);
}
inline void solve(node p,int x){
	int id=p.id;
	split(rt[id],rt[++tot]=newnode(),st[id]?p.r-x+1:x-p.l),st[tot]=st[id];
	if(st[id])swap(rt[id],rt[tot]);
	s.erase(p),s.insert(node{p.l,x-1,id}),s.insert(node{x,p.r,tot});
}
char S[N];
int l,r,opt;
signed main(){
	read(n,m),tot=n;
	scanf("%s",S+1);
	for(rgi i=1;i<=n;++i)l=S[i]-'a'+1,upd(rt[i],1,30,l,1),s.insert(node{i,i,i});
	while(m--){
		read(l,r,opt),opt^=1;
		node p;
		if(l!=1){
			p=*(--s.low(node{l,0,0}));
			if(p.r>=l)solve(p,l);
		}
		if(r!=n){
			p=*(--s.low(node{r+1,0,0}));
			if(p.r>r)solve(p,r+1);
		}
		iter res=s.low(node{l,0,0});
		st[(p=*res).id]=opt,p.r=r;
		for(iter it=s.upp(node{l,0,0});it!=s.end()&&(*it).r<=r;s.erase(it),it=s.upp(node{l,0,0})){
			merge(rt[p.id],rt[(*it).id]);
		}
		s.erase(res),s.insert(p);
	}out();
	return 0;
}