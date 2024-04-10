#include <stdio.h>
#include <algorithm>
#define mp make_pair
#define ll long long
using namespace std;
const ll maxn=1e5;
pair<ll,ll> y[maxn];
int main()
{
    ll n,x1,x2;
    scanf("%I64d",&n);
    scanf("%I64d %I64d",&x1,&x2);
    for (ll i=0;i<n;i++)
    {
        ll k,b;
        scanf("%I64d %I64d",&k,&b);
        y[i]=mp(k*x1+b,k*x2+b);
    }

    sort(y,y+n);

    for (ll i=1;i<n;i++)
    {
        if(y[i].first>y[i-1].first&&y[i].second<y[i-1].second)
        {
            printf("YES");
            return 0;
        }

        if(y[i].first<y[i-1].first&&y[i].second>y[i-1].second)
        {
            printf("YES");
            return 0;
        }
    }
    printf("NO");
    return 0;
}