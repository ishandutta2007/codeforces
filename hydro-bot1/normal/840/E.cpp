// Hydro submission #62c674c3c3a9fda5622ac34a@1657173200846
#include<cstdio>
#include<algorithm>
using namespace std;

#define B 256
int n,q,cnt=-1;
int fir[50000];
int val[50000];
int to[100000];
int nxt[100000];
int dep[50000];
int fat[50000];
int up[200][50000];
int maxv[200][50000];
void add(int a,int b)
{
	to[++cnt]=b;
	nxt[cnt]=fir[a];
	fir[a]=cnt;
	return;
}
void dfs(int i,int fa)
{
	fat[i]=fa;
	for(int j=fir[i];j!=-1;j=nxt[j])
		if(to[j]!=fa){
			dep[to[j]]=dep[i]+1;
			dfs(to[j],i);
		}
	return;
}

int wei[256];
int ch[2][65536];
void build_table(int nd)
{
	int cnt=0;
	for(int i=0;i<B*16;i++)
		ch[0][i]=ch[1][i]=-1;
	for(int i=0;i<B;i++){
		int x=0,y;
		for(int j=15;j>=0;j--){
			y=((wei[i]>>j)&1);
			if(ch[y][x]==-1){
				++cnt; ch[y][x]=cnt;
			}
			x=ch[y][x];
		}
	}
	for(int i=0;i*B<n;i++){
		int w=i*B,x=0,y;
		for(int j=15;j>=0;j--){
			y=((w>>j)&1);
			if(ch[y^1][x]>=0){
				maxv[i][nd]|=(1<<j);
				x=ch[y^1][x];
			}
			else x=ch[y][x];
		}
	}
	return;
}

int main()
{
	scanf("%d%d",&n,&q);
	for(int i=0;i<n;i++){
		scanf("%d",&val[i]);
		fir[i]=-1;
	}
	for(int i=1;i<n;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		add(a-1,b-1); add(b-1,a-1);
	}
	dfs(0,-1);
	for(int i=0;i<n;i++){
		up[0][i]=i;
		for(int j=0;j<B;j++)
			if(up[0][i]!=-1){
				wei[j]=(val[up[0][i]]^j);
				up[0][i]=fat[up[0][i]];
			}
			else wei[j]=0;
		build_table(i);
	}
	for(int i=1;i*B<n;i++)
		for(int j=0;j<n;j++)
			if(up[i-1][j]!=-1)
				up[i][j]=up[0][up[i-1][j]];
	while(q--){
		int a,b,ans=0,x=0,y=0;
		scanf("%d%d",&a,&b);
		a--; b--;
		while(dep[b]-dep[a]>=B){
			ans=max(ans,maxv[x][b]); x++;
			b=up[0][b];
		}
		while(b!=a){
			ans=max(ans,(x*B+y)^val[b]); y++;
			b=fat[b];
		}
		ans=max(ans,(x*B+y)^val[b]);
		printf("%d\n",ans);
	}
	return 0;
}