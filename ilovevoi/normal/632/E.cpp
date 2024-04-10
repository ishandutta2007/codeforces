#include <bits/stdc++.h>
using namespace std;

#define ll  long long
#define pll pair<ll,ll>
#define ff first
#define ss second
#define pb push_back
#define endl "\n"
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn=5e1+5;
const ll mod=1e9+7   ;
const ll base=1e9+1000;

/// have medal in APIO
/// goal 3/7

struct FFT
{
    const double PI = 3.141592653589793;
    typedef complex<double> base;
    void fft( vector < base > & a, bool inv )
    {
        int n = ( int ) a.size();
        for ( int i = 1, j = 0; i < n; ++i )
        {
            int bit = ( n >> 1 );
            for ( ; j >= bit; bit >>= 1 )
                j -= bit;
            j += bit;
            if ( i < j )
                swap( a[i], a[j] );
        }
        for ( int len = 2; len <= n; len <<= 1 )
        {
            double ang = 2. * PI / len * ( inv ? -1 : 1 );
            base wlen( cos( ang ), sin( ang ) );
            for ( int i = 0; i < n; i += len )
            {
                base w(1);
                ll len2 = len >> 1;
                for (int j = 0; j < len2; ++j )
                {
                    base u = a[i+j], v = a[i+j+len2] * w;
                    a[i+j] = u + v;
                    a[i+j+len2] = u - v;
                    w *= wlen;
                }
            }
        }
        if ( inv )
            for (int i = 0; i < n; ++i )
                a[i] /= n;
    }
    vector<ll> multiply( vector<ll> a, vector<ll> b )
    {
        vector < base > fa(a.begin(), a.end()), fb(b.begin(), b.end());
        ll n = 1;
        while ( n < max( (ll)a.size(), (ll)b.size() ) )
            n <<= 1;
        n <<= 1;
        fa.resize( n );
        fb.resize( n );
        fft( fa, false );
        fft( fb, false );
        for (int i = 0; i < n; ++i )
            fa[i] *= fb[i];
        fft( fa, true );
        vector<ll> ret( n,0ll );
        for (int i = 0; i < n; ++i )
        {
            ret[i] = ( ll ) ( fa[i].real() + .5 );
            if (ret[i])
                ret[i]=1;
        }

        return (ret);
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    if (fopen("t.inp", "r"))
    {
        freopen("test.inp", "r", stdin);
        freopen("test.out", "w", stdout);
    }
    ll n, k;
    cin>> n>> k;
    vector<ll> vt=vector<ll> (1003,0);
    for (int i=1; i<=n; i++)
    {
        ll x;
        cin>> x;
        vt[x]=1;
    }
    ll cnt=0;
    vector<ll> ans;
    ll dem=0;
    while (k)
    {
        FFT man;
        dem++;
        if (k%2==1)
        {
            cnt++;
            if (cnt==1)
                ans=vt;
            else
            {
                ans=man.multiply(ans,vt);
            }
        }
        k/=2;
        vt=man.multiply(vt,vt);
    }
    for (int i=0; i<ans.size(); i++)
    {
        if (ans[i])
            cout <<i<<" ";
    }
}