#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 998244353

ll a,b,c,d;
ll ksm(ll a,ll p){
	if(!p)return 0;
	ll res=1;while(p){if(p&1){res=res*a%M;}p>>=1;a=a*a%M;}return res;}

int main(){
    scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
    if(a*b%2){printf("%lld",ksm(d-c+1,a*b%(M-1)));}
	else{printf("%lld",(ksm(d-c+1,a*b%(M-1))+(d-c+1)%2)*499122177%M);}
}