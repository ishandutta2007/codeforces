/*********************************************************************
 * Source
 * ProblemCF585C
 * Authorhydd
 * Date2020/9/8
 * EncodingSimplified Chinese (GB2312)
*********************************************************************/
#include<cstdio>
#include<algorithm>
//#define File(x) freopen(x".in","r",stdin);freopen(x".out","w",stdout)
using namespace std;
typedef long long ll;
ll x,y;
int main(){
	scanf("%lld%lld",&x,&y);
	if (__gcd(x,y)!=1){
		puts("Impossible");
		return 0;
	}
	while (x>1&&y>1){
		if (x>y) printf("%lldA",x/y),x%=y;
		else printf("%lldB",y/x),y%=x;
	}
	if (x==1) printf("%lldB",y-1);
	else printf("%lldA",x-1);
	return 0;
}