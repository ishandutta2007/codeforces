//Code by juju527.
#include<bits/stdc++.h>
typedef long long ll;
#define pii pair<int,int>
#define fi first
#define se second
#define vec vector<int>
#define eb emplace_back
using namespace std;
const int maxn=1e3+5,maxd=55,mod=1e9+7;
int n,d;
char s[maxn],limx[maxd],limy[maxd];
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<48||ch>57){if(ch==45)y=-1;ch=getchar();}
    while(ch>=48&&ch<=57)x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
int tot=1,lst=1;
int to[2*maxn][10];
int nxt[2*maxn],len[2*maxn];
void extend(int c){
	int u=++tot,p=lst;
	len[u]=len[p]+1;
	while(p&&!to[p][c])to[p][c]=u,p=nxt[p];
	if(!p)nxt[u]=1;
	else{
		int d=to[p][c];
		if(len[d]==len[p]+1)nxt[u]=d;
		else{
			int v=++tot;
			for(int i=0;i<10;i++)to[v][i]=to[d][i];
			len[v]=len[p]+1;nxt[v]=nxt[d];nxt[d]=nxt[u]=v;
			while(p&&to[p][c]==d)to[p][c]=v,p=nxt[p];
		}
	}
	lst=u;
	return ;
}
inline int add(int x){return (x>=mod)?x-mod:x;}
inline void trans(int &x,int y){x=add(x+y);return ;}
inline int sub(int x){return (x<0)?x+mod:x;}
int f[maxd][2*maxn][maxd][2][2];
pii dfs(int p,int l,int c){
	while(p&&!to[p][c])l=len[p=nxt[p]];
	if(!p)p=1,l=0;else p=to[p][c],l++;
	return pii(p,l);
}
int dp(char *lim){
	memset(f,0,sizeof(f));
	f[0][1][0][1][0]=1;
	for(int i=0;i<d;i++){
		for(int x=1;x<=tot;x++){
			for(int l=len[nxt[x]]+1;l<=len[x]&&l<=i;l++){
				for(int v=0;v<10;v++){
					pii s=dfs(x,l,v);
					trans(f[i+1][s.fi][s.se][0][s.se>=(d/2)],f[i][x][l][0][0]);
					trans(f[i+1][s.fi][s.se][0][1],f[i][x][l][0][1]);
					if(v<lim[i+1]-'0')
						trans(f[i+1][s.fi][s.se][0][s.se>=(d/2)],f[i][x][l][1][0]),
						trans(f[i+1][s.fi][s.se][0][1],f[i][x][l][1][1]);
					else if(v==lim[i+1]-'0')
						trans(f[i+1][s.fi][s.se][1][s.se>=(d/2)],f[i][x][l][1][0]),
						trans(f[i+1][s.fi][s.se][1][1],f[i][x][l][1][1]);
				}
			}
		}
	}
	int res=0;
	for(int x=1;x<=tot;x++)
		for(int l=len[nxt[x]]+1;l<=len[x]&&l<=d;l++)
			res=add(res+add(f[d][x][l][0][1]+f[d][x][l][1][1]));
	return res;
}
int main(){
    scanf("%s",s+1);n=strlen(s+1);
	len[0]=-1;
	for(int i=1;i<=n;i++)extend(s[i]-'0');
	scanf("%s",limx+1);scanf("%s",limy+1);
	d=strlen(limx+1);
	for(int i=d;i>=1;i--){
		if(limx[i]>'0'){
			limx[i]--;
			for(int j=i+1;j<=d;j++)limx[j]='9';
			break;
		}
	}
	printf("%d\n",sub(dp(limy)-dp(limx)));
    return 0;
}