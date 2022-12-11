#include<iostream>
#include<cstdio>
#include<set>
#include<map>
#define IT set<node>::iterator
using namespace std;
typedef long long ll;
int n,m,seed,vm;
struct node{
	int l,r;
	mutable ll v;
	node(){}
	node(int a,int b,ll c){l=a;r=b;v=c;}
	bool operator <(node b)const{
		return l<b.l;
	}
};
set<node> s;
ll qpow(ll x,ll k,ll mod){
	ll res=1;
	while(k){
		if(k&1)res=res*x%mod;
		x=x*x%mod;
		k>>=1;
	}
	return res;
}
int rnd(){
	int ret=seed;
	seed=(seed*7ll+13)%1000000007;
	return ret;
}
IT split(int pos){
	IT p=s.upper_bound(node(pos,0,0));
	p--;
	if(p->l==pos)return p;
	int L=p->l,R=p->r;
	ll V=p->v;
	s.erase(p);
	s.insert(node(L,pos-1,V));
	return s.insert(node(pos,R,V)).first;
}
void cover(int l,int r,int val){
	IT lp=split(l),rp=split(r+1);
	s.erase(lp,rp);
	s.insert(node(l,r,val));
}
void add(int l,int r,int val){
	IT lp=split(l),rp=split(r+1);
	for(;lp!=rp;lp->v+=val,lp++);
}
ll rk(int l,int r,int k){
	map <ll,int> mp;
	mp.clear();
	IT lp=split(l),rp=split(r+1);
	for(;lp!=rp;lp++)
		mp[lp->v]+=lp->r-lp->l+1;
	map<ll,int>::iterator mit;
	pair<ll,int> p;
	mit=mp.begin();
	for(;mit!=mp.end();mit++){
		p=*mit;
		if(k<=p.second)
			return p.first;
		else k-=p.second;
	}
	return -1ll;
}
ll query(int l,int r,int k,int mod){
	IT lp=split(l),rp=split(r+1);
	ll res=0;
	for(;lp!=rp;lp++)
		res=(res+(lp->r-lp->l+1)*qpow(lp->v%mod,k,mod)%mod)%mod;
	return res;
}
inline int read(){
	int res=0;
	char ch=getchar(),ch1=ch;
	while(!isdigit(ch))ch1=ch,ch=getchar();
	while(isdigit(ch))res=(res<<3)+(res<<1)+ch-'0',ch=getchar();
	return ch1=='-'?-res:res;
}
int main(){
	n=read();m=read();seed=read();vm=read();
	for(register int i=1;i<=n;++i)
		s.insert(node(i,i,(rnd()%vm)+1));
	s.insert(node(n+1,n+1,0));
	for(register int i = 1,op,l,r,x,y;i<=m;++i){
		op=(rnd()%4)+1;
    	l=(rnd()%n)+1;
    	r=(rnd()%n)+1;
		if (l > r)
        	swap(l, r);
	    if (op == 3)
	        x=(rnd()%(r - l + 1))+1;
	    else
	        x=(rnd()%vm)+1;
	    if (op == 4)
	        y=(rnd()%vm)+1;
	    if(op==1)
	    	add(l,r,x);
	    else if(op==2)
	    	cover(l,r,x);
	    else if(op==3)
	    	printf("%lld\n",rk(l,r,x));
	    else
	    	printf("%lld\n",query(l,r,x,y));
	}
	return 0;
}