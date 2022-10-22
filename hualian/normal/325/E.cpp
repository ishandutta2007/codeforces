#include<bits/stdc++.h>
#define For(i,a,b) for(register int i=a,i##end=b;i<=i##end;i++)
#define Rof(i,a,b) for(register int i=a,i##end=b;i>=i##end;i--)
#define rep(i,  a) for(register int i=1,i##end=a;i<=i##end;i++)
using namespace std;
const int N=1e6+9;
void chmx(int &x,int y){(x<y)?(x=y):(0);}
void chmn(int &x,int y){(x>y)?(x=y):(0);}
inline int read(){
	int f=0,x=0;
	char ch=getchar();
	while(!isdigit(ch)){f|=(ch=='-');ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return f?-x:x;
}
int n;
int fa[N],to[N];
int get(int x){return fa[x]==x?x:fa[x]=get(fa[x]);}
void merge(int x,int y){
	x=get(x),y=get(y);
	if(x==y)return;
	fa[x]=y;
}
signed main(){
//	printf("%.5lf",(&pppp-&ppp)/1024.0/1024.0);
	n=read();
	For(i,0,n-1)fa[i]=i;
	if(n%2){puts("-1");return 0;}
	For(i,0,n-1){
		if(i<n/2)to[i]=(2*i+1)%n,merge(i,(2*i+1)%n);
		else to[i]=2*i%n,merge(i,2*i%n);
	}
	For(i,0,n/2-1)if(get(i)!=get(i+n/2)){
		merge(get(i),get(i+n/2));
		swap(to[i],to[i+n/2]);
	}
	int x=0;cout<<"0 ";
	do x=to[x],printf("%d ",x);while(x);
	return 0;
}