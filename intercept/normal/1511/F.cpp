#include<bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
const int mod=998244353;
const int M=509;
int n,m,sz,tot;
int c[M][29];
int tag[M],vis[M][M];
char t[10];
struct Matrix{
	int a[M][M];
	void clear(){
		for(int i=1;i<=tot;++i)
		for(int j=1;j<=tot;++j)
			a[i][j]=0;
	}
	Matrix operator * (const Matrix&o){
		Matrix rex;rex.clear();
		for(int i=1;i<=tot;++i)
		for(int j=1;j<=tot;++j)
		for(int k=1;k<=tot;++k)
			rex.a[i][j]=(rex.a[i][j]+1ll*a[i][k]*o.a[k][j]%mod)%mod;
		return rex;
	}
}x,y;
void ins(char *s){
	int len=strlen(s+1),u=0;
	for(int i=1;i<=len;++i){
		int v=s[i]-'a'+1;
		if(!c[u][v])c[u][v]=++sz;
		u=c[u][v];
		if(i==len)tag[u]=1;
	}
}
queue<pii>q;
int get(int u,int v){
	if(u>v)swap(u,v);
	if(!vis[u][v])vis[u][v]=++tot,q.push(pii{u,v});
	return vis[u][v];
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i){
		scanf("%s",t+1);
		ins(t);
	}
	
	q.push(pii{0,0});
	vis[0][0]=++tot;
	x.clear();
	y.clear();
	while(!q.empty()){
		pii u=q.front();
		q.pop();
		for(int i=1;i<=26;++i){
			pii v=pii{c[u.fi][i],c[u.se][i]};
			if(v.fi&&v.se){
				x.a[get(u.fi,u.se)][get(v.fi,v.se)]++;
				if(tag[v.fi])x.a[get(u.fi,u.se)][get(0,v.se)]++;
				if(tag[v.se])x.a[get(u.fi,u.se)][get(v.fi,0)]++;
				if(tag[v.fi]&&tag[v.se])x.a[get(u.fi,u.se)][1]++;
			}
		}
	}
	for(int i=1;i<=tot;++i)y.a[i][i]=1;
	for(;m;m>>=1,x=x*x)if(m&1)y=y*x;
	printf("%d\n",y.a[1][1]);
	return 0;
}