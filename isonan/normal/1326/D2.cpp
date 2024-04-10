#include <cstdio>
#include <cstring> 


const int P=998244353;
inline int mul(const int &a,const int &b){return 1ll*a*b%P;}
int con[600001][2],top;
int son[1000010][26];
int nxt[1000010],len[1000010],cnt,last,N;
int fa[1000010][21];
bool vis[1000010];
int S[1000010];
char str[1000010];
void init(){
	for(int i=0;i<=cnt;i++)memset(son[i],0,sizeof son[i]),len[i]=nxt[i]=0;
	len[0]=0;
	len[1]=-1;
	cnt=1,last=0;
	S[N=0]=-1;
	nxt[0]=1;
}
int fail(int x){
	while(S[N]!=S[N-len[x]-1])x=nxt[x];
	return x;
}
void add(int x){
	S[++N]=x;
	int cur=fail(last);
	if(!son[cur][x]){
		int now=++cnt;
		len[now]=len[cur]+2;
		nxt[now]=son[fail(nxt[cur])][x];
		son[cur][x]=now;
	}
	last=son[cur][x];
}
int t;
int pos[1000001];
int main(){
	scanf("%d",&t);
	for(int fd=1;fd<=t;fd++){
		scanf("%s",str+1);
		int n=strlen(str+1);
		int p=0;
		for(int i=1;i<=n;i++){
			if(str[i]!=str[n-i+1]){
				p=i-1;
				break;
			}
		}
		if(n-p+1<=p){
			for(int i=1;i<=n;i++)putchar(str[i]);
			continue;
		}
		init();
		for(int i=n;i;i--)add(str[i]-'a'),pos[i]=last;
		for(int i=0;i<=cnt;i++)fa[i][0]=nxt[i];
		for(int j=1;j<=20;j++)
			for(int i=0;i<=cnt;i++)
				fa[i][j]=fa[fa[i][j-1]][j-1];
		int ans=0,l=0,r=n+1;
		for(int i=0;i<=p;i++){
			int tem=pos[i+1],x=n-(i<<1);
			for(int j=20;~j;--j)
				if(len[fa[tem][j]]>x)tem=fa[tem][j];
			if(len[tem]>x)tem=nxt[tem];
//			printf("%d %d\n",i,len[tem]);
			if(ans<len[tem]+(i<<1)){
				ans=len[tem]+(i<<1);
				l=i+len[tem];
				r=n-i+1;
			}
		}
		init();
//		printf("%d %d %d\n",ans,l,r);
		for(int i=1;i<=n;i++)add(str[i]-'a'),pos[i]=last;
		for(int i=0;i<=cnt;i++)fa[i][0]=nxt[i];
		for(int j=1;j<=20;j++)
			for(int i=0;i<=cnt;i++)
				fa[i][j]=fa[fa[i][j-1]][j-1];
		for(int i=0;i<=p;i++){
			int tem=pos[n-i],x=n-(i<<1);
			for(int j=20;~j;--j)
				if(len[fa[tem][j]]>x)tem=fa[tem][j];
			if(len[tem]>x)tem=nxt[tem];
			if(ans<len[tem]+(i<<1)){
				ans=len[tem]+(i<<1);
				r=n-i-len[tem]+1;
				l=i;
			}
		}
//		printf("%d %d %d\n",ans,l,r);
		for(int i=1;i<=l;i++)putchar(str[i]);
		for(int i=r;i<=n;i++)putchar(str[i]);
		putchar('\n');
	}
}