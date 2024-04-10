#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld double
#define vi vector<int>
#define pb push_back
#define vll vector<int>
#define cps CLOCKS_PER_SEC
#define eb push_back
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1)
#define all(a) (a).begin(), (a).end()
#define sz(a) int((a).size())
#define print(s) cerr<<#s<<" : ";for(auto i:(s))cerr<<i<<" ";cerr<<"\n";
#define slld(t) scanf("%lld",&(t))
#define sd(t) scanf("%d",&(t))
#define pd(t) printf("%d\n",(t))
#define plld(t) printf("%lld\n",(t))
#define endl "\n"
const int N = 2e5 + 10;

const int mod = 1009;
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
};
double PI = 2.0*acos(0.0);
const int MAXN = 21;
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
inline int add(int x, int y){ x += y; if(x >= mod) x -= mod; return x;}
inline int sub(int x, int y){ x -= y; if(x < 0) x += mod; return x;}
inline int mul(int x, int y){ return (x * 1ll * y) % mod;}
inline int powr(int a, ll b){
    int x = 1 % mod;
    while(b){
        if(b & 1) x = mul(x, a);
        a = mul(a, a);
        b >>= 1;
    }
    return x;
}
inline int inv(int a){ return powr(a, mod - 2);}
// In case of precision issues change vll to vll
void multiply (vll & a, vll b) {
    if( (a.size() * 1ll * b.size()) <= 1000){
        vll ret(sz(a) + sz(b) - 1);
        rep(i,0,sz(a)) rep(j, 0, sz(b)) ret[i + j] = add(ret[i + j], mul(a[i], b[j]));
        a = ret;
        return;
    }
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
        a[i] = ( (ll) (fa[i].real() + 0.5)) % mod;
}
vll mul(vll a, vll b){
    multiply(a, b);
    return a;
}

vll get(vector<vll> & V){
	if(V.size() == 1) return V[0];
	int mid = (V.size() >>1);
	vector<vll> lft(V.begin(), V.begin()+mid);
	vector<vll> rgt(V.begin() + mid , V.end());
	return mul(get(lft), get(rgt));
}
int f[N];
int main(){
	precompute_powers();
	int n, m, k;
	sd(n); sd(m); sd(k);

	for(int i = 1; i <= n; i++){
		int x;
		sd(x);
		f[x]++;
	}
	vector<vll> v;
	
	for(int i = 0; i < N; i++){
		if(f[i]){
			vll z;
			for(int j = 0; j <= f[i]; j++) z.push_back(1);
			v.push_back(z);
		}
	}
	random_shuffle(v.begin(), v.end());
	printf("%d\n", get(v)[k]);
}