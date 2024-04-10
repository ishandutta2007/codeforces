#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
 
using namespace __gnu_pbds;
using namespace std;

typedef long long ll;
#define M 1000000007

int i,j,k,n,t,a[105],p,x,y,res=666;

void chk(int l,int r){
	int nmsl1,nmsl2,i,j,k;
	for(i=l;i<r;i++){
		nmsl1=nmsl2=0;
		for(j=l;j<=i;j++){
			nmsl1^=a[j];
		}
		for(j=i+1;j<=r;j++){
			nmsl2^=a[j];
		}
		//printf("%d %d %d %d %d\n",l,i,r,nmsl1,nmsl2);
		if(nmsl1<a[l-1]||nmsl2<nmsl1||a[r+1]<nmsl2){res=min(res,r-l-1);return;}
	}
}

int main(){
	scanf("%d",&n);
	if(n>=70){puts("1");return 0;}
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}a[0]=-2e9,a[n+1]=2e9;
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			chk(i,j);
		}
	}
	if(res==666){res=-1;}
	printf("%d",res);
}