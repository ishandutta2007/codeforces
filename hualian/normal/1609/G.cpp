#include<bits/stdc++.h>
#define For(i,a,b) for(int i=a,i##end=b;i<=i##end;i++)
#define Rof(i,a,b) for(int i=a,i##end=b;i>=i##end;i--)
#define rep(i,  a) for(int i=1,i##end=a;i<=i##end;i++)
using namespace std;
const int N=1e5+9;
//char buf[(1<<21)+5],*p1,*p2;
//#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
void chmx(int &x,int y){(x<y)?(x=y):(0);}
void chmn(int &x,int y){(x>y)?(x=y):(0);}
inline long long read(){
	long long f=0,x=0;
	char ch=getchar();
	while(!isdigit(ch)){f|=(ch=='-');ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return f?-x:x;
}
int n,m,q;
long long ans;
long long a[N],b[N];
int son[N][2],sz[N],tag[N],idx,rt;
long long sum[N],val[N];
long long rd[N];
int now=0,SZ;
long long VAL;
struct treap{
	#define ls son[p][0]
	#define rs son[p][1]
	inline int clone(long long v){
		val[++idx]=sum[idx]=v;
		rd[idx]=1ll*rand()*rand();
		sz[idx]=1;tag[idx]=0;
		return idx;
	}
	void f(int p,int tg){
		if(!p)return;
		val[p]+=tg;
		sum[p]+=1ll*sz[p]*tg;
		tag[p]+=tg;
	}	
	void push_down(int p){
		if(!tag[p])return;
		f(ls,tag[p]);f(rs,tag[p]);
		tag[p]=0;return;
	}
	void push_up(int &p){
		sz[p]=sz[ls]+sz[rs]+1;
		sum[p]=sum[ls]+sum[rs]+val[p];
		return;
	}
	void build(int &p,int l,int r){
		if(l>r)return;
		int mid=(l+r)>>1;
		now=mid;p=clone(b[mid]);
		build(ls,l,mid-1);build(rs,mid+1,r);
		push_up(p);
	}
	void split_s(int p,int &x,int &y,int k){
		if(!p){x=y=0;return;}
		push_down(p);
		if(sz[ls]+1<=k)x=p,split_s(rs,rs,y,k-sz[ls]-1);
		else y=p,split_s(ls,x,ls,k);
		push_up(p);
	}
	void getv(int p,long long &k){
		if(!p){return;}
		push_down(p);
		if(val[p]<=k)SZ+=sz[ls]+1,VAL+=sum[ls]+val[p],getv(rs,k);
		else getv(ls,k);
		push_up(p);
	}
	int merge(int p1,int p2){
		if(p1*p2==0)return p1|p2;
		push_down(p1);push_down(p2);
		if(rd[p1]<rd[p2]){son[p1][1]=merge(son[p1][1],p2);push_up(p1);return p1;}
		else {son[p2][0]=merge(p1,son[p2][0]);push_up(p2);return p2;}
	}
	void add(int k,int d){
		int a,b;
		split_s(rt,a,b,k);
		f(b,d);
		rt=merge(a,b);
	}
	long long find(long long v,int rk){
		int a,b;
		SZ=0,VAL=0;
		getv(rt,v);
		return VAL+1ll*(m-1-SZ+n-rk+1)*v;
	}	
}T;
long long all=0;
long long get(int l,int r){return 1ll*(l+r)*(r-l+1)/2;}
signed main(){ 
//	printf("%.5lf",(&pppp-&ppp)/1024.0/1024.0);
	srand(time(0));
	n=read(),m=read();q=read();
	rep(i,n)a[i]=read();rep(i,m)b[i]=read();
	Rof(i,n,1)a[i]-=a[i-1];Rof(i,m,1)b[i]-=b[i-1];
	For(i,2,m)all+=b[i]*(m-i+1);
	T.build(rt,2,m);
	while(q--){
		int op=read(),k=read(),d=read();
		if(op==2){
			k=m-1-k;
			if(k==-1)k=0,b[1]+=d;
			all+=1ll*get(1,m-1-k)*d;
			T.add(k,d);
		}//k 
		else For(i,n-k+1,n)a[i]+=d;
		ans=0;
		For(i,2,n)ans+=T.find(a[i],i);
		ans+=1ll*(n+m-1)*(a[1]+b[1]);
		printf("%lld\n",ans+all);
	}
	return 0;
}