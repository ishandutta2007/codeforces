#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,t,n,m;
ll k,sb,res;
int main() {
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		sb=0;
		for(i=1;i<=n;i++){
			scanf("%lld",&k);
			sb+=k;
		}
		sb%=n;
		printf("%lld\n",sb*(n-sb));
	}
}