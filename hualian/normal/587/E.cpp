#include<bits/stdc++.h>
#define lowbit(x) (x&-x)
#define For(i,a,b) for(register int i=a,i##end=b;i<=i##end;i++)
#define Rof(i,a,b) for(register int i=a,i##end=b;i>=i##end;i--)
#define rep(i,  a) for(register int i=1,i##end=a;i<=i##end;i++)
using namespace std;
const int N=6e5+9;
void chmx(int &x,int y){(x<y)?(x=y):(0);}
void chmn(int &x,int y){(x>y)?(x=y):(0);}
char In[1<<20],*Ss=In,*Tt=In;
//#define getchar() (Ss==Tt&&(Tt=(Ss=In)+fread(In,1,1<<20,stdin),Ss==Tt)?EOF:*Ss++)
inline int read(){
	int f=0,x=0;
	char ch=getchar();
	while(!isdigit(ch)){f|=(ch=='-');ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return f?-x:x;
}
int n,m,lim=1;
int w[N];
void add(int x,int v){while(x<=n)w[x]^=v,x+=lowbit(x);}
int get(int x,int res=0){while(x)res^=w[x],x-=lowbit(x);return res;}
struct node{
	int a[32],len;
	node(){memset(a,0,sizeof a);len=0;}
	void clear(){memset(a,0,sizeof a);len=0;}
	void insert(int x){
		if(len==32)return;
		Rof(i,31,0)if(x>>i){
			if(!a[i]){a[i]=x;len++;break;}
			x^=a[i];
		}
	}
	int get(int x){Rof(i,31,0)if(a[i]&&(((x>>i)&1)==0))x^=a[i];return x;}
	node operator+(const node&x)const{
		if(len==32)return (*this);
		if(x.len==32)return x;
		node c;c=x;
		For(i,0,31)if(a[i])c.insert(a[i]);
		return c;
	}
	void operator+=(const node&x){
		if(len==32)return;
		if(x.len==32){For(i,0,31)a[i]=x.a[i];return;}
		For(i,0,31)insert(x.a[i]);
	}
};
int a[N];
struct tree{
	node sum[N];
	void build(){
		while(lim<=n+1)lim<<=1;
		For(i,lim+1,lim+n)sum[i].insert(a[i-lim]);
		Rof(i,lim-1,1)sum[i]=sum[i<<1]+sum[i<<1|1];
	}
	void change(int x,int v){
		a[x]^=v;x+=lim;sum[x].clear();
		sum[x].insert(a[x-lim]);
		while(x>>=1)sum[x]=sum[x<<1]+sum[x<<1|1];
	}
	void find(int l,int r,node&res){
		l=lim+l-1;r=lim+r+1;
		while(l^r^1){
			if(~l&1)res+=sum[l^1];
			if( r&1)res+=sum[r^1];
			if(res.len==32)return;
			l>>=1;r>>=1;
		}
	}
}T;
long long p2[N];
signed main(){
//	printf("%.5lf",(&pppp-&ppp)/1024.0/1024.0);
	n=read(),m=read();
	p2[0]=1;rep(i,32)p2[i]=p2[i-1]*2;
	rep(i,n)a[i]=read();Rof(i,n,1)a[i]^=a[i-1];
	rep(i,n)add(i,a[i]);
	T.build();
	int l,r,op,v;node res;
	while(m--){
		op=read();
		switch(op){
			case 1:{
				l=read(),r=read(),v=read();
				add(l,v);add(r+1,v);
				T.change(l,v);if(r<n)T.change(r+1,v);
				break;
			}
			case 2:{
				l=read()+1,r=read();
				res.clear();res.insert(get(l-1));
				T.find(l,r,res);
				printf("%lld\n",p2[res.len]);
			}
		}
	}
	return 0;
}