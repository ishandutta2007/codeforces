#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld double
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vii vector<pii >
#define vll vector<ll >
#define cps CLOCKS_PER_SEC
#define eb emplace_back
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1)
#define all(a) (a).begin(), (a).end()
#define sz(a) int((a).size())
#define print(s) cout<<#s<<" : ";for(auto i:(s))cout<<i<<" ";cout<<"\n";
#define slld(t) scanf("%lld",&(t))
#define sd(t) scanf("%d",&(t))
#define pd(t) printf("%d\n",(t))
#define plld(t) printf("%lld\n",(t))
#define endl "\n"

struct base
{
    ld x,y;
    base(){x=y=0;}
    base(ld _x, ld _y){x = _x,y = _y;}
    base(ld _x){x = _x, y = 0;}
    void operator = (ld _x){x = _x,y = 0;}
    ld real(){return x;}
    ld imag(){return y;}
    base operator + (const base& b){return base(x+b.x,y+b.y);}
    void operator += (const base& b){x+=b.x,y+=b.y;}
    base operator * (const base& b){return base(x*b.x - y*b.y,x*b.y+y*b.x);}
    void operator *= (const base& b){ld p = x*b.x - y*b.y, q = x*b.y+y*b.x; x = p, y = q;}
    void operator /= (ld k){x/=k,y/=k;}
    base operator - (const base& b){return base(x - b.x,y - b.y);}
    void operator -= (const base& b){x -= b.x, y -= b.y;}
};
//typedef complex<double> base;
double PI = 2.0*acos(0.0);
const int MAXN = 19;
const int maxn = (1<<MAXN);
base W[maxn],invW[maxn];
void precompute_powers()
{
    for(int i = 0;i<maxn/2;i++){
        double ang = (2*PI*i)/maxn; 
        ld _cos = cos(ang), _sin = sin(ang);
        W[i] = base(_cos,_sin);
        invW[i] = base(_cos,-_sin);
    }
}
void fft (vector<base> & a, bool invert) {
    int n = (int) a.size();
 
    for (int i=1, j=0; i<n; ++i) {
        int bit = n >> 1;
        for (; j>=bit; bit>>=1)
            j -= bit;
        j += bit;
        if (i < j)
            swap (a[i], a[j]);
    }
    for (int len=2; len<=n; len<<=1) {
        for (int i=0; i<n; i+=len) {
            int ind = 0,add = maxn/len;
            for (int j=0; j<len/2; ++j) {
                base u = a[i+j],  v = (a[i+j+len/2] * (invert?invW[ind]:W[ind]));
                a[i+j] = (u + v);
                a[i+j+len/2] = (u - v);
                ind += add;
            }
        }
    }
    if (invert)
        for (int i=0; i<n; ++i)
            a[i] /= n;
}
     
     
void multiply ( vector<ll> & a, vector<ll> & B) {
    vll b = B;
    vector<base> fa (a.begin(), a.end()),  fb (b.begin(), b.end());
    int fsz = a.size()+b.size()-1;
    int n = 1;
    while (n < max (a.size(), b.size()))  n <<= 1;
    n <<= 1;
    fa.resize (n),  fb.resize (n);
 
    fft (fa, false),  fft (fb, false);
    for (size_t i=0; i<n; ++i)
        fa[i] *= fb[i];
    fft (fa, true);
 
    a.resize (fsz);
    for(int i = 0;i<fsz;i++)
        a[i] = ( (ll) (fa[i].real() + 0.5));
}
inline ll mul(ll a, ll b, ll mod)
{
    return (a*b)%mod;
}
void mul_big_mod(vll& a, vll& b, ll mod)
{
    int n1 = a.size(),n2 = b.size();
    vll a1(n1),a2(n1),b1(n2),b2(n2),a3(n1),b3(n2);
    int base = (int)sqrt(mod)+10;
    for(int i = 0;i<n1;i++)
        a1[i] = a[i]/base,a2[i] = a[i]%base,a3[i] = (a1[i]+a2[i]);
    for(int i = 0;i<n2;i++)
         b1[i] = b[i]/base, b2[i] = b[i]%base, b3[i] = (b1[i]+b2[i]);
    multiply(a1,b1);
    multiply(a2,b2);
    multiply(a3,b3);
    int _sz = n1+n2-1;
    a.resize(_sz);
    for(int i = 0;i<_sz;i++){
        a[i] = (mul(base*base,a1[i]%mod,mod)+mul(base,(a3[i]-a1[i] - a2[i])%mod,mod)+a2[i])%mod;
        if(a[i]<mod)
            a[i]+=mod;
    }
}

void polypower_big_mod(vll& a, int n,ll mod)
{
    vll x;
    x.pb(1);
    vll b;
    while(n)
    {
        if(n&1)
            mul_big_mod(x,a,mod);
            // polymulmod(x,a,takemod,mod,give_a_fuck_about_precision);
        b = a;
        mul_big_mod(a,b,mod);
        // polymulmod(a,b,takemod,mod,give_a_fuck_about_precision);
        n>>=1;
    }
    a = x;
}
const int N = 10005;
const ll mod = 1e9+7;
int main()
{
    precompute_powers();
    int a,b,k,t;
    sd(a),sd(b),sd(k),sd(t);
    vll diff(4*k+1,0);
    rep(i,0,2*k+1)
    rep(j,0,2*k+1)
    diff[i-j+2*k]++;
    polypower_big_mod(diff,t,mod);
    ll ans = 0;
    for(int i=b-a+2*k*t+1;i<=4*k*t;i++)
        if(i>=0)
            ans=(ans+diff[i])%mod;
    cout<<ans<<endl;    
}