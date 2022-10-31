#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,t;
ll n,m,k;
int main() {
	scanf("%d",&t);
	while(t--){
		scanf("%lld%lld",&n,&m);
		if(m==n){puts("0 0");continue;}
		if(n<m){swap(n,m);}
		k=llabs(n-m);
		m%=k;
		printf("%lld %lld\n",k,min(llabs(m-k),m));
	}
}