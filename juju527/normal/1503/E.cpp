//Code by juju527.
#include<bits/stdc++.h>
typedef long long ll;
#define pii pair<int,int>
#define fi first
#define se second
#define vec vector<int>
#define eb emplace_back
using namespace std;
const int maxn=2505,mod=998244353;
int c[2*maxn][2*maxn];
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<48||ch>57){if(ch==45)y=-1;ch=getchar();}
    while(ch>=48&&ch<=57)x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
inline int add(int x){return (x>=mod)?x-mod:x;}
inline void add(int &x,int y){x=add(x+y);return ;}
int suf[maxn];
inline int calc(int n,int m,bool op){
	int cur=0;
	for(int i=1;i<n;i++){
		suf[m]=0;
		for(int k=m-1;k>=1;k--)
			suf[k]=add(suf[k+1]+1ll*c[i-1+k][k]*c[i+m-k-1][i]%mod);
		for(int j=1;j<m;j++){
			int val=1ll*c[n-i+j-1][j-1]*c[n-i-1+m-j][m-j]%mod;
			add(cur,1ll*val*suf[j+op]%mod);
		}
	}
	return add(cur+cur);
}
int main(){
    int n,m;
	n=read();m=read();
	c[0][0]=1;
	for(int i=1;i<=n+m;i++){
		c[i][0]=1;
		for(int j=1;j<=i;j++)c[i][j]=add(c[i-1][j]+c[i-1][j-1]);
	}
	int res=add(calc(n,m,0)+calc(m,n,1));
	printf("%d\n",res);
    return 0;
}