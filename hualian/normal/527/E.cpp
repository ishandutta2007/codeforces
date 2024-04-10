#include<bits/stdc++.h>
#define For(i,a,b) for(int i=a,i##end=b;i<=i##end;i++)
#define Rof(i,a,b) for(int i=a,i##end=b;i>=i##end;i--)
#define rep(i,  a) for(int i=1,i##end=a;i<=i##end;i++)
using namespace std;
const int N=1e6+9;
inline int read(){
	int f=0,x=0;
	char ch=getchar();
	while(!isdigit(ch)){f|=(ch=='-');ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return f?-x:x;
}
struct edge{
	int pre,to;
}e[2*N];int last[N],cnt=1;
int vis[N];
void add(int x,int y){
	e[++cnt].pre=last[x];
	e[cnt].to=y;
	last[x]=cnt;
}
int n,m,pre,idx,d[N];
void dfs(int x){
	for(int &i=last[x];i;i=e[i].pre){
		int to=e[i].to;if(vis[i/2])continue;
		vis[i/2]=1;
		dfs(to);
		if((++idx)%2)printf("%d %d\n",x,to);
		else printf("%d %d\n",to,x);
		
	}
}
int main(){
//	printf("%.5lf",(&pppp-&ppp)/1024.0/1024.0);
	n=read(),m=read();
	rep(i,m){
		int x=read(),y=read();
		add(x,y),add(y,x);
		d[x]++,d[y]++;
	}
	rep(i,n){
		if(d[i]%2){
			if(pre)add(pre,i),add(i,pre),pre=0;
			else pre=i;
		}
	}
	assert(pre==0);
	if(cnt/2%2)add(1,1),add(1,1);
	cout<<cnt/2<<endl;
	dfs(1);
	return 0;
}