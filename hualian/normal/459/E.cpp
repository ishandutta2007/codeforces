#include<bits/stdc++.h>
#define For(i,a,b) for(int i=a,i##end=b;i<=i##end;i++)
#define Rof(i,a,b) for(int i=a,i##end=b;i>=i##end;i--)
#define rep(i,  a) for(int i=1,i##end=a;i<=i##end;i++)
using namespace std;
const int N=3e5+9;
void chmx(int &x,int y){(x<y)?(x=y):(0);}
void chmn(int &x,int y){(x>y)?(x=y):(0);}
inline int read(){
	int f=0,x=0;
	char ch=getchar();
	while(!isdigit(ch)){f|=(ch=='-');ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return f?-x:x;
}
int n,m,res[N],tmp[N];
struct edge{
	int x,y,w;
	bool operator<(const edge&X)const{return w<X.w;}
}e[2*N];
int main(){
//	printf("%.5lf",(&pppp-&ppp)/1024.0/1024.0);
	n=read(),m=read();
	rep(i,m)e[i]=edge{read(),read(),read()};
	sort(e+1,e+1+m);
	int i=1,j;
	while(i<=m){
		j=i;while(j<=m&&e[j].w==e[i].w)j++;
		For(k,i,j-1)tmp[e[k].x]=res[e[k].x],tmp[e[k].y]=res[e[k].y];
		For(k,i,j-1)chmx(res[e[k].y],tmp[e[k].x]+1);
		i=j;
	}
	int ans=0;
	rep(i,n)chmx(ans,res[i]);
	cout<<ans<<endl;
	return 0;
}