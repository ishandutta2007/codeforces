#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 998244353

int i,j,k,n,m,t,l[55],r[55],cnt;
int g[100500],f[2][100500];
int su(int a,int b){a+=b;return (a>=M)?a-M:a;}

void get(int x){
	int i,j,k,res=0,l1,r1,len=m/x,i1,i0;
	for(i=1;i<=n;i++){
		i1=i&1;
		i0=1-i1;
		r1=(r[i]/x);
		l1=((l[i]+x-1)/x);
		if(l1>r1){return;}
		if(i==1){
			for(j=l1;j<=r1;j++){f[i1][j]=1;}
		}
		else{
			for(j=1;j<=len;j++){
				if(j<=l1){f[i1][j]=0;continue;}
				if(j<=r1+1){f[i1][j]=f[i0][j-l1];}
				else{f[i1][j]=su(f[i0][j-l1],M-f[i0][j-r1-1]);}
			}
		}
		for(j=1;j<=len;j++){
			f[i1][j]=su(f[i1][j-1],f[i1][j]);
		}
	}
	g[x]=f[n&1][len];
}

int main(){
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++){
		scanf("%d%d",&l[i],&r[i]);
	}
	for(i=1;i<=m;i++){get(i);}
	for(i=m;i>=1;i--){
		for(j=i+i;j<=m;j+=i){g[i]=su(g[i],M-g[j]);}
	}
	printf("%d",g[1]);
}