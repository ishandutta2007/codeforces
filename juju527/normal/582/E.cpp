#include<bits/stdc++.h>
using namespace std;
const int maxs=505,mod=1e9+7;
int n,m;
char s[maxs];
struct Edge{
	int to,nxt;
}e[maxs];
int cnt;
int head[maxs];
int tot;
int a[maxs];
int ls[maxs],rs[maxs];
int lim[16],S;
int read(){
	int x=0,y=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')y=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return x*y;
}
inline int add(int x){
	if(x>=mod)x-=mod;
	return x;
}
inline int sub(int x){
	if(x<0)x+=mod;
	return x;
}
void add(int u,int v){
	e[cnt].to=v;
	e[cnt].nxt=head[u];
	head[u]=cnt++;
	return ;
}
int build(int l,int r){
	int tp=0;
	int id=++tot;
	if(l==r){a[id]=s[l];return id;}
	for(int i=l;i<=r;i++){
		if(s[i]=='(')tp++;
		else if(s[i]==')')tp--;
		else{
			if(tp)continue;
			a[id]=s[i];
			int Ls=build(l+1,i-2),Rs=build(i+2,r-1);
			ls[id]=Ls;rs[id]=Rs;
			break;
		}
	}
	return id;
}
int to[256],tag[256];
int f[maxs][1<<16],g[1<<16];
int get(int s,int b){
	return (s&(1<<b))>>b;
}
void FWTor(int *f,int opt){
	for(int mid=1;mid<(1<<m);mid<<=1)
		for(int j=0;j<(1<<m);j+=(mid<<1))
			for(int k=0;k<mid;k++)
				f[j+k+mid]=(opt==1?add(f[j+k+mid]+f[j+k]):sub(f[j+k+mid]-f[j+k]));
	return ;
}
void FWTand(int *f,int opt){
	for(int mid=1;mid<(1<<m);mid<<=1)
		for(int j=0;j<(1<<m);j+=(mid<<1))
			for(int k=0;k<mid;k++)
				f[j+k]=(opt==1?add(f[j+k]+f[j+k+mid]):sub(f[j+k]-f[j+k+mid]));
	return ;
}
void dfs(int x){
	if(ls[x]&&rs[x]){
		dfs(ls[x]);
		dfs(rs[x]);
		if(a[x]=='|'||a[x]=='?'){
			FWTor(f[ls[x]],1);FWTor(f[rs[x]],1);
			for(int i=0;i<(1<<m);i++)g[i]=1ll*f[ls[x]][i]*f[rs[x]][i]%mod;
			FWTor(f[ls[x]],-1);FWTor(f[rs[x]],-1);
			FWTor(g,-1);
			for(int i=0;i<(1<<m);i++)f[x][i]=add(f[x][i]+g[i]);
		}
//		for(int i=0;i<(1<<m);i++)cout<<x<<" "<<i<<" "<<f[x][i]<<endl;
		if(a[x]=='&'||a[x]=='?'){
			FWTand(f[ls[x]],1);FWTand(f[rs[x]],1);
			for(int i=0;i<(1<<m);i++)g[i]=1ll*f[ls[x]][i]*f[rs[x]][i]%mod;
			FWTand(f[ls[x]],-1);FWTand(f[rs[x]],-1);
			FWTand(g,-1);
			for(int i=0;i<(1<<m);i++)f[x][i]=add(f[x][i]+g[i]);
		}
	}
	if(!ls[x]&&!rs[x]){
		if(a[x]=='?'){
			for(int i=0;i<(1<<m);i++){
				bool vis[4][2];
				memset(vis,0,sizeof(vis));
				for(int j=0;j<m;j++){
					int c=get(i,j);
					for(int k=0;k<4;k++){
						if(get(lim[j],k)==c)vis[k][1]=1;
						else vis[k][0]=1;
					}
				}
				for(int j=0;j<4;j++)f[x][i]+=(vis[j][0]^1)+(vis[j][1]^1);
			}
		}
		else{
			for(int i=0;i<(1<<m);i++){
				bool flag=1;
				for(int j=0;j<m;j++)
					if(get(lim[j],to[a[x]])^tag[a[x]]^get(i,j)){flag=0;break;}
				f[x][i]=flag;
			}
		}
		
	}
//	for(int i=0;i<(1<<m);i++)cout<<x<<" "<<i<<" "<<f[x][i]<<endl;
	return ;
}
int main(){
	scanf("%s",s+1);n=strlen(s+1);
	memset(head,-1,sizeof(head));
	build(1,n);
	m=read();
	for(int i=0;i<m;i++){
		int c;
		for(int j=0;j<4;j++){
			c=read();
			lim[i]=lim[i]+c*(1<<j);
		}
		c=read();
		S=S+c*(1<<i);
	}
	to['A']=to['a']=0;
	to['B']=to['b']=1;
	to['C']=to['c']=2;
	to['D']=to['d']=3;
	tag['a']=tag['b']=tag['c']=tag['d']=1;
	dfs(1);
	printf("%d\n",f[1][S]);
	return 0;
}