#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
using namespace std;

#define int long long

int binpow(int a, int b, int m)
{
    int res=1;
    while (b)
    {
        if (b&1) res*=a, res%=m;
        a*=a, a%=m;
        b>>=1;
    }
    return res;
}

const int nmax=2e5+100;
    int n;
int a[nmax];
vector<int> primes;
int erat[1000100];

int check(int p)
{
    int cur=0;
    for (int i=1; i<=n; i++)
            if (a[i]<p) cur+=p-a[i];
            else cur+=min( a[i]%p, p-a[i]%p );
    return cur;
}

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    srand(time(0));

    cin>>n;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    int ans=1e9;

    for (int i=2; i<1e6+100; i++)
        if (erat[i]==0)
    {
        primes.pb(i);
        for (int j=2*i; j<1e6+100; j+=i)
            erat[j]=1;
    }
    for (int i=0; i<200; i++)
    {
        int p=primes[i];

        ans=min(ans, check(p));
    }

    map<int, int> goodx;
    while (clock()*1.0 / CLOCKS_PER_SEC < 1.5)
    {
        int l=(rand()<<15)+rand();
        l=l%n+1;
        int r=(rand()<<15)+rand();
        r=r%(n-1)+1;
        if (r>=l) r++;
        for (int k1=max<int>(1, a[l]-1); k1<=a[l]+1; k1++)
        for (int k2=max<int>(1, a[r]-1); k2<=a[r]+1; k2++)
        {
            int r=__gcd(k1, k2);
            if (r<primes[200]) continue;
            for (int i=0; (primes[i]*primes[i] <= r); i++)
                while (r%primes[i]==0)
                {
                    if (i>=200)
                        goodx[primes[i]]++;
                    r/=primes[i];
                }
            if (r>1)
                goodx[r]++;
        }
    }

/*
3
1000000007 3000000021 7000000048
*/
    set<pair<int, int> > goodset;
    for (auto pa:goodx)
        goodset.insert({-pa.se, pa.fi}); //, cout<<pa.fi<<"\n" ;
    for (auto pa:goodset)
    {
        ans=min(ans, check(pa.se));
        if (clock()*1.0 / CLOCKS_PER_SEC > 2.0)
            break;
    }
    cout<<ans<<"\n";
    return 0;
}