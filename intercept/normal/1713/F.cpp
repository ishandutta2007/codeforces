#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;
const int M=5e5+9;
int n;
int a[M],b[M],c[M][23],d[M][23];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&d[i][0]);
	for(int i=n,j=0;i>=1;--i,++j){
		b[i]=d[i][0];
		for(int k=0;k<20;++k){
			if(j>>k&1)b[i]^=d[i+(1<<k)][k];
			d[i][k+1]=b[i];
		}
		c[i][0]=b[i];
	}
	for(int i=1;i<=n;++i){
		a[i]=c[i][0];
		for(int j=0;j<20;++j){
			if((n>>j&1)&&i-(1<<j)>=0)a[i]^=c[i-(1<<j)][j];
			c[i][j+1]=a[i];
		}
		printf("%d%c",a[i]," \n"[i==n]);
	}
	return 0;
}