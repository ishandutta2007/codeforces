#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ll long long
#define fi first
#define se second
#define db double
using namespace std;
inline int read(){
	int res=0,f=1;char ch=getchar();
	while(!isdigit(ch)) {if(ch=='-') f=-f;ch=getchar();}
	while(isdigit(ch)) {res=(res<<1)+(res<<3)+(ch^48);ch=getchar();}
	return res*f;
}
const int N=2005;
int r[2000000],c[2000000];
int ans[N][N];
const ll mod=1e9+7;
inline ll ksm(ll a,int b){
	ll res=1;
	for(;b;b>>=1,a=1ll*a*a%mod) if(b&1) res=1ll*res*a%mod;
	return res; 
}
ll p[2000000]; 
int main(){
	int h=read(),w=read();
	p[0]=1;
    for(int i=1;i<=1500000;++i) p[i]=p[i-1]*2%mod;
	for(int i=1;i<=h;i++) r[i]=read();
	for(int i=1;i<=w;i++) c[i]=read();
	memset(ans,-1,sizeof(ans));
	int f=1;
	for(int i=1;i<=h;i++){
		for(int j=1;j<=r[i];j++) {if(ans[i][j]==0) f=0;ans[i][j]=1;}
		if(ans[i][r[i]+1]==1) f=0;ans[i][r[i]+1]=0;
	}
	for(int i=1;i<=w;i++){
		for(int j=1;j<=c[i];j++) {if(ans[j][i]==0) f=0;ans[j][i]=1;}
		if(ans[c[i]+1][i]==1) f=0;ans[c[i]+1][i]=0;
	}
	if(!f) {cout<<"0";return 0;}
	int cnt=0;
	for(int i=1;i<=h;i++)
		for(int j=1;j<=w;j++) if(ans[i][j]==-1) ++cnt;
    cout<<p[cnt];
	return 0;
}