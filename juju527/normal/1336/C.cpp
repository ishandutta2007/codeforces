#include <bits/stdc++.h>
using namespace std;
const int maxn=3005,mod=998244353;
int n,m;
char s[maxn],t[maxn];
int f[maxn][maxn];
//f[i][j]s[1]~s[j-i+1]t[i]~t[j]
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<48||ch>57){if(ch==45)y=-1;ch=getchar();}
    while(ch>=48&&ch<=57)x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
int main(){
//    freopen("CF1336C.in","r",stdin);
//    freopen("CF1336C.out","w",stdout);
   	scanf("%s",s+1);n=strlen(s+1);
    scanf("%s",t+1);m=strlen(t+1);
	for(int i=1;i<=n;i++)f[i][i]=2*(t[i]==s[1]||i>m);
	for(int len=2;len<=n;len++){
		for(int i=1;i<=n-len+1;i++){
			int j=i+len-1;
			if(s[j-i+1]==t[i]||i>m)(f[i][j]+=f[i+1][j])%=mod;
			if(s[j-i+1]==t[j]||j>m)(f[i][j]+=f[i][j-1])%=mod;
		}
	}
	int ans=0;
	for(int i=m;i<=n;i++)(ans+=f[1][i])%=mod;
	printf("%d\n",ans);
	return 0;
}