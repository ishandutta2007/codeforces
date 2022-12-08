#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll s,a,b,c;
int main()
{
	int T;
	scanf("%d",&T);
	while(T--){
		cin>>s>>a>>b>>c;
		ll k=s/c;
		ll p=k/a;
		ll q=p*b;
		printf("%lld\n",q+k);
	}
}