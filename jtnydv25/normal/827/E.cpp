#include <bits/stdc++.h>
using namespace std;
#define ll int
#define ld double
#define pii pair<int,int>
#define vll vector<ll >
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
const int MAXN = 20;
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


void multiply ( vector<ll> & a, vector<ll> b) {
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

void getDiffvector(vector<ll> & vec){
    int n = vec.size();
    vll v2(n + 1);
    for(int i = 0; i < n; i++) v2[n - i] = vec[i];
    multiply(vec, v2);
    for(int i = 0; i < n; i++) vec[i] = vec[n + i];
    vec.resize(n);

}
vll v1, v2;
vector<int> vec;
const int N = 5e5 + 10;
bool bad[N];
char s[N];
int main(){
    precompute_powers();
    int t;
    scanf("%d", &t);
    while(t--){
        int n;
        scanf("%d", &n);
        scanf("%s", s);
        v1.clear(); v2.clear();
        v1.resize(n); v2.resize(n);
        for(int i = 0; i < n; i++){
            v1[i] = (s[i] == '?') ? 0 : 1;
            if(s[i] == 'V') v2[i] = 1;
            else if(s[i] == 'K') v2[i] = -1;
        }
        for(int i = 1; i <= n; i++) bad[i] = 0;
        getDiffvector(v1);
        getDiffvector(v2);
        for(int i = 1; i < n; i++) if(v1[i] != v2[i]) bad[i] = 1;
        for(int i = 1; i <= n; i++){
            for(int j = i; j <= n; j+= i) if(bad[j]) bad[i] = 1;
        }
        int cnt = 0;
        for(int i = 1; i <= n; i++) if(!bad[i]) cnt++;
        printf("%d\n", cnt);
        for(int i = 1; i <= n; i++) if(!bad[i]) printf("%d ", i);
        printf("\n");
    }
}