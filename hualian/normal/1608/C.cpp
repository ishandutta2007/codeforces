#include<bits/stdc++.h>
#define For(i,a,b) for(int i=a,i##end=b;i<=i##end;i++)
#define Rof(i,a,b) for(int i=a,i##end=b;i>=i##end;i--)
#define rep(i,  b) for(int i=1,i##end=b;i<=i##end;i++)
using namespace std;
const int N=2e5+9;
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
struct node{int x,y,id;}a[N];
int mx[N],op[N],ans[N];
signed main(){
//	printf("%.5lf\n",(&pppp-&ppp)/1024.0/1024.0);
	int T=read();while(T--){
		int n=read();
		rep(i,n)mx[i]=op[i]=0;
		rep(i,n)a[i].id=i;
		rep(i,n)a[i].x=read();
		rep(i,n)a[i].y=read();
		sort(a+1,a+1+n,[&](node&x,node&y){return x.y<y.y;});
		rep(i,n)a[i].y=i;
		sort(a+1,a+1+n,[&](node&x,node&y){return x.x<y.x;});
		rep(i,n){
			mx[i]=mx[i-1];
			chmx(mx[i],a[i].y);
		}
		op[n]=1;
		Rof(i,n,1){
			if(op[mx[i]])op[i]=1;
		}
		rep(i,n)ans[a[i].id]=op[i];
		rep(i,n)putchar(ans[i]?'1':'0');puts("");
		//ii 
	}
	return 0;
}