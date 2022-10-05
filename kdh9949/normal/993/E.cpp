#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()
typedef complex<double> base;
 
void fft(vector <base> &a, bool invert)
{
    int n = sz(a);
    for (int i=1,j=0;i<n;i++){
        int bit = n >> 1;
        for (;j>=bit;bit>>=1) j -= bit;
        j += bit;
        if (i < j) swap(a[i],a[j]);
    }
    for (int len=2;len<=n;len<<=1){
        double ang = 2*M_PI/len*(invert?-1:1);
        base wlen(cos(ang),sin(ang));
        for (int i=0;i<n;i+=len){
            base w(1);
            for (int j=0;j<len/2;j++){
                base u = a[i+j], v = a[i+j+len/2]*w;
                a[i+j] = u+v;
                a[i+j+len/2] = u-v;
                w *= wlen;
            }
        }
    }
    if (invert){
        for (int i=0;i<n;i++) a[i] /= n;
    }
}
 
void multiply(const vector<ll> &a,const vector<ll> &b,vector<ll> &res)
{
    vector <base> fa(all(a)), fb(all(b));
    int n = 1;
    while (n < 2 * max(sz(a),sz(b))) n <<= 1;
    fa.resize(n); fb.resize(n);
    fft(fa,false); fft(fb,false);
    for (int i=0;i<n;i++) fa[i] *= fb[i];
    fft(fa,true);
    res.resize(n);
    for (int i=0;i<n;i++) res[i] = ll(fa[i].real()+(fa[i].real()>0?0.5:-0.5));
}

int n, x;
vector<ll> a, b, c, r;

int main(){
    scanf("%d%d", &n, &x);
    for(int i = 0, t, p = 1; i <= n; i++){
        if(i < n) scanf("%d", &t);
        else t = x - 1;
        if(t < x){ a.push_back(p); p = 1; }
        else p++;
    }
    b = a;
    reverse(all(b));
    multiply(a, b, c);
    ll nn = 1LL * n * (n + 1) / 2;
    for(int i = sz(a) - 2; i >= 0; i--){
        r.push_back(c[i]);
        nn -= c[i];
    }
    printf("%lld ", nn);
    for(ll i : r) printf("%lld ", i);
    for(int i = 0; i < n - sz(a) + 1; i++) printf("0 ");
}