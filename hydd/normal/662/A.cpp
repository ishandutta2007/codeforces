#include<cstdio>
using namespace std;
typedef long long ll;
int n,tot;
ll x,y,ans;
ll num[66];
bool ins(ll x){
    for (int i=62;i>=0;i--)
        if (x&(1ll<<i)){
            if (!num[i]){ num[i]=x; tot++; return true;}
            x^=num[i];
        }
    return false;
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%lld%lld",&x,&y);
		ins(x^y); ans^=x;
	}
	if (ins(ans)) puts("1/1");
	else printf("%lld/%lld\n",(1ll<<tot)-1,(1ll<<tot));
	return 0;
}