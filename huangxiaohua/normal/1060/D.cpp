#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int i,j,k,n,m;
ll res,l[100500],r[100500];

int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%lld%lld",&l[i],&r[i]);
	}
	sort(l+1,l+n+1);
	sort(r+1,r+n+1);
	for(i=1;i<=n;i++){
		res+=max(l[i],r[i]);
	}
	printf("%lld",res+n);
}