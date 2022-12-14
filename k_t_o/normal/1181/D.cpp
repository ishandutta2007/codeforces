#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("avx") 
#include<bits/stdc++.h>
using namespace std;

inline int read()
{
	int ret=0; char c=getchar();
	while(c<48||c>57)c=getchar();
	while(c>=48 && c<=57)ret=ret*10+c-48,c=getchar();
	return ret;
}

#define N 500006
#define M 16000007
struct node {
	long long d;
	int id;
	node (long long a=0,int b=0) {
		d=a; id=b;
	}
	bool operator < (const node &a)const {
		return d<a.d;
	}
}Q[N];

set<int>s;
int u,g[N],ans[N],n,m,q,pp,p,w,r,aa,ss,cnt,rt[N];
int si[M],ls[M],rs[M];
long long dd,ee,o;

void insert(int &p, int k, int l, int r)
{
	if(!p)p=++cnt;
	++si[p];
	if(l==r)return;
	int mi=(l+r)>>1; 
	if(k<=mi)insert(ls[p],k,l,mi);
	else insert(rs[p],k,mi+1,r);
}

int qu(int p, int l, int r, int k)
{
	if(l==r)return l;
	int mi=(l+r)>>1;
	if(si[ls[p]]>=k)return qu(ls[p],l,mi,k);
	return qu(rs[p],mi+1,r,k-si[ls[p]]);
}

int mer(int p, int p_, int l, int r)
{
	if(!p)return p_;
	if(!p_)return p;
	if(l==r){
		si[p]+=si[p_];
		return p;
	}
	int mi=(l+r)>>1;
	ls[p]=mer(ls[p],ls[p_],l,mi);
	rs[p]=mer(rs[p],rs[p_],mi+1,r);
	si[p]=si[ls[p]]+si[rs[p]];
	return p;
}

int main()
{
	m=read();n=read();q=read();
	for(int i=1;i<=m;++i){
		p=read(); 
		++g[p];
	}
	for(int i=1;i<=n;++i){
		insert(rt[g[i]],i,1,n);
		s.insert(g[i]);
	}
	pp=*(--s.end());
	for(int i=1;i<=q;++i){
		long long cyb;scanf("%lld",&cyb);
		Q[i]=(node){cyb-m,i};
	}
	sort(Q+1,Q+q+1); u=1;
	for(set<int>::iterator it=s.begin(); it!=s.end();++it){
		w=*it;if(w==pp)break;
//		r=*(++it);
		set<int>::iterator it_=it; ++it_;
		r=*it_;  ///bian s    it shixiao
//		cerr<<w<<' '<<r<<endl;
		
		aa=r-w; ss=si[rt[w]];
		ee=dd+(long long)aa*ss;
		while(u<=q&&Q[u].d<=ee){
			o=Q[u].d-dd;
			o%=ss;if(!o)o=ss;
			ans[Q[u].id]=qu(rt[w],1,n,o);
			++u;
		}
		rt[r]=mer(rt[w],rt[r],1,n);
		dd=ee;
	}
//	cerr<<'*'<<dd<<endl;
	for(int i=u;i<=q;++i){
		o=Q[i].d-dd;
//		cerr<<i<<' '<<o<<endl;
		o%=n;if(!o)o=n;
		ans[Q[i].id]=o;   ///
	}
	for(int i=1;i<=q;++i)printf("%d\n",ans[i]);
}
/*
4 5 1
4 4 5 1
15
*/