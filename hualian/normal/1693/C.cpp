#include<bits/stdc++.h>
#define For(i,a,b) for(int i=a,i##end=b;i<=i##end;i++)
#define Rof(i,a,b) for(int i=a,i##end=b;i>=i##end;i--)
#define rep(i,  b) for(int i=1,i##end=b;i<=i##end;i++)
using namespace std;
char buf[(1<<21)+5],*p1,*p2;
#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
void chmx(int &x,int y){(x<y)&&(x=y);}
void chmn(int &x,int y){(x>y)&&(x=y);}
int read(){
	int f=0,x=0;
	char ch=getchar();
	while(!isdigit(ch)){f|=(ch=='-');ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return f?-x:x;
}
int deg[200010],dis[200010],m,n;
vector<int>e[200010];
bool vis[200010];
priority_queue<pair<int,int>>q;
signed main(){
//	printf("%.5lf\n",(&pppp-&ppp)/1024.0/1024.0);
	n=read(),m=read();
	while(m--){
		int x=read(),y=read();
		++deg[x];
		e[y].push_back(x);
	}
	memset(dis,0x3f,sizeof dis);
	dis[n]=0;
	q.emplace(0,n);
	while(q.size()){
		int u=q.top().second;q.pop();
		if(vis[u])continue;
		vis[u]=true;
		for(int v:e[u]){
			if(!vis[v]&&dis[u]+deg[v]<dis[v]){
				dis[v]=dis[u]+deg[v];
				q.emplace(-dis[v],v);
			}
			--deg[v];
		}
	}
	printf("%d",dis[1]);
	return 0;
}