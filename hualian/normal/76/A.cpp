#include<bits/stdc++.h>
#define lowbit(x) (x&-x)
#define int long long
#define For(i,a,b) for(int i=a,i##end=b;i<=i##end;i++)
#define Rof(i,a,b) for(int i=a,i##end=b;i>=i##end;i--)
#define rep(i,  a) for(int i=1,i##end=a;i<=i##end;i++)
using namespace std;
const int MAX=2e18;
const int N=2e5+9;
void chmx(int &x,int y){(x<y)?(x=y):(0);}
void chmn(int &x,int y){(x>y)?(x=y):(0);}
inline int read(){
	int f=0,x=0;
	char ch=getchar();
	while(!isdigit(ch)){f|=(ch=='-');ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return f?-x:x;
}
int n,m,G,S;
struct edge{
	int x,y,g,s;
	void input(){x=read(),y=read(),g=read(),s=read();}
	bool operator<(const edge&X)const{return g==X.g?s<X.s:g<X.g;}
}a[N],b[N];int top;
int fa[N],ans=MAX;
int get(int x){return fa[x]==x?x:fa[x]=get(fa[x]);}
bool merge(int x,int y){
	x=get(x),y=get(y);
	if(x==y)return false;
	fa[x]=y;
	return true;
}
signed main(){
//	printf("%.5lf",(&pppp-&ppp)/1024.0/1024.0);
	n=read(),m=read(),G=read(),S=read();
	rep(i,m)a[i].input();
	sort(a+1,a+1+m);
	rep(i,m){
		b[++top]=a[i];
		sort(b+1,b+1+top,[&](edge &x,edge&y){return x.s<y.s;});
		int len=0;
		rep(j,n)fa[j]=j;
		rep(j,top)if(merge(b[j].x,b[j].y))b[++len]=b[j];
		top=len;
		if(top==n-1)chmn(ans,G*a[i].g+S*b[top].s);
	}cout<<(ans<MAX?ans:-1)<<endl;
	return 0;
}