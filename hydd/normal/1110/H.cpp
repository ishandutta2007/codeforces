/*********************************************************************
 * Source
 * Problem
 * Authorhydd
 * Date
 * EncodingSimplified Chinese (GB2312)
*********************************************************************/
#include<cstdio>
#include<queue>
#include<cstring>
#include<algorithm>
#define File(x) freopen(x".in","r",stdin);freopen(x".out","w",stdout)
using namespace std;
const int INF=0x3f3f3f3f;
int n,len_l,len_r,len,l[2100],r[2100],s[2100];
int cnt,fail[41000],ch[41000][10],c[41000][2100],f[2100][41000],g[2100][41000];
char L[2100],R[2100];
void dfs(int now,bool lim1,bool lim2){
	if (!now||(!lim1&&!lim2)){
		int i=len,u=0;
		for (;i>now&&(!s[i]);i--);
		for (;i>now;i--){
			if (!ch[u][s[i]]) ch[u][s[i]]=++cnt;
			u=ch[u][s[i]];
		}
		c[u][now]++; return;
	}
	int L=lim1?l[now]:0,R=lim2?r[now]:9;
	for (int i=L;i<=R;i++) s[now]=i,dfs(now-1,lim1&&(i==L),lim2&&(i==R));
}
queue<int> q;
void build(){
	for (int i=0;i<=9;i++)
		if (ch[0][i]) q.push(ch[0][i]);
	while (!q.empty()){
		int u=q.front(); q.pop();
		for (int i=0;i<=9;i++)
			if (ch[u][i]){
				fail[ch[u][i]]=ch[fail[u]][i];
				q.push(ch[u][i]);
			} else ch[u][i]=ch[fail[u]][i];
	}
}
int main(){
	scanf("%s%s%d",L+1,R+1,&n);
	len_l=strlen(L+1); len_r=strlen(R+1);
	reverse(L+1,L+len_l+1); reverse(R+1,R+len_r+1);
	if (len_l>len_r){ puts("0"); return 0;}
	for (int i=1;i<=len_l;i++) l[i]=L[i]-'0';
	for (int i=1;i<=len_r;i++) r[i]=R[i]-'0';
	len=len_r;
	dfs(len,true,true); build();
	for (int i=1;i<=cnt;i++)
		for (int j=0;j<=n;j++) c[i][j]+=c[fail[i]][j];
	for (int i=1;i<=cnt;i++)
		for (int j=1;j<=n;j++) c[i][j]+=c[i][j-1];
	int tmp;
	for (int i=1;i<=n;i++)
		for (int j=0;j<=cnt;j++){
			f[i][j]=-INF;
			for (int x=0;x<=9;x++){
				tmp=f[i-1][ch[j][x]]+c[ch[j][x]][i-1];
				if (tmp>f[i][j]) f[i][j]=tmp,g[i][j]=x;
			}
		}
	printf("%d\n",f[n][0]);
	int x=0,c;
	for (int i=n;i;i--){
		c=g[i][x]; putchar(c+'0');
		x=ch[x][c];
	}
	return 0;
}