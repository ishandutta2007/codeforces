#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
ll n;

int main()
{
    ll i, tmp, cur;
    scanf("%lld",&n);
    for(i=1;i<=n;i++) {
        cur = 0; tmp = i;
        while(tmp>0) {
            cur += tmp;
            tmp /= 5;
        }
        if(cur>=n) {
            if(cur==n) {
                printf("5\n%lld %lld %lld %lld %lld",5*i,5*i+1,5*i+2,5*i+3,5*i+4);
            }
            else printf("0");
            return 0;
        }
    }
}