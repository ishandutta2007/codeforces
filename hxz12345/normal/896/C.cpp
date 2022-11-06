#include<bits/stdc++.h>
using namespace std;
inline long long read()
{
  long long x=0,f=1;char ch=getchar();
  while(!isdigit(ch)&&ch!='-')ch=getchar();
  if(ch=='-')f=-1,ch=getchar();
  while(isdigit(ch))x=(x<<1)+(x<<3)+ch-'0',ch=getchar();
  return x*f;
}
#define IT set<node>::iterator
vector<pair<long long,int>> V;
struct node{
	long long l,r;
	mutable long long v;
	node (long long lft,long long rit=-1,long long val=0) : l(lft),r(rit),v(val) {}
	bool operator < (const node &x) const{return l<x.l;}
};
set<node> G;
long long x,y;
long long Q,i,a[1001010],opt,l,r,n,m,seed,vmax;
int cas;
long long rnd(){
	long long ret=seed;
	seed=(seed*7+13) % 1000000007;return ret;
}
IT split(long long x){
	IT it=G.lower_bound(node(x));
	if ((it!=G.end())&&(it->l==x)) return it;
	it--;
	if (it->r<x) return G.end();
	long long lft=it->l,rit=it->r,val=it->v;
	G.erase(it);G.insert(node(lft,x-1,val));
	return G.insert(node(x,rit,val)).first;
}
void add(int l,int r,long long val){
	IT itr=split(r+1),itl=split(l);
	for (;itl!=itr;itl++) itl->v+=val;
}
void assign(int l,int r,long long val){
	IT itr=split(r+1),itl=split(l);
	G.erase(itl,itr);
	G.insert(node(l,r,val));
}
void findk(int l,int r){
	IT itr=split(r+1),itl=split(l);
	V.clear();
	for (;itl!=itr;itl++) V.push_back(make_pair(itl->v,itl->r-itl->l+1));
	sort(V.begin(),V.end());
	for (int i=0;i<V.size();i++){
		x-=V[i].second;
		if (x<=0) {printf("%lld\n",V[i].first);return ;}
	}
}
long long pow(long long x,long long y,long long p){
	long long ans=1;for (;y;y>>=1,x=x*x % p)if (y&1) ans=ans*x % p;return ans;
}
void findp(int l,int r){
	IT itl=split(l),itr=split(r+1);
	long long ans=0;
	for (;itl!=itr;itl++) 
		ans=(ans+pow(itl->v % y,x,y)*(itl->r-itl->l+1)) % y;
	printf("%lld\n",ans);
}
int main()
{
	n=read();Q=read();seed=read();vmax=read();
	for (int i=1;i<=n;i++) a[i]=(rnd() % vmax)+1;
	for (i=1;i<=n;i++) G.insert(node(i,i,a[i]));
	for (;Q;Q--){
		
		opt=rnd() % 4+1;l=rnd() % n+1;r=rnd() % n+1;
		if (l>r) swap(l,r);
		if (opt==3) x=(rnd() % (r-l+1))+1;
		else x=(rnd() % vmax)+1;
		if (opt==4) y=(rnd() % vmax)+1;
		if (opt==1) add(l,r,x);
		if (opt==2) assign(l,r,x);
		if (opt==3) findk(l,r);
		if (opt==4) findp(l,r);
	}
	return 0;
}