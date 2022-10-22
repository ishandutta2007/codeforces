#include<bits/stdc++.h>
#define For(i,a,b) for(int i=a,i##end=b;i<=i##end;i++)
#define Rof(i,a,b) for(int i=a,i##end=b;i>=i##end;i--)
#define rep(i,  b) for(int i=1,i##end=b;i<=i##end;i++)
using namespace std;
const int N=5e5+9;
//char buf[(1<<21)+5],*p1,*p2;
//#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
void chmx(int &x,int y){(x<y)&&(x=y);}
void chmn(int &x,int y){(x>y)&&(x=y);}
int read(){
	int f=0,x=0;
	char ch=getchar();
	while(!isdigit(ch)){f|=(ch=='-');ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return f?-x:x;
}
int n,a[N];
int last[N],nt[N],pre[N];
int mn[N<<2],cnt[N<<2],tag[N<<2];
struct tree{
	#define ls (p<<1)
	#define rs (p<<1|1)
	void f(int p,int t){mn[p]+=t;tag[p]+=t;}
	void push_down(int p){
		if(!tag[p])return;
		f(ls,tag[p]);f(rs,tag[p]);
		tag[p]=0;return;
	}
	void push_up(int p){
		mn[p]=min(mn[ls],mn[rs]);
		cnt[p]=(mn[p]==mn[ls]?cnt[ls]:0)+(mn[p]==mn[rs]?cnt[rs]:0);
	}
	void build(int p,int l,int r){
		if(l==r){cnt[p]=1;return;}
		int mid=(l+r)>>1;
		build(ls,l,mid);build(rs,mid+1,r);
		push_up(p);
		return ;
	}
	void add(int p,int l,int r,int nl,int nr,int v){
		if(nl>nr)return;
		if(nl<=l&&r<=nr){mn[p]+=v;tag[p]+=v;return;}
		int mid=(l+r)>>1;push_down(p);
		if(mid>=nl)add(ls,l,mid,nl,nr,v);
		if(mid<nr)add(rs,mid+1,r,nl,nr,v);
		push_up(p);
	}
}T;
signed main(){
//	printf("%.5lf\n",(&pppp-&ppp)/1024.0/1024.0);
	n=read();rep(i,n)a[i]=read();
	rep(i,n){
		if(last[a[i]])nt[last[a[i]]]=i;
		pre[i]=last[a[i]];
		last[a[i]]=i;
	}
	rep(i,n)if(last[i])nt[last[i]]=n+1;
	T.build(1,1,n);
	rep(i,n)if(!pre[i]){
		T.add(1,1,n,1,n,1);
		T.add(1,1,n,1,i-1,-1);
		int x=nt[nt[i]];
		if(!nt[x])continue;
		else T.add(1,1,n,x,nt[x]-1,-1);
	}
	long long ans=0;
	rep(i,n){
		if(mn[1]==0)ans+=cnt[1];
		T.add(1,1,n,pre[i]+1,i-1,1);
		T.add(1,1,n,i+1,nt[i]-1,-1);
		int x=nt[nt[i]];
		if(!nt[x]);
		else T.add(1,1,n,x,nt[x]-1,1);
		x=nt[x];
		if(!nt[x]);
		else T.add(1,1,n,x,nt[x]-1,-1) ;
		
		T.add(1,1,n,i,i,1e9);
	}cout<<ans<<endl;
	return 0;
}