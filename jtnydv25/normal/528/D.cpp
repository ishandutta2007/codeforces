#include <bits/stdc++.h>
using namespace std;
 
#define ll int
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
const int MAXN = 19;
const int maxn = (1<<MAXN);
base W[maxn],invW[maxn];
void precompute_powers(){
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
    if (invert) for (int i=0; i<n; ++i) a[i] /= n;
}

void multiply (vll & a, vll b) {
    vector<base> fa(a.begin(), a.end());
    int fsz = a.size()+b.size()-1;
    int n = 1;
    while (n < fsz)  n <<= 1;
    fa.resize (n); a.resize(n); b.resize(n);
    for(int i = 0; i < n; i++) fa[i] = base(a[i]) + (base(0, 1) * base(b[i]));
    fft (fa, false);
     for(int i = 0 ; i <= (n >> 1) ; ++i){
        base p = fa[i] + fa[(n - i) % n].conj();
        base q = fa[i] - fa[(n - i) % n].conj();
        fa[i] = (p * q * base(0, -0.25)) ;
        if(i > 0) fa[(n - i)] = fa[i].conj();
    }
    fft (fa, true);
    a.resize (fsz);
    for(int i = 0;i<fsz;i++)
        a[i] = ( (ll) (fa[i].real() + 0.5));
}
const int N = 200005;
char S[N], T[N];
int cnt[N], pref[4][N], b[N];
vector<int> v1, v2;
int val(char c){ if(c == 'A') return 1; if(c == 'T') return 0; if(c == 'C') return 2; if(c == 'G') return 3;}
int main(){
    precompute_powers();
    int n, m, k;
    sd(n); sd(m); sd(k);
    v1.resize(n + 1); v2.resize(n + 1);
    scanf("%s ", S);
    scanf("%s", T);
    rep(i, 1, n + 1){
        rep(j, 0, 4) pref[j][i] = pref[j][i - 1];
        pref[val(S[i - 1])][i] ++; 
    }
    rep(j, 0, 4){
        v1.clear();
        v1.resize(n + 1);
        for(int i = 0; i < m; i++) v1[i] = (val(T[i]) == j);
        for(int i = 1; i <= n; i++){
            int lo = i - k, hi = i + k;
            v2[n + 1 - i] = (pref[j][min(hi, n)] > pref[j][max(0, lo - 1)]);
        }
        multiply(v1, v2);
        for(int i = 1; i <= n; i++) cnt[i] += v1[i];
    }
    int ans = 0;
    for(int i = 1; i <= n; i++) if(cnt[i] == m)ans++;
    pd(ans);
}