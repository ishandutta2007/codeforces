#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll q;

int main()
{
	scanf("%lld",&q);
	while(q--) {
		ll A, B;
		scanf("%lld%lld",&A,&B);
		if(A%2 == 1) {
			if(B%2 == 0) printf("%lld\n",(B-A+1)/2);
			else printf("%lld\n",(B-A)/2-B);
		}
		else {
			if(B%2 == 1) printf("%lld\n",-(B-A+1)/2);
			else printf("%lld\n",-(B-A+1)/2+B);
		}
	}
}