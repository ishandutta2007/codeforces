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
int n;
vector<int>e[N];
int dep[N],mx;
int len[N];
void dfs(int x,int fa){
	dep[x]=dep[fa]+1;
	chmx(len[x],dep[x]);
	if(dep[x]>dep[mx])mx=x;
	for(int to:e[x])if(to!=fa)
		dfs(to,x);
}
signed main(){
//	printf("%.5lf\n",(&pppp-&ppp)/1024.0/1024.0);
dep[0]=-1;
	int T=read();while(T--){
		n=read();int a=read(),b=read(),da=read(),db=read();
		rep(i,n)e[i].clear(),len[i]=dep[i]=0;
		rep(i,n-1){
			int x=read(),y=read();
			e[x].push_back(y);
			e[y].push_back(x);
		}
		int rt=1;mx=0;
		dfs(rt,0);rt=mx;mx=0;
		dfs(rt,0);rt=mx;mx=0;
		dfs(rt,0);
		dfs(a,0);if(dep[b]<=da){puts("Alice");continue;}
		if(da*2>=db){puts("Alice");continue;}
		int f=0;
		rep(i,n)if(e[i].size()==1){ 
			if(len[i]>2*da){f=1;puts("Bob");break;}
		}
		if(!f)puts("Alice");
	}
	return 0;
}