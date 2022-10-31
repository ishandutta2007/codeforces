#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int i,j,k,n,m;
ll res,a[100500];

int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	res+=a[1]*(n-a[1]+1);
	for(i=2;i<=n;i++){
		if(a[i-1]>a[i]){
			res+=(a[i-1]-a[i])*a[i];
		}
		else{
			res+=(n-a[i]+1)*(a[i]-a[i-1]);
		}
	}
	printf("%lld",res);
}