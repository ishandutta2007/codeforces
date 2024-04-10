#include<bits/stdc++.h>
#define int long long
#define For(i,a,b) for(int i=a,i##end=b;i<=i##end;i++)
#define Rof(i,a,b) for(int i=a,i##end=b;i>=i##end;i--)
#define rep(i,  a) for(int i=1,i##end=a;i<=i##end;i++)
using namespace std;
const int N=3e5+9;
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
int n,m,k,a[N];
vector<int>E[N];
struct edge{
	int pre,to;
}e[2*N];int last[N],cnt,idx;
void add(int x,int y){
	e[++cnt].pre=last[x];
	e[cnt].to=y;
	last[x]=cnt;
}
int sta[N],top,c[N],color,f,sz[N];
int rd[N],dfn[N],low[N];
int dp[N];
void clear(){
	memset(last,0,sizeof last);
	memset(c,0,sizeof c);
	memset(rd,0,sizeof rd);
	memset(dp,0,sizeof dp);
	memset(dfn,0,sizeof dfn);
	memset(sz,0,sizeof sz);
	cnt=0;idx=0;f=0;color=0;
}
void tarjan(int x){
	dfn[x]=low[x]=++idx;
	sta[++top]=x;
	for(int i=last[x];i;i=e[i].pre){
		int to=e[i].to;
		if(!dfn[to]){
			tarjan(to);
			chmn(low[x],low[to]);
		}else if(!c[to])chmn(low[x],dfn[to]);
	}
	if(low[x]!=dfn[x])return ;
	++color;
	do c[sta[top--]]=color,sz[color]++;while(sta[top+1]!=x);
}
queue<int>q;
bool check(int mid){
	clear();rep(i,n)if(a[i]<=mid)for(int to:E[i])if(a[to]<=mid)add(i,to),rd[to]++;
	rep(i,n)if(!dfn[i]&&a[i]<=mid)tarjan(i);
	rep(i,color)if(sz[i]>=2)return 1;
	rep(i,n)if(!rd[i]&&a[i]<=mid)q.push(i),dp[i]=1;
	int f=0;
	while(!q.empty()){
		int x=q.front();q.pop();
		if(dp[x]>=k)f=1;
		for(int i=last[x];i;i=e[i].pre){
			int to=e[i].to;chmx(dp[to],dp[x]+1);
			if(--rd[to]==0)q.push(to);
		}
	}return f;
}
signed main(){
//	printf("%.5lf",(&pppp-&ppp)/1024.0/1024.0);
	n=read(),m=read(),k=read();
	rep(i,n)a[i]=read();
	rep(i,m){
		int x=read(),y=read();
		E[x].push_back(y);
	}
	int l=0,r=1000000000;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid))r=mid-1;
		else l=mid+1;
//		cout<<check(mid)<<" "<<mid<<endl;
	}
	if(r+1==1000000001)puts("-1");
	else cout<<r+1<<endl;
	return 0;
}