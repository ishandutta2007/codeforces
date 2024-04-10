#include<bits/stdc++.h>
#define ll long long 
#define eb emplace_back
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;
const int mod=998244353;
int kpow(int x,int y,int rex=1){
    for(;y;y>>=1,x=1ll*x*x%mod)if(y&1)rex=1ll*x*rex%mod;
    return rex;
}
int exgcd(int a,int b,int &x,int &y){
    int t=b?exgcd(b,a%b,y,x):a;
    if(!b)x=1,y=0;
    else y-=a/b*x;
    return t;
}
int n,m,k;
struct mat{
	int l;
	int a[209][209];
	mat(){
		l=200;
		memset(a,0,sizeof(a));
	}
	mat operator * (const mat&o){
		mat rex;
		for(int i=1;i<=l;++i)
		for(int j=1;j<=l;++j)
		for(int k=1;k<=l;++k)
			rex.a[i][j]=(rex.a[i][j]+1ll*a[i][k]*(o.a[k][j])%mod)%mod;
		return rex;
	}
};

int d[109];
mat kpow(mat x,int y){
	mat rex;
	rex=x;
	for(int i=1;i<=n;++i)x.a[i][i+n]++;
	for(;y;y>>=1,x=x*x)if(y&1)rex=rex*x;
	return rex;
}

int main(){
	mat a;
	cin>>n>>m>>k;
	for(int i=1;i<=m;++i){
		int u,v;
		cin>>u>>v;
		a.a[u][v]=a.a[v][u]=1;
		d[u]++;
		d[v]++;
	}
	for(int i=1;i<=n;++i)a.a[i][i+n]=mod-d[i],a.a[i+n][i]=1;
	k--;
	a=kpow(a,k);
	int ans=0;
	for(int i=1;i<=n;++i)ans=(ans+a.a[i][i])%mod;
	cout<<ans<<endl;
	return 0;
}
/*
4 5 1
4 1
2 3
3 1
4 3
2 4

*/