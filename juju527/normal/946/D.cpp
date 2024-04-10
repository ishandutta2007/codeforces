#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=505;
char s[maxn];
int a[maxn];
int p[maxn];
int mn[maxn][maxn];
int f[maxn][maxn];
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<48||ch>57){if(ch==45)y=-1;ch=getchar();}
    while(ch>=48&&ch<=57)x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
int main(){
	int n,m,k;
	n=read();m=read();k=read();
	memset(mn,0x3f,sizeof(mn));
	for(int i=1;i<=n;i++){
		scanf("%s",s+1);
		int len=0;
		for(int j=1;j<=m;j++)if(s[j]=='1')a[++len]=j;
		mn[i][len]=0;
		p[i]=len;
		for(int j=1;j<=len;j++)
			for(int l=j;l<=len;l++)
				mn[i][len-(l-j+1)]=min(mn[i][len-(l-j+1)],a[l]-a[j]+1);
	}
	memset(f,0x3f,sizeof(f));
	for(int i=0;i<=k;i++)f[0][i]=0;
	for(int i=1;i<=n;i++)
		for(int j=0;j<=k;j++)
			for(int l=0;l<=min(j,p[i]);l++)
				f[i][j]=min(f[i][j],f[i-1][j-l]+mn[i][l]);
    printf("%d\n",f[n][k]);
	return 0;
}