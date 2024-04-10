#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,a[200500],it;

int main() {
	a[0]=1;
	//scanf("%d",&t);
	t=1;
	while(t--){
		scanf("%d",&n);
		it=0;
		for(i=1;i<=n;i++){
			scanf("%d",&k);
			if(__gcd(a[it],k)!=1){
				a[++it]=1;
			}
			a[++it]=k;
		}
		printf("%d\n",it-n);
		for(i=1;i<=it;i++){
			printf("%d ",a[i]);
		}puts("");
	}
}