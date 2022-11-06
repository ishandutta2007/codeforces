#include<bits/stdc++.h>
#define ri register int
#define fi first
#define se second
using namespace std;
const int rlen=1<<18|1;
char buf[rlen],*ib=buf,*ob=buf;
#define gc() (((ib==ob)&&(ob=(ib=buf)+fread(buf,1,rlen,stdin)),ib==ob)?-1:*ib++)
typedef pair<int,int> pii;
inline int read(){
	int ans=0;
	char ch=gc();
	while(!isdigit(ch))ch=gc();
	while(isdigit(ch))ans=((ans<<2)+ans<<1)+(ch^48),ch=gc();
	return ans;
}
const int N=2005;
bitset<N>vl[N],tp[N];
int n,m,q;
set<pii>S,ans;
typedef set<pii>::iterator It;
inline bool check(int a,int b){
	if(!a||a==n+1)return 0;
	if(!b||b==n+1)return 0;
	if((vl[a]|vl[b])==vl[a])return 0;
	if((vl[b]|vl[a])==vl[b])return 0;
	return 1;
}
inline void modify1(int x){
	S.insert(pii(vl[x].count(),x));
	It it=S.lower_bound(pii(vl[x].count(),x)),ia=it,ib=it;
	--ia;
	if(check(ia->se,x))ans.insert(pii(ia->se,x));
	++ib;
	if(check(ib->se,x))ans.insert(pii(x,ib->se));
	if(check(ia->se,ib->se))ans.erase(pii(ia->se,ib->se));
}
inline void modify2(int x){
	It it=S.lower_bound(pii(vl[x].count(),x)),ia=it,ib=it;
	--ia;
	if(check(ia->se,x))ans.erase(pii(ia->se,x));
	++ib;
	if(check(ib->se,x))ans.erase(pii(x,ib->se));
	if(check(ia->se,ib->se))ans.insert(pii(ia->se,ib->se));
	S.erase(it);
}
int main(){
	#ifdef ldxcaicai
	freopen("lx.in","r",stdin);
	freopen("biao.out","w",stdout);
	#endif
	n=read(),m=read(),q=read();
	S.insert(pii(-1,0));
	for(ri i=1;i<=n;++i)S.insert(pii(0,i));
	S.insert(pii(m+1,n+1));
	for(ri i=1;i<=m;++i)tp[i].set(i-1),tp[i]|=tp[i-1];
	for(ri a,b,l,r,i=1;i<=q;++i){
		a=read(),l=read(),r=read();
		modify2(a);
		vl[a]^=(tp[r-l+1]<<l);
		modify1(a);
		if(ans.size()){
			a=ans.begin()->fi,b=ans.begin()->se;
			l=(vl[a]&~vl[b])._Find_first(),r=(~vl[a]&vl[b])._Find_first();
			if(a>b)swap(a,b);
			if(l>r)swap(l,r);
			cout<<a<<' '<<l<<' '<<b<<' '<<r<<'\n';
		}
		else puts("-1");
	}
	return 0;
}