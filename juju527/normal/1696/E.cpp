#include<bits/stdc++.h>
typedef long long ll;
#define pii pair<int,int>
#define fi first
#define se second
#define mp make_pair
#define vec vector<int>
#define eb emplace_back
using namespace std;
const int maxn=5e5+5,N=5e5,mod=1e9+7;
int fc[maxn],ifc[maxn];
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<48||ch>57){if(ch==45)y=-1;ch=getchar();}
    while(ch>=48&&ch<=57)x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
inline int add(int x){return (x>=mod)?x-mod:x;}
inline int sub(int x){return (x<0)?x+mod:x;}
inline int power(int x,int b){
	int res=1;
	while(b){
		if(b&1)res=1ll*res*x%mod;
		x=1ll*x*x%mod;
		b>>=1;
	}
	return res;
}
void init(){
	fc[0]=1;for(int i=1;i<=N;i++)fc[i]=1ll*fc[i-1]*i%mod;
	ifc[N]=power(fc[N],mod-2);for(int i=N-1;i>=0;i--)ifc[i]=1ll*ifc[i+1]*(i+1)%mod;
	return ;
}
inline int binom(int n,int m){
	if(n<0||n<m)return 0;
	return 1ll*fc[n]*ifc[m]%mod*ifc[n-m]%mod;
}
int main(){
    int n,res=0;
	n=read();
	init();
	for(int i=0;i<=n;i++){
		int x;
		x=read()-1;
		res=add(res+binom(i+1+x,x));
	}
	printf("%d\n",res);
    return 0;
}