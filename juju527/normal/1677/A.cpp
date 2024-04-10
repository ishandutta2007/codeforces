#include<bits/stdc++.h>
typedef long long ll;
#define pii pair<int,int>
#define fi first
#define se second
#define vec vector<int>
#define eb emplace_back
using namespace std;
const int maxn=5005;
int p[maxn];
int pre[maxn][maxn],suf[maxn][maxn];
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<48||ch>57){if(ch==45)y=-1;ch=getchar();}
    while(ch>=48&&ch<=57)x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
int main(){
    int T;
	T=read();
	while(T--){
		int n;
		n=read();
		ll res=0;
		for(int i=1;i<=n;i++)p[i]=read(),suf[n+1][i]=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++)pre[i][j]=pre[i-1][j];
			for(int j=p[i];j<=n;j++)pre[i][j]++;
		}
		for(int i=n;i>=1;i--){
			for(int j=1;j<=n;j++)suf[i][j]=suf[i+1][j];
			for(int j=p[i];j<=n;j++)suf[i][j]++;
		}
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				res+=1ll*pre[i-1][p[j]]*suf[j+1][p[i]];
		printf("%lld\n",res);
	}
    return 0;
}