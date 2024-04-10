#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
ll n,d,h;

int main()
{
    ll i,j;
    scanf("%lld%lld%lld",&n,&d,&h);
    if(d>2*h || d+1>n || d<h || (n!=2 && d==1)) {puts("-1"); return 0;}
    for(i=2;i<=1+h;i++) {
        printf("%lld %lld\n",i-1,i);
    }
    if(i<=n && d!=h) {
        printf("1 %lld\n",i);
        i++;
    }
    for(;i<=1+d;i++) {
        printf("%lld %lld\n",i-1,i);
    }
    for(;i<=n;i++) {
        printf("%lld %lld\n",h,i);
    }
}