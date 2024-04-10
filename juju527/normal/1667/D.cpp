//Code by juju527.
#include<bits/stdc++.h>
typedef long long ll;
#define pii pair<int,int>
#define fi first
#define se second
#define vec vector<int>
#define eb emplace_back
using namespace std;
const int maxn=2e5+5;
struct Edge{int to,nxt;}e[2*maxn];
int cnt,head[maxn];
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<48||ch>57){if(ch==45)y=-1;ch=getchar();}
    while(ch>=48&&ch<=57)x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
void add(int u,int v){
	e[cnt]=(Edge){v,head[u]};
	head[u]=cnt++;
	return ;
}
bool tag=0;
int f[maxn],p[maxn],s[maxn];
int num[maxn][4];
void dfs1(int x,int fa){
	p[x]=fa;
	int *buf=num[x],son=0;
	buf[0]=buf[1]=buf[2]=buf[3]=0;
	for(int i=head[x];i!=-1;i=e[i].nxt){
		int tmp=e[i].to;
		if(tmp==fa)continue;
		dfs1(tmp,x);
		if(!f[tmp]){tag=1;break;}
		buf[f[tmp]]++;son++;
	}
	if(tag)return ;
	f[x]=0;s[x]=son;
	if(!son){f[x]=1;return ;}
	if(son&1){
		if(buf[1]+buf[3]>=(son+1)/2&&buf[2]+buf[3]>=(son-1)/2)f[x]|=2;
		if(buf[2]+buf[3]>=(son+1)/2&&buf[1]+buf[3]>=(son-1)/2)f[x]|=1;
	}
	else{
		if(buf[1]+buf[3]>=son/2+1&&buf[2]+buf[3]>=son/2-1)f[x]|=2;
		if(buf[1]+buf[3]>=son/2&&buf[2]+buf[3]>=son/2)f[x]|=1;
	}
	if(x==1&&!((f[x]>>(son&1))&1))tag=1;
	return ;
}
int tp,st[maxn];
void dfs2(int x,int fa,int op){
	vec aux[4];for(int i=0;i<4;i++)aux[i].clear();
	for(int i=head[x];i!=-1;i=e[i].nxt){
		int tmp=e[i].to;
		if(tmp==fa)continue;
		aux[f[tmp]].eb(tmp);
	}
	if(s[x]&1){
		if(op){
			int y=0;
			if(aux[2].size())y=aux[2].back(),aux[2].pop_back();
			else y=aux[3].back(),aux[3].pop_back();
			if(s[y]&1)st[++tp]=y,dfs2(y,x,0);
			else dfs2(y,x,1);
			st[++tp]=x;
		}
	}
	else{
		if(op){
			int y=0;
			if(aux[1].size())y=aux[1].back(),aux[1].pop_back();
			else y=aux[3].back(),aux[3].pop_back();
			if(s[y]&1)dfs2(y,x,1);
			else st[++tp]=y,dfs2(y,x,0);
			st[++tp]=x;
		}
	}
	for(int i=op+1-(s[x]&1);i<s[x]+1-(s[x]&1);i++){
		int y=0;
		if(i&1){
			if(aux[2].size())y=aux[2].back(),aux[2].pop_back();
			else y=aux[3].back(),aux[3].pop_back();
			if(s[y]&1)st[++tp]=y,dfs2(y,x,0);
			else dfs2(y,x,1);
		}
		else{
			if(aux[1].size())y=aux[1].back(),aux[1].pop_back();
			else y=aux[3].back(),aux[3].pop_back();
			if(s[y]&1)dfs2(y,x,1);
			else st[++tp]=y,dfs2(y,x,0);
		}
	}
	return ;
}
int main(){
    int T;
	T=read();
	while(T--){
		int n;
		n=read();
		for(int i=1;i<=n;i++)head[i]=-1;
		for(int i=1;i<n;i++){
			int u,v;
			u=read();v=read();
			add(u,v),add(v,u);
		}
		tag=0,dfs1(1,0);
		if(tag){puts("NO");continue;}
		tp=0;dfs2(1,0,0);
		puts("YES");
		for(int i=1;i<n;i++)printf("%d %d\n",st[i],p[st[i]]);
	}
    return 0;
}