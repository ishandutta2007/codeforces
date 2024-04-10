//Code by juju527.
#include<bits/stdc++.h>
typedef long long ll;
#define pii pair<int,int>
#define fi first
#define se second
#define vec vector
#define eb emplace_back
using namespace std;
const int maxm=55,mod=998244353;
int n,m,k;
ll read(){
    ll x=0,y=1;
    char ch=getchar();
    while(ch<48||ch>57){if(ch==45)y=-1;ch=getchar();}
    while(ch>=48&&ch<=57)x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
inline int add(int x){return (x>=mod)?x-mod:x;}
inline void add(int &x,int y){x=add(x+y);return ;}
inline int sub(int x){return (x<0)?x+mod:x;}
inline void sub(int &x,int y){x=sub(x-y);return ;}
inline int power(int x,int b){
	int res=1;
	while(b){
		if(b&1)res=1ll*res*x%mod;
		x=1ll*x*x%mod;
		b>>=1;
	}
	return res;
}
int f[maxm];
ll p[maxm];
bool ins(ll x){
	for(int i=m-1;i>=0;i--){
		if(!((x>>i)&1))continue;
		if(!p[i]){p[i]=x;return 1;}
		x^=p[i];
	}
	return 0;
}
vec<ll> a;
void dfs1(int x,ll aux){
	if(x==k){f[__builtin_popcountll(aux)]++;return ;}
	dfs1(x+1,aux);dfs1(x+1,aux^a[x]);
	return ;
}
void solve1(){
	for(int i=0;i<m;i++)if(p[i])a.eb(p[i]);
	dfs1(0,0);
	return ;
}
int C[maxm][maxm];
int buf[maxm][maxm];
int cnt[maxm];
ll q[maxm];
void dfs2(int x,ll aux){
	if(x==m-k){cnt[__builtin_popcountll(aux)]++;return ;}
	dfs2(x+1,aux);dfs2(x+1,aux^a[x]);
	return ;
}
void deal(){
	for(int i=0;i<m;i++){
		if(!p[i])continue;
		for(int j=i+1;j<m;j++)if((p[j]>>i)&1)p[j]^=p[i];
	}
	for(int i=0;i<m;i++)
		for(int j=0;j<m;j++)
			if((p[i]>>j)&1)q[j]|=(1ll<<i);
	for(int i=0;i<m;i++)q[i]^=(1ll<<i);
	for(int i=0;i<m;i++)if(q[i])a.eb(q[i]);
	dfs2(0,0);
	return ;
}
void solve2(){
	C[0][0]=1;
	for(int i=1;i<=m;i++){
		C[i][0]=1;
		for(int j=1;j<=i;j++)C[i][j]=add(C[i-1][j]+C[i-1][j-1]);
	}
	for(int a=0;a<=m;a++){
		for(int c=0;c<=m;c++){
			int sum=0;
			for(int b=0;b<=c;b++){
				int val=1ll*C[m-a][c-b]*C[a][b]%mod;
				if(b&1)sub(sum,val);else add(sum,val);
			}
			buf[a][c]=sum;
		}
	}
	deal();
	for(int c=0;c<=m;c++){
		int sum=0;
		for(int a=0;a<=m;a++)add(sum,1ll*cnt[a]*buf[a][c]%mod);
		f[c]=1ll*sum*power(2,k-m+mod-1)%mod;
	}
	return ;
}
int main(){
    n=read();m=read();
	for(int i=1;i<=n;i++)k+=ins(read());
	if(k<=26)solve1();else solve2();
	int v=power(2,n-k);
	for(int i=0;i<=m;i++)printf("%d ",(int)(1ll*f[i]*v%mod));
	puts("");
    return 0;
}