//Code by juju527.
#include<bits/stdc++.h>
typedef long long ll;
#define pii pair<int,int>
#define fi first
#define se second
#define vec vector<int>
#define eb emplace_back
using namespace std;
const int maxn=2e5+5,inf=1e9;
int p[maxn];
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<48||ch>57){if(ch==45)y=-1;ch=getchar();}
    while(ch>=48&&ch<=57)x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
int f[maxn][2];
int main(){
    int n;ll res=0;
	n=read();
	for(int i=1;i<=n;i++)p[i]=read();
	for(int i=n,k=n;i>=1;i--){
		f[i][0]=inf,f[i][1]=-inf;
		for(int j=i+1;j<=n;j++){
			int v0=-inf,v1=inf;
			if(p[j]>p[j-1]){
				v0=f[j-1][0];
				if(f[j-1][1]<p[j])v0=max(v0,p[j-1]);
				if(f[j-1][0]>p[j])v1=p[j-1];else v1=inf;
			}
			else{
				v1=f[j-1][1];
				if(f[j-1][0]>p[j])v1=min(v1,p[j-1]);
				if(f[j-1][1]<p[j])v0=p[j-1];else v0=-inf;
			}
			if(v0==f[j][0]&&v1==f[j][1])break;
			f[j][0]=v0,f[j][1]=v1;
		}
		while(k>i&&f[k][0]==-inf&&f[k][1]==inf)k--;
		res+=k-i+1;
	}
	printf("%lld\n",res);
    return 0;
}