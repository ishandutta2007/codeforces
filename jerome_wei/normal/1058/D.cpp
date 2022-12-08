#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll m,n,k,s;

ll gcd(ll a,ll b){
	return b==0ll ? a : gcd(b,a%b);

}

int main()
{
	scanf("%lld%lld%lld",&n,&m,&k);
   	s=m*n*2;
	if(s%k){printf("NO");return 0;}
	s=s/k;
	ll p=gcd(n,s);
	if(p>n)p/=2;
	ll q=s/p;
	if(q>m)q/=2,p*=2;
	printf("YES\n");
	printf("0 0\n");
	printf("%I64d 0\n",p);
	printf("0 %I64d",q);
}