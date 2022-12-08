#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
ll n;
int q;
int main()
{
	scanf("%lld%d",&n,&q);
	for(int p=1;p<=q;p++){
		ll i,j;
		scanf("%lld%lld",&i,&j);
		ll hlf=(n*n+1)/2;
		ll rk=j+(i-1)*n;
		//cout<<rk;
		if(n%2){
			if(rk%2){
				printf("%lld\n",(rk+1)/2);
			}else{
				printf("%lld\n",rk/2+hlf);
			}
		}
		else{
			ll ans=0;
			if(i%2!=j%2)ans+=hlf;
			printf("%lld\n",(rk+1)/2+ans);
		}
	}
}