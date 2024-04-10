#include<bits/stdc++.h>
#define For(i,a,b) for(int i=a,i##end=b;i<=i##end;i++)
#define Rof(i,a,b) for(int i=a,i##end=b;i>=i##end;i--)
#define rep(i,  a) for(int i=1,i##end=a;i<=i##end;i++)
using namespace std;
const int N=3e5+9;
char buf[(1<<21)+5],*p1,*p2;
#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
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
vector<int>e[N];
int dp[N],f[N];
void add(int x,int y){e[x].push_back(y);}
void dfs(int x,int fa){
	f[x]=fa;
	for(int to:e[x])if(to!=fa){
		dfs(to,x);
		dp[x]^=(dp[to]+1);
	}return;
}
bool vis[N];
int ans=0,cnt;
void del(int x){
	while(x){
		if(!vis[x]){
			for(int to:e[x])if(to!=f[x]){
				ans^=(dp[to]+1);
			}
			ans^=(dp[x]+1);
		}else break;
		vis[x]=1;cnt++;x=f[x];
	}
}
signed main(){
//	printf("%.5lf",(&pppp-&ppp)/1024.0/1024.0);
	n=read();
	rep(i,n-1){
		int x=read(),y=read();
		add(x,y);add(y,x);
	}dfs(1,0);
	ans=dp[1];vis[1]=1;
	putchar(ans?'1':'2');
	For(i,2,n)del(i),putchar((ans^(cnt%2))?'1':'2');
	return 0;
}