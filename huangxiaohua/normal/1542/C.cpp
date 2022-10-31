#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define M 1000000007
int i,j,k,m,t;
ll n,a,b,sb,tmp,res;

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%lld",&n);
		sb=1;i=2;res=n;
		while(sb<=n){
			res=(res+n/sb)%M;
			sb=i*sb/__gcd(sb,i*1ll);i++;
		}
		printf("%lld\n",res);
	}
}