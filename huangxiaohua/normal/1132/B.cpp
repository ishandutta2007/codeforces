#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t;
ll a[500500],sb;
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%lld",&a[i]);sb+=a[i];
	}
	sort(a+1,a+n+1);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&i);
		printf("%lld\n",sb-a[n+1-i]);
	}
}