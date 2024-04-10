#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,t;
ll n,m,sb,res;

int main() {
	scanf("%d",&t);
	while(t--){
		scanf("%lld%lld%lld",&n,&m,&sb);
		res=((n+1)/(sb*2))*sb+min(sb,(n+1)%(sb*2))-2;
		puts((res<(m-1)||sb==n)?"YES":"NO");
	}
}