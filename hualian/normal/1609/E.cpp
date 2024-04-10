#include<bits/stdc++.h>
#define For(i,a,b) for(int i=a,i##end=b;i<=i##end;i++)
#define Rof(i,a,b) for(int i=a,i##end=b;i>=i##end;i--)
#define rep(i,  a) for(int i=1,i##end=a;i<=i##end;i++)
using namespace std;
const int N=2e5+9;
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
int n,q; 
char s[N];
struct point{
	int a,b,c;
	int ab,bc,abc;
}t[N*2];
struct tree{
	#define ls (p<<1)
	#define rs (p<<1|1)
	void push_up(int p){
		t[p].a=t[ls].a+t[rs].a;
		t[p].b=t[ls].b+t[rs].b;
		t[p].c=t[ls].c+t[rs].c;
		t[p].ab=min(t[ls].a+t[rs].ab,t[ls].ab+t[rs].b);
		//ABBA 
		t[p].bc=min(t[ls].b+t[rs].bc,t[ls].bc+t[rs].c);
		t[p].abc=min(t[ls].a+t[rs].abc,t[ls].abc+t[rs].c);
		//ABCABC,ABC 
		//AABC 
		//CABC
		//ABBC 
		chmn(t[p].abc,t[ls].ab+t[rs].bc);
	}
	void build(int p,int l,int r){
		if(l==r){
			t[p].a=t[p].b=t[p].c=0;
			switch(s[l]){
				case 'a':t[p].a=1;break;
				case 'b':t[p].b=1;break;
				case 'c':t[p].c=1;break; 
			}return;
		}int mid=(l+r)>>1;
		build(ls,l,mid);
		build(rs,mid+1,r);
		push_up(p);
	}
	void change(int p,int l,int r,int x){
		if(l==r){
			t[p].a=t[p].b=t[p].c=0;
			switch(s[l]){
				case 'a':t[p].a=1;break;
				case 'b':t[p].b=1;break;
				case 'c':t[p].c=1;break; 
			}return;
		}int mid=(l+r)>>1;
		if(mid>=x)change(ls,l,mid,x);
		else change(rs,mid+1,r,x);
		push_up(p);
	}
}T;
signed main(){
//	printf("%.5lf",(&pppp-&ppp)/1024.0/1024.0);
	n=read(),q=read();
	scanf("%s",s+1);
	T.build(1,1,n);
	while(q--){
		int x=read();char c;cin>>c;
		s[x]=c;T.change(1,1,n,x);
		printf("%d\n",t[1].abc);
	}
	return 0;
}