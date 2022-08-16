#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vll vector<ll>
#define ld double
#define pb push_back
#define print(s) cout<<#s<<" : ";for(auto i:(s))cerr<<i<<" ";cerr<<"\n";
// class bigint
// works with C++ 14
char S[1500005];
struct cplx{
    ld x,y;
    cplx(){x=y=0;}
    cplx(ld _x, ld _y){x = _x,y = _y;}
    cplx(ld _x){x = _x, y = 0;}
    void operator = (ld _x){x = _x,y = 0;}
    ld real(){return x;}
    ld imag(){return y;}
    cplx operator + (const cplx& b){return cplx(x+b.x,y+b.y);}
    void operator += (const cplx& b){x+=b.x,y+=b.y;}
    cplx operator * (const cplx& b){return cplx(x*b.x - y*b.y,x*b.y+y*b.x);}
    void operator *= (const cplx& b){ld p = x*b.x - y*b.y, q = x*b.y+y*b.x; x = p, y = q;}
    void operator /= (ld k){x/=k,y/=k;}
    cplx operator - (const cplx& b){return cplx(x - b.x,y - b.y);}
    cplx conj(){ return cplx(x, -y);}
    void operator -= (const cplx& b){x -= b.x, y -= b.y;}
};
double PI = 2.0*acos(0.0);
const int base = 10000, baselen = 4, mod = base;
const int MAXN = 21;
const int maxn = (1<<MAXN);
cplx W[maxn],invW[maxn];
void precompute_powers()
{
    for(int i = 0;i<=maxn/2;i++){
        double ang = (2*PI*i)/maxn; 
        ld _cos = cos(ang), _sin = sin(ang);
        W[i] = cplx(_cos,_sin);
        invW[i] = cplx(_cos,-_sin);
    }
}
void fft (vector<cplx> & a, bool invert) {
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
                cplx u = a[i+j],  v = (a[i+j+len/2] * (invert?invW[ind]:W[ind]));
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
class bigint{
    // Polynomials 
    vll naive_mul(vll &a, vll &b){
        vll c(a.size()+b.size()-1);
        for(int i = 0;i<a.size();i++) for(int j = 0;j<b.size();j++) c[i+j] += a[i]*b[j];
        return c;
    }
    // a < b -> -1, a > b -> 1, a==b -> 0
    int comparevec(const vll &a,const vll &b){
        int sza = a.size(), szb = b.size();
        if(sza < szb) return -1;
        if(sza > szb) return 1;
        for(int i = sza-1;i>=0;i--){
            if(a[i]<b[i]) return -1;
            if(a[i]>b[i]) return 1;
        }
        return 0;
    }
/*    vll multiply ( vector<ll>& a, vector<ll> b) {
        if(a.size()*1ll*b.size() <= 1000) return naive_mul(a,b);
        vector<cplx> fa (a.begin(), a.end()),  fb (b.begin(), b.end());
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
        return a;
    }*/
    vll multiply (vll & a, vll b) {
        if(int(min(a.size(), b.size())) <= 3 || a.size()*1ll*b.size() <= 10000) return naive_mul(a,b);
        vector<cplx> fa(a.begin(), a.end());
        int fsz = a.size()+b.size()-1;
        int n = 1;
        while (n < fsz)  n <<= 1;
        fa.resize (n); a.resize(n); b.resize(n);
        for(int i = 0; i < n; i++) fa[i] = cplx(a[i]) + (cplx(0, 1) * cplx(b[i]));
        fft (fa, false);
         for(int i = 0 ; i <= (n >> 1) ; ++i){
            cplx p = fa[i] + fa[(n - i) % n].conj();
            cplx q = fa[i] - fa[(n - i) % n].conj();
            fa[i] = (p * q * cplx(0, -0.25)) ;
            if(i > 0) fa[(n - i)] = fa[i].conj();
        }
        fft (fa, true);
        a.resize (fsz);
        for(int i = 0;i<fsz;i++)
            a[i] = ( (ll) (fa[i].real() + 0.5));
        return a;
    }
    vll vector_add(vll a, vll b, int base){
        int sza = a.size(), szb = b.size();
        if(sza<szb){sza = szb, a.resize(szb);}
        else szb = sza, b.resize(sza);
        int carry = 0;
        for(int i = 0;i<szb;i++){
            int ncarry = (a[i]+b[i]+carry)/base;
            a[i] = (a[i]+b[i]+carry)%base;
            carry = ncarry;
        }
        while(carry)a.pb(carry%base),carry/=base;
        return a;
    }
    vll vector_sub(vll a, vll b, int base){
        int sza = a.size(), szb = b.size();
        if(sza<szb)sza = szb, a.resize(szb);
        else b.resize(sza), szb = sza;
        int carry = 0;
        for(int i = 0;i<sza;i++){
            int ncarry = (a[i]-carry-b[i] < 0);
            a[i] = a[i] - b[i] - carry + base*ncarry;
            carry = ncarry;
        }
        assert(carry == 0); 
        return a;
    }
public:
    vll vec;
    int sign;
    bigint(){sign=1;}
    bigint(ll x){
        sign = 1;
        if(x < 0) sign = -1, x*=-1;
        for(;x;x/=base) vec.pb(x%base);
    }
    bigint(string s){input(s);}
    bigint operator = (const bigint &b){sign = b.sign; vec = b.vec;}
    void input(string s){
        vec.clear();
        sign = 1;
        if(s[0] == '-') sign = -1, s = s.substr(1,s.length()-1);
        int l = s.length();
        if(!l){sign = 1; return;}
        reverse(s.begin(),s.end());
        for(int i = 0;i<l;i+=baselen){
            string _s = s.substr(i,min(i+baselen,l)-i);
            reverse(_s.begin(),_s.end());
            vec.pb(stoi(_s));
        }
    }
    //IO
    friend istream& operator>>(istream &stream, bigint &v) {
        string s;
        stream >> s;
        v.input(s);
        return stream;
    }
 
    friend ostream& operator<<(ostream &stream, const bigint &v) {
        if (v.sign == -1)
            stream << '-';
        stream << (v.vec.empty() ? 0 : v.vec.back());
        for (int i = (int) v.vec.size() - 2; i >= 0; --i)
            stream << setw(baselen) << setfill('0') << v.vec[i];
        return stream;
    }
 
    void negate(){sign=-sign;}
    bigint abs(){bigint ret; ret.vec = vec; ret.sign = 1;}
    void trim(){
        while(!vec.empty() && !vec.back())vec.pop_back();
        if(vec.empty()) sign = 1;
    }
    void fix(){
        ll carry = 0;
        for(int i = 0;i<vec.size();i++){
            ll ncarry = (vec[i]+carry)/base;
            vec[i] = (vec[i]+carry)%base;
            carry = ncarry;
        }
        while(carry)vec.pb(carry%base), carry/=base;
        trim();
    }
    // Comparisions.
    int compare_bigint(bigint &b){
        if(sign < b.sign) return -1;
        if(sign > b.sign) return 1;
        return sign*comparevec(vec,b.vec);
    }
    bool operator < (bigint &b){return compare_bigint(b) == -1;}
    bool operator <= (bigint &b){return compare_bigint(b) <= 0;}
    bool operator > (bigint &b){return compare_bigint(b) == 1;}
    bool operator >= (bigint &b){return compare_bigint(b) >= 0;}
    bool operator == (bigint &b){return compare_bigint(b) == 0;}
    bool operator != (bigint &b){return compare_bigint(b) == -1;}
    bigint operator + (const bigint &b){
        int signa = sign, signb = b.sign;
        bigint ret;
        if(signa == signb){
            ret.sign = signa;ret.vec = vector_add(vec,b.vec,base);
            ret.fix();
            return ret;
        }
        int cmp1 = comparevec(vec,b.vec);
        if(cmp1 >= 0){
            ret.sign = signa;
            ret.vec = vector_sub(vec,b.vec,base);
        }
        else{
            ret.sign = signb;
            ret.vec = vector_sub(b.vec,vec,base);
        }
        ret.fix();
        return ret;
    }
    bigint operator - (const bigint &b){
        bigint x = b; x.negate();
        return (*this) - x;
    }
    bigint operator * (bigint b){
        bigint ret;
        ret.vec = multiply(vec, b.vec);
        ret.sign = sign*b.sign;
        ret.fix();
        return ret;
    }
};
 
bigint factorial(int lo, int hi){
    if(lo == hi) return bigint(lo);
    if(lo == hi -1) return bigint(lo*1ll*hi);
    int mid = (lo+hi)/2;
    return factorial(lo,mid)*factorial(mid+1,hi);
}

bigint power(bigint a, int n){
	if(n == 1) return a;
	if(n == 0) return bigint("1");
	bigint x = power(a, n >> 1);
	bigint y = x;
	bigint z = x * y;
	if(n & 1) return z * a;
	return z;
}

int main(){
    precompute_powers();
    int t;
  	scanf("%s", S);
  	string s = string(S);
  	if(s == "1"){
  		printf("1\n");
  		return 0;
  	}
  	if(s == "2"){
  		printf("2\n");
  		return 0;
  	}
  	bigint given = bigint(s);
  	int ans = 1e9;
  	int minlen = max(0, (int)(s.length() * log(10) / log(3)) - 3);
  	bigint val = power(3, minlen);
  	for(int p2 = 0; p2 <= 4; p2++)
  		for(int p3 = 0; p2 + p3 <= 4; p3++){
  			int num = 1;
  			for(int i = 1; i <= p2; i++) num <<= 1;
  			for(int i = 1; i <= p3; i++) num *= 3;
  			bigint val2 = val;
  			bigint z = val2 * bigint(to_string(num));
  			// cerr << z << " " << 
  			if(z >= given) ans = min(ans, (p3 + minlen) * 3 + p2 * 2);
  		}  
  	printf("%d\n", ans);
}