#include<bits/stdc++.h>
#define For(i,a,b) for(int i=a,i##end=b;i<=i##end;i++)
#define Rof(i,a,b) for(int i=a,i##end=b;i>=i##end;i--)
#define rep(i,  b) for(int i=1,i##end=b;i<=i##end;i++)
using namespace std;
const int N=1e6+9;
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
int n;
int a[N][2],op[N],vis[N];
struct edge{
	int pre,to;
}e[4*N];int last[N],cnt;
void add(int x,int y){
	e[++cnt].pre=last[x];
	e[cnt].to=y;
	last[x]=cnt;
}
signed main(){
//	printf("%.5lf\n",(&pppp-&ppp)/1024.0/1024.0);
	n=read();
	if(n%2==0){
		puts("First");
		fflush(stdout);
		rep(i,n)printf("%d ",i);
		rep(i,n)printf("%d ",i);
		fflush(stdout);
		return 0;
	}
	puts("Second");fflush(stdout);
	rep(i,2*n){
		int x=read();
		a[x][0]?(a[x][1]=i,op[x]=1):(a[x][0]=i,op[x]=0);
	}
	rep(i,n)add(a[i][0],a[i][1]),add(a[i][1],a[i][0]);
	rep(i,n)add(i,i+n),add(i+n,i);
	long long tag=0,sum=0;
	rep(i,2*n)if(!vis[i]){
		int x=i,len=0,op=2;
		while(!vis[x]){
			len++;vis[x]=op;
			if(op==3)sum+=x;op^=1;
			int nt=0;
			for(int j=last[x];j;j=e[j].pre){
				if(!vis[e[j].to])nt=e[j].to;
			}
			if(nt)x=nt;
		}
		if(len/2%2)tag=i;
	}
	if(sum%(n*2)){
		int x=tag,op=1;
		while(vis[x]>=2){
			vis[x]=op;
			if(op==1)sum+=x;
			else sum-=x;
			op^=1;
			int nt=0;
			for(int j=last[x];j;j=e[j].pre)
				if(vis[e[j].to]>=2)nt=e[j].to;
			if(nt)x=nt;
		}
	}assert(sum%(n*2)==0);
	rep(i,n){
		if(vis[a[i][0]]%2)printf("%d ",a[i][0]);
		else printf("%d ",a[i][1]);
	}
		fflush(stdout);
	return 0;
}