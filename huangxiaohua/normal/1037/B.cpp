#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 1000000007

int i,j,k,n,m,t,b[1000500],a[1000500];
ll res;
int main(){
	scanf("%d%d",&n,&k);
	m=(n+1)/2;
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+n+1);
	if(k>=a[m]){
		for(i=m;i<=n;i++){
			res+=max(0,k-a[i]);
		}
	}
	else{
		for(i=1;i<=m;i++){
			res+=max(0,a[i]-k);
		}
	}
	printf("%lld",res);
}