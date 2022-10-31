#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,a[100500];
ll res,b[100500],sum;
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);sum=0;res=0;
		for(i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		sort(a+1,a+n+1);
		sum=a[n];
		for(i=1;i<n;i++){
			b[i]=a[i+1]-a[i];
		}
		n--;
		for(i=1;i<=n;i++){
			res+=b[i]*i*(n+1-i);
		}
		printf("%lld\n",sum-res);
	}
}