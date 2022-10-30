#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define M 1000000007
int i,j,k,t,m,a[505],n;
ll p[505]={1},res;

int main(){
	scanf("%d",&n);
	for(i=1;i<=500;i++){
		p[i]=p[i-1]*2%M;
	}
	for(i=1;i<=n;i++){
		scanf("%d",&k);
		if(k==-1){a[i]++;}
		else{a[k]++;}
	}
	res=1-p[n-1];
	for(i=1;i<=n;i++){
		if(!a[i]){continue;}
		res-=1-p[a[i]-1];
	}
	res=((M-res)%M+M)%M;
	printf("%lld",res);
}