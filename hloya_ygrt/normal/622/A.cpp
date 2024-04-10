#include <bits/stdc++.h>

#define f first
#define s second
#define ll long long
#define ld long double
#define pb push_back
#define files1 freopen("input.txt","r",stdin)
#define files2 freopen("output.txt","w",stdout)
#define mp make_pair
#define fast_io ios_base::sync_with_stdio(0);
#define forn() for(int i=0;i<n;i++)


using namespace std;

const int inf=2e9;
const double eps=1e-9;
const int maxn = 1e5+500, base = 1e9+7;

int main()
{
    ll n;
    cin >> n;

    ll l = 0, r = inf;

    while ( r-l>1 ){
        ll m = (l+r)>>1;
        if (n - ((1LL+m)*m)/2LL >= 0)
            l = m;
        else
            r = m;
    }
    ll sum = ((1LL+l)*l)/2LL;
    sum = n-sum;
    if (sum == 0)
        sum+=l;
    cout<<sum;
    return 0;
}