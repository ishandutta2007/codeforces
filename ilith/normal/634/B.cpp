#include<bits/stdc++.h>
#define rgi register int
#define pbk push_back
#define FOR(i,a,b) for(rgi i=a,i##i=b;i<=i##i;++i)
#define ROF(i,a,b) for(rgi i=a,i##i=b;i>=i##i;--i)
using namespace std;
typedef long long ll;
const int N=400010;
ll s,x,ad,ans=1;
signed main(){
	scanf("%lld%lld",&s,&x);
	ad=s-x;
	if(ad&1)puts("0"),exit(0);
	ad>>=1;
	if(ad&x)puts("0"),exit(0);
	while(x){
		if(x&1)ans*=2;
		x>>=1;
	}
	printf("%lld",ad?ans:ans-2);
	return 0;
}