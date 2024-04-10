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
char s[N];int a[N],n;
multiset<int>e[N];
void add(int x,int y){e[x].insert(y);}
int sta[N],top;
void dfs(int x){
	while(e[x].size()){
		int to=*e[x].begin();
		e[x].erase(e[x].begin());
		e[to].erase(e[to].find(x));
		dfs(to);
	}sta[++top]=x;
}
signed main(){
//	printf("%.5lf\n",(&pppp-&ppp)/1024.0/1024.0);
	int T=read();
	while(T--){top=0;
		scanf("%s",s+1);
		n=strlen(s+1);
		rep(i,2*n+2)e[i].clear();
		rep(i,n)a[i]=(s[i]=='1'?1:-1);
		rep(i,n)a[i]+=a[i-1];
		rep(i,n)add(a[i-1]+n,a[i]+n),add(a[i]+n,a[i-1]+n);
		dfs(n);reverse(sta+1,sta+1+top);
		For(i,2,top)printf("%d",(sta[i]-sta[i-1]==-1)?0:1);puts("");
	}
	return 0;
}