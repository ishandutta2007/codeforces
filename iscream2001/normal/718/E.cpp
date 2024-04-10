#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#define LL long long
using namespace std;
const int N=1e5+50;
int n,cnt;
int a[N],hed[N],f[N][9],g[9][9],d[9][260][9][260];
int t[N];
LL tot[9][260];
char s[N];
struct edge{
	int r,nxt,v;
}e[N*6];
void insert(int u,int v,int w){
	e[++cnt].r=v;e[cnt].nxt=hed[u];hed[u]=cnt;e[cnt].v=w;
}
bool vis[N];
queue<int> Q;
void getf(int c){
	int x;
	for(int i=1;i<=n;++i)
		if(a[i]==c){
			f[i][c]=0;
			Q.push(i);
			vis[i]=1;
		}
	while(!Q.empty()){
		x=Q.front();Q.pop();
		for(int i=hed[x];i;i=e[i].nxt)
			if(f[x][c]+e[i].v<f[e[i].r][c]){
				f[e[i].r][c]=f[x][c]+e[i].v;
				if(!vis[e[i].r]){
					Q.push(e[i].r);
					vis[e[i].r]=1;
				}
			}
		vis[x]=0;
	}
}
LL ans=0;
int len=0;
void add(int L,LL sum){
	if(L>16||sum==0) return ;
	if(L>len){len=L;ans=0;}
	if(L==len) ans+=sum;
}
int main(){
	memset(f,62,sizeof(f));
	scanf("%d",&n);
	scanf("%s",s+1);
	for(int i=1;i<=n;++i) a[i]=s[i]-'a'+1;
	for(int i=1;i<n;++i){
		insert(i,i+1,1);
		insert(i+1,i,1);
	}
	for(int i=1;i<=n;++i){
		insert(i,n+a[i],0);
		insert(n+a[i],i,1);
	}
	for(int c=1;c<=8;++c) getf(c);
	memset(g,62,sizeof(g));
	for(int i=1;i<=8;++i)
		for(int j=1;j<=8;++j){
			if(i==j){g[i][j]=0;continue;}
			for(int k=1;k<=n;++k) g[i][j]=min(g[i][j],f[k][i]+f[k][j]);
		}
	memset(d,62,sizeof(d));
	for(int i=1;i<=8;++i)
		for(int j=0;j<(1<<8);++j)
			for(int k=1;k<=8;++k)
				for(int p=0;p<(1<<8);++p)
					for(int q=1;q<=8;++q)
						d[i][j][k][p]=min(d[i][j][k][p],g[i][q]+g[k][q]+1+((j>>(q-1))&1)+((p>>(q-1))&1));
	for(int i=1;i<=n;++i)
		for(int j=8;j>=1;--j)
			t[i]=t[i]<<1|(f[i][j]-g[a[i]][j]);
	int L;
	for(int i=1;i<=n;++i){
		for(int j=i-15;j<i;++j){
			if(j<1) continue;
			L=min(i-j,d[a[i]][t[i]][a[j]][t[j]]);
			add(L,1);
		}
		for(int c=1;c<=8;++c)
			for(int j=0;j<(1<<8);++j)
				add(d[a[i]][t[i]][c][j],tot[c][j]);
		if(i-15>=1) tot[a[i-15]][t[i-15]]++;
	}
	cout<<len<<" "<<ans<<endl;
	return 0;
}
/*
59
eedecdbacbcdhhaggefgfbcagcbbafggdhcdbfhcgbehhhcfcffcacfchgh
*/