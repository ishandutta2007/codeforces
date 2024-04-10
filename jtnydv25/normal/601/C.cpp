#include <bits/stdc++.h>
using namespace std;
 
#define ll double
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
#define eb push_back
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1)
#define all(a) (a).begin(), (a).end()
#define sz(a) int((a).size())
#define print(s) cout<<#s<<" : ";for(auto i:(s))cout<<i<<" ";cout<<"\n";
#define slld(t) scanf("%lld",&(t))
#define sd(t) scanf("%d",&(t))
#define pd(t) printf("%d\n",(t))
#define plld(t) printf("%lld\n",(t))
#define endl "\n"

// To make it faster and more precise, precompute all the nth roots.
struct base{
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
    base conj(){ return base(x, -y);}
};
//typedef complex<double> base;
double PI = 2.0*acos(0.0);
base w[1 << 20];

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
        double ang = 2*PI/len * (invert ? -1 : 1);
        base wlen (cos(ang), sin(ang));
        for (int i=0; i<n; i+=len) {
            w[0] = 1;
            for (int j=0; j<len/2; ++j) {
                if(j&1)
                    w[j] = w[j-1]*wlen;
                if(j && !(j&1))
                    w[j] = w[j>>1]*w[j>>1];
                base u = a[i+j],  v = (a[i+j+len/2] * w[j]);
                a[i+j] = (u + v);
                a[i+j+len/2] = (u - v);
                // w *= wlen;
            }
        }
    }
    if (invert)
        for (int i=0; i<n; ++i)
            a[i] /= n;
}     
void multiply (vll & a, vll b) {
    vector<base> fa (a.begin(), a.end()),  fb (b.begin(), b.end());
    int fsz = a.size()+b.size()-1;
    int n = 1;
    while (n < fsz)  n <<= 1;
    fa.resize (n),  fb.resize (n);
 
    fft (fa, false),  fft (fb, false);
    for (size_t i=0; i<n; ++i) fa[i] *= fb[i];
    fft (fa, true);
 
    a.resize (fsz);
    for(int i = 0;i<fsz;i++)
        a[i] = fa[i].real();
}

vll mul(vll &a, vll &b){
    vll c = a;
    multiply(c, b);
    return c;
}

// vec[0](x) * vec[1](x) * vec[2](x) ..
vll polymul(vector<vll> & vec){
    if(vec.size() == 1) return vec[0];
    int half = ((int)vec.size()) >> 1;
    vector<vll> lft(vec.begin(), vec.begin() + half);
    vector<vll> rgt(vec.begin() + half, vec.end());
    vll vl = polymul(lft), vr = polymul(rgt);
    return mul(vl, vr);
}
vector<vll > vec;
int main(){
    int n, m, x;
    sd(n), sd(m);
    if(m == 1){
        printf("1.0000000000\n");
        return 0;
    }
    int s = 0;
    for(int i = 0; i < n; i++){
        sd(x); x--; s += x;
        vector<ll> v;
        for(int j = 0; j < m; j++){
            v.push_back(j == x ? 0 : (1. / (m - 1)));
        }
        vec.push_back(v);
    }
    vector<ll > v = polymul(vec);
    double ans = 0;
    for(int i = 0; i < s; i++) ans += v[i];
    printf("%.10lf\n", 1 + ans * (m - 1));
}