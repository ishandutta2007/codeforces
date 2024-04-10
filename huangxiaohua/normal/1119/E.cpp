#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t;
ll res,a[300500],t1,t2,sum;
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	for(i=1;i<=n;i++){
		sum+=a[i];
		t1=min(a[i]/2,t2);
		res+=t1;a[i]-=t1*2;
		res+=a[i]/3;
		t2=sum-res*3;
	}
	printf("%lld",res);
}