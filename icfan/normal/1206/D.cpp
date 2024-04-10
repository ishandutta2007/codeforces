#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
#define Maxn 100000
#define ll long long
#define Inf 1000000
vector<ll> a[70];
ll x[Maxn+5];
ll y[Maxn+5];
int f[205][205];
int edge[205][205];
int mn(int a,int b){
	return a<b?a:b;
}
int main(){
	int n;
	int m=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		cin>>x[i];
		if(x[i]!=0){
			y[++m]=x[i];
		}
		for(int j=0;j<63;j++){
			if(x[i]&(1ll<<j)){
				a[j].push_back(x[i]);
			}
		}
	}
	for(int i=0;i<63;i++){
		if((int)a[i].size()>=3){
			puts("3");
			return 0;
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			edge[i][j]=f[i][j]=Inf;
		}
	}
	for(int i=1;i<=m;i++){
		edge[i][i]=f[i][i]=0;
	}
	for(int i=1;i<=m;i++){
		for(int j=i+1;j<=m;j++){
			if(y[i]&y[j]){
				edge[i][j]=edge[j][i]=1;
				f[i][j]=f[j][i]=1;
			}
		}
	}
	int ans=Inf;
	for(int k=1;k<=m;k++){
		for(int i=1;i<k;i++){
			for(int j=i+1;j<k;j++){
				ans=mn(ans,edge[i][k]+edge[k][j]+f[i][j]);
			}
		}
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				f[i][j]=mn(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
	if(ans>m){
		puts("-1");
	}
	else{
		printf("%d\n",ans);
	}
	return 0;
}