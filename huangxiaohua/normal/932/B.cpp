#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define M 1000000007

int i,j,k,n,m,t,a[1005000][10];

int f(int x){
	int i,res=1;
	while(x){
		i=x%10;x/=10;
		if(i){res*=i;}
	}
	return res;
}

int g(int x){
	if(x<10){return x;}
	return g(f(x));
}

int main(){
	for(i=1;i<=1000000;i++){
		memcpy(a[i],a[i-1],sizeof(a[i-1]));
		a[i][g(i)]++;
	}
	scanf("%d",&t);
	while(t--){
		scanf("%d%d%d",&i,&j,&k);
		printf("%d\n",a[j][k]-a[i-1][k]);
	}
}