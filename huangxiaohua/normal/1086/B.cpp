#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,t,n,m,a[100500],res;

int main(){
	scanf("%d%d",&n,&m);
	for(i=1;i<n;i++){
		scanf("%d%d",&j,&k);
		a[j]++;a[k]++;
	}
	for(i=1;i<=n;i++){
		res+=(a[i]==1);
	}
	printf("%.20lf",m*1.0/res*2);
}