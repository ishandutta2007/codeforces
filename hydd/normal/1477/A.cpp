#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int T,n; ll k,a[210000];
int main(){
	scanf("%d",&T);
	while (T--){
		scanf("%d%lld",&n,&k); ll g=0;
		for (int i=1;i<=n;i++){
			scanf("%lld",&a[i]);
			g=__gcd(g,a[i]-a[1]);
		}
		if ((k-a[1])%g) puts("NO");
		else puts("YES");
	}
	return 0;
}