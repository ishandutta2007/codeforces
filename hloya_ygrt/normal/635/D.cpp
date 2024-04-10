#include <bits/stdc++.h>

#define f first
#define s second
#define ll long long
#define pb push_back
#define pf push_front
#define files1 freopen("input.txt","r",stdin)
#define files2 freopen("output1.txt","w",stdout)
#define mp make_pair
#define fast_io ios_base::sync_with_stdio(0);
#define forn() for(int i=0;i<n;i++)

using namespace std;

const int inf=2e9;
const double eps=1e-9;
const int maxn = 2e5+5, base = 1e9+7,maxm= 1e4+5;

ll f1[maxn],f2[maxn];

ll sum(ll * t,int r)
{
    ll ans = 0;
    r++;
    while ( r > 0)
    {
        ans += t[r];
        r -= r & (-r);
    }

    return ans;
}

void add(ll *t,int i,ll x)
{
    i++;
    while (i < maxn)
    {
        t[i] += x;
        i += i & (-i);
    }
}
int main()
{
    //files1;
    //files2;
    int n, k ,a , b, q;
    scanf("%d %d %d %d %d",&n,&k,&a,&b,&q);

    for (int i=0;i<q;i++){
        int t;
        scanf("%d",&t);
        if ( t == 1 ) {
            int d,val;
            scanf("%d %d",&d,&val);
            d--;
            ll oldb = sum(f2,d) - sum(f2,d-1);
            ll nb = (val + oldb);
            if (nb > b)
                nb = b;
            add(f2, d, nb - oldb);

            d = n - d - 1;
            ll olda = sum(f1,d) - sum(f1,d-1);
            ll na = (val + olda);
            if (na > a)
                na = a;
            add(f1,d,na - olda);

           // cerr<<sum(f1,maxn-1)<<' '<<sum(f2,maxn-1);

        } else
        {
            int l;
            scanf("%d",&l);
            l--;
            int r = l + k - 1;
            int l2 = n - r - 1;
            ll ans1 = sum(f2,l-1);
            ll ans2 = sum(f1,l2-1);
            printf("%I64d\n",ans1+ans2);
        }
    }
    return 0;
}