#include<bits/stdc++.h>
#define For(i,a,b) for(int i=a,i##end=b;i<=i##end;i++)
#define Rof(i,a,b) for(int i=a,i##end=b;i>=i##end;i--)
#define rep(i,  b) for(int i=1,i##end=b;i<=i##end;i++)
using namespace std;
const int N=41;
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
int n,k,res,ans,a[N]; 
bitset<N>e[N],S;
signed main(){
//	printf("%.5lf\n",(&pppp-&ppp)/1024.0/1024.0);
	n=read(),k=read();
	rep(i,n)rep(j,n)e[i][j]=read();
	rep(i,n)a[i]=i;
	rep(k,1000000){
		res=0;S.reset();
		random_shuffle(a+1,a+1+n);
		rep(j,n)if((e[a[j]]&S)==S)S.set(a[j]),res++;
		chmx(ans,res);
	}
	printf("%.6lf",1.0*k*k*(ans-1)/2/ans);
	return 0;
}