#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=3005;
int a[maxn];
int f[maxn][maxn];
int nxt0[maxn],pre0[maxn];
int nxt1[maxn];
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<48||ch>57){if(ch==45)y=-1;ch=getchar();}
    while(ch>=48&&ch<=57)x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
int main(){
//    freopen("CF1572C.in","r",stdin);
//    freopen("CF1572C.out","w",stdout);
    int T;
	T=read();
	while(T--){
		int n;
		n=read();
		for(int i=1;i<=n;i++)a[i]=read();
		for(int i=1;i<=n;i++){
			pre0[i]=0;nxt0[i]=nxt1[i]=n+1;
			for(int j=i-1;j>=1;j--)if(a[j]^a[i]){pre0[i]=j;break;}
			for(int j=i+1;j<=n;j++)if(a[j]^a[i]){nxt0[i]=j;break;}
			for(int j=i+1;j<=n;j++)if(a[j]==a[i]){nxt1[i]=j;break;}
		}
		for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++)f[i][j]=1e9;
		for(int len=2;len<=n;len++){
			for(int i=1;i<=n-len+1;i++){
				int j=i+len-1;
				f[i][j]=min(f[nxt0[i]][j],f[i][pre0[j]])+1;
				for(int k=nxt1[i];k<=j;k=nxt1[k])f[i][j]=min(f[i][j],f[i][k-1]+f[k][j]);
			}
		}
		printf("%d\n",f[1][n]);
	}
    return 0;
}