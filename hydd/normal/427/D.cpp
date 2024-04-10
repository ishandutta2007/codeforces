#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int S=1;
const int INF=0x3f3f3f3f;
int z,n,m,cnt,sz[210000],f[210000],g[210000],len[210000],ans;
int link[210000],trans[210000][27];
char s[110000],t[110000];
void add(int c,int *sz){
    int v=z,l=len[z];
    z=++cnt; len[z]=l+1;
    for (;v&&!trans[v][c];v=link[v]) trans[v][c]=z;
    if (!v) link[z]=S;
    else{
        int x=trans[v][c];
        if (len[v]+1==len[x]) link[z]=x;
        else{
            int y=++cnt; len[y]=len[v]+1; f[y]=f[x]; g[y]=g[x];
            for (int i=0;i<=26;i++) trans[y][i]=trans[x][i];
            link[y]=link[x]; link[x]=y; link[z]=y;
            for (;trans[v][c]==x;v=link[v]) trans[v][c]=y;
        }
    }
    int now=z;
    while (now&&sz[now]<=1) sz[now]++,now=link[now];
}
int main(){
    scanf("%s",s+1); n=strlen(s+1);
    scanf("%s",t+1); m=strlen(t+1);
	cnt=1;
    z=1; for (int i=1;i<=n;i++) add(s[i]-'a',f);
    z=1; for (int i=1;i<=m;i++) add(t[i]-'a',g);
    ans=INF;
	for (int i=2;i<=cnt;i++)
		if (f[i]==1&&g[i]==1) ans=min(ans,len[link[i]]+1);
	if (ans==INF) puts("-1");
    else printf("%d\n",ans);
    return 0;
}