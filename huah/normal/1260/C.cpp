#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
ll r,b,k;
int main()
{
    int t;scanf("%d",&t);
    while(t--)
    {
        scanf("%lld%lld%lld",&r,&b,&k);
        ll s=__gcd(r,b);
        bool flag=true;
        if(r>b) swap(r,b);
        if(s+(k-1)*r<b) flag=false;
        printf(flag?"OBEY\n":"REBEL\n");
    }
}
//1 2 3 4 5 6 7 8 9 10