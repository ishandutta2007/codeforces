#include<bits/stdc++.h>
#define ri register int
#define pb push_back
#define fi first
#define se second
using namespace std;
const int rlen=1<<18|1;
inline char gc(){
	static char buf[rlen],*ib,*ob;
	(ib==ob)&&(ob=(ib=buf)+fread(buf,1,rlen,stdin));
	return ib==ob?-1:*ib++;
}
inline int read(){
	int ans=0;
	char ch=gc();
	while(!isdigit(ch))ch=gc();
	while(isdigit(ch))ans=((ans<<2)+ans<<1)+(ch^48),ch=gc();
	return ans;
}
typedef long long ll;
typedef pair<int,int> pii;
const int N=3e5+5;
int n,k,len[N],m=0;
pii a[N];
struct Node{
	Node(int l=0,int r=0,int c=0):l(l),r(r),c(c){}
	int l,r,c;
	inline int len()const{return r-l+1;}
	friend inline bool operator<(Node a,Node b){return a.l^b.l?a.l<b.l:a.r<b.r;}
};
vector<Node>ff[N];
set<Node>S;
typedef set<Node>::iterator It;
inline void init(){
	S.insert(Node(1,m,0));
	for(ri i=1;i<=n;++i){
		It it=S.lower_bound(Node(a[i].fi,m+1,i));
		--it;
		if(a[i].se<=it->r){
			ff[i].pb(Node(a[i].fi,a[i].se,it->c));
			if(it->l<a[i].fi)S.insert(Node(it->l,a[i].fi-1,it->c));
			if(it->r>a[i].se)S.insert(Node(a[i].se+1,it->r,it->c));
			S.erase(it);
			S.insert(Node(a[i].fi,a[i].se,i));
		}
		else{
			ff[i].pb(Node(a[i].fi,it->r,it->c));
			if(it->l<a[i].fi)S.insert(Node(it->l,a[i].fi-1,it->c));
			S.erase(it);
			it=S.lower_bound(Node(a[i].fi,m+1,i));
			while(it!=S.end()&&it->r<=a[i].se)ff[i].pb(*it),S.erase(it++);
			if(it!=S.end()&&it->l<=a[i].se){
				ff[i].pb(Node(it->l,a[i].se,it->c));
				S.insert(Node(a[i].se+1,it->r,it->c));
				S.erase(it);
			}
			S.insert(Node(a[i].fi,a[i].se,i));
		}
	}
}
inline bool check(int lim){
	int ss=0;
	ll cnt=0;
	for(ri l=1,i=1;i<=n;++i){
		ss+=(len[i]=a[i].se-a[i].fi+1);
		for(ri j=ff[i].size()-1;~j;--j){
			len[ff[i][j].c]-=ff[i][j].len();
			if(ff[i][j].c>=l)ss-=ff[i][j].len();
		}
		while(ss>=lim)ss-=len[l++];
		cnt+=l-1;
	}
	return cnt>=k;
}
inline ll solve(int lim){
	int ss=0;
	ll cnt=0,nowss=0,res=0;
	for(ri l=1,i=1;i<=n;++i){
		ss+=(len[i]=a[i].se-a[i].fi+1);
		for(ri j=ff[i].size()-1;~j;--j){
			len[ff[i][j].c]-=ff[i][j].len();
			if(ff[i][j].c>=l)ss-=ff[i][j].len();
			if(ff[i][j].c&&ff[i][j].c<l)nowss-=(ll)ff[i][j].len()*ff[i][j].c;
		}
		while(ss>=lim)ss-=len[l],nowss+=(ll)l*len[l],++l;
		res+=nowss+(ll)ss*(l-1);
		cnt+=l-1;
	}
	return res-(cnt-k)*lim;
}
int main(){
	#ifdef ldxcaicai
	freopen("lx.in","r",stdin);
	#endif
	n=read(),k=read();
	for(ri i=1;i<=n;++i)a[i].fi=read(),m=max(m,a[i].se=read()-1);
	init();
	int l=0,r=m,res=0;
	while(l<=r){
		int mid=l+r>>1;
		if(check(mid))l=mid+1,res=mid;
		else r=mid-1;
	}
	cout<<solve(res);
	return 0;
}