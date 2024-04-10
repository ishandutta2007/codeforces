#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,a[1005000],sb,res;

int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		a[i]=(a[i-1]^i);
	}
	for(i=1;i<=n;i++){
		scanf("%d",&sb);
		res^=sb;
		res^=a[n%i];
		k=n/i;
		if(k&1){res^=a[i-1];}
	}
	printf("%d",res);
}