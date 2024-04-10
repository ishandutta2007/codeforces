#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,a[2050];
ll f[100500];
#define M 1000000007

int main(){
	f[1]=1;
	f[2]=2;
	for(i=3;i<=100000;i++){
		f[i]=(f[i-1]+f[i-2])%M;
	}
	scanf("%d%d",&n,&m);
	printf("%lld",2*(f[n]+f[m]-1)%M);
}