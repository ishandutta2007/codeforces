#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
inline int read(){
	int x=0,f=1;char ch;
	do{ch=getchar();if(ch=='-')f=-1;}while(ch<'0'||ch>'9');
	do{x=x*10+ch-'0';ch=getchar();}while(ch>='0'&&ch<='9');
	return x*f;
}
const int N=2010,M=210;
char a[N][M],b[M][N];
const ll Base=127,MOD=1e9+7;
ll Hash1[N],Pow[N];
ll Hash2[M][N];
int n,m;
bool check(int x,int y){
	for (int i=1;i<=m;++i){
		for (int j=1;j<=m;++j){
			if (a[x+i-1][j]!=b[i][y+j-1])
			return 0;
		}
	}
	return 1;
}
int main(){
	n=read(),m=read();
	Pow[0]=1;
	for (int i=1;i<=n;++i) Pow[i]=Pow[i-1]*Base%MOD;
	for (int i=1;i<=n;++i) scanf("%s",a[i]+1);
	for (int i=1;i<=m;++i) scanf("%s",b[i]+1);
	for (int i=1;i<=n;++i){
		for (int j=1;j<=m;++j){
			Hash1[i]=(Hash1[i]*Base+(ll)a[i][j])%MOD;
		}
	}
	for (int i=1;i<=n;++i){
		Hash1[i]=(Hash1[i-1]*Base+Hash1[i])%MOD;
	}
	for (int i=1;i<=m;++i){
		for (int j=1;j<=n;++j) Hash2[i][j]=(Hash2[i][j-1]*Base+(ll)b[i][j])%MOD;
	}
	for (int j=1;j<=n-m+1;++j){
		ll th=0;
		for (int i=1;i<=m;++i){
			ll Ha=(Hash2[i][j+m-1]-Hash2[i][j-1]*Pow[m]%MOD+MOD)%MOD;
			th=(th*Base+Ha)%MOD;
		}
		bool gfg=0;
		for (int i=1;i<=n-m+1;++i){
			ll Ha=(Hash1[i+m-1]-Hash1[i-1]*Pow[m]%MOD+MOD)%MOD;
			if (Ha==th){
				if (check(i,j)){
					gfg=1;
					printf("%d %d\n",i,j);
					break;
				}
			}
		}
		if (gfg) break;
	}
	return 0;
}