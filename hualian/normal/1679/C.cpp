#include<bits/stdc++.h>
#define int long long
#define For(i,a,b) for(int i=a,i##end=b;i<=i##end;i++)
#define Rof(i,a,b) for(int i=a,i##end=b;i>=i##end;i--)
#define rep(i,  a) for(int i=1,i##end=a;i<=i##end;i++)
using namespace std;
const int N=4e5+9;
//char buf[(1<<21)+5],*p1,*p2;
//#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
void chmx(int &x,int y){(x<y)?(x=y):(0);}
void chmn(int &x,int y){(x>y)?(x=y):(0);}
inline int read(){
	int f=0,x=0;
	char ch=getchar();
	while(!isdigit(ch)){f|=(ch=='-');ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return f?-x:x;
}
struct tree{
	int tag[N<<2],sum[N<<2];
	#define ls (p<<1)
	#define rs (p<<1|1)
	void add(int p,int l,int r,int x,int v){
		if(l==r){sum[p]-=v;if(sum[p])tag[p]=1;else tag[p]=0;return;}
		int mid=(l+r)>>1;
		if(mid>=x)add(ls,l,mid,x,v);
		else add(rs,mid+1,r,x,v);
		tag[p]=tag[ls]+tag[rs];
	}
	int get(int p,int l,int r,int nl,int nr){
		if(nl<=l&&r<=nr)return tag[p];
		int mid=(l+r)>>1,res=0;
		if(mid>=nl)res+=get(ls,l,mid,nl,nr);
		if(mid<nr)res+=get(rs,mid+1,r,nl,nr);
		return res;
	}
}a,b;
signed main(){
//	printf("%.5lf",(&pppp-&ppp)/1024.0/1024.0);
	int n=read(),q=read();
	while(q--){
		int op=read();
		if(op==1){
			int x=read(),y=read();
			a.add(1,1,n,x,1);
			b.add(1,1,n,y,1);
		}
		if(op==2){
			int x=read(),y=read();
			a.add(1,1,n,x,-1);
			b.add(1,1,n,y,-1);
		}if(op==3){
			int a1=read(),b1=read(),a2=read(),b2=read();
			if(a.get(1,1,n,a1,a2)==a2-a1+1){puts("Yes");continue;}
			if(b.get(1,1,n,b1,b2)==b2-b1+1){puts("Yes");continue;}
			puts("No");
			
		}
	}
	return 0;
}