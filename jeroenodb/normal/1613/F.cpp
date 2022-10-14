#include "bits/stdc++.h"
using namespace std;
#define all(x) begin(x),end(x)
#define debug(a) cerr << "(" << #a << ": " << a << ")\n";
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pi;
const int mxN = 1<<19, oo = 1e9;
const long long MOD =  998244353;
class mint {
public:
    int d;
    mint () {d=0;}
    mint (long long _d) : d(_d%MOD){};
    mint operator*(const mint& o) const {
        return ((ll)d*o.d)%MOD;
    }
    mint operator+(const mint& o) const {
        long long tmp = d+o.d;
        if(tmp>=MOD) tmp-=MOD;
        return tmp;
    }
    mint operator-(const mint& o) const {
        long long tmp = d-o.d;
        if(tmp<0) tmp+=MOD;
        return tmp;
    }
    mint operator^(long long b) const {
        mint tmp = 1;
        mint power = *this;
        while(b) {
            if(b&1) {
                tmp = tmp*power;
            }
            power = power*power;
            b/=2;
        }
        return tmp;
    }
    mint operator/(const mint& o) {
        return *this * (o^(MOD-2));
    }
    bool operator==(const mint& o) {
        return d==o.d;
    }
    friend mint& operator+=(mint& a, const mint& o) {
        a.d+=o.d;
        if(a.d>=MOD) a.d-=MOD;
        return a;
    }
};
typedef mint cd;
void revperm(cd* in, int n) {
    for(int i=0,j=0;i<n;++i) {
        if(i<j) swap(in[i],in[j]);
		for(int k = n >> 1; (j ^= k) < k; k >>= 1);
    }
}
cd w[mxN+1]; // stores w^j for each j in [0,n-1]
void precomp() {
    w[0] = 1;
    int pw = (MOD-1)/mxN;
    w[1] = mint(3)^pw;
    for(int i= 2;i<=mxN;++i) {
        w[i] = w[i-1]*w[1];
    }
}
void fft(cd* in, int n, bool reverse=false) {
    int lg = __lg(n);
    assert(1<<lg == n);
    int stride = mxN/n;
    revperm(in,n);
    for(int s=1;s<=lg;++s) {
        int pw = 1<<s;
        int mstride = stride*(n>>s);
        for(int j=0;j<n;j+=pw) {
            // do FFT merging on out array
            cd* even = in+j, *odd = in+j+pw/2;
            for(int i=0;i<pw/2;++i) {
                cd& power = w[reverse?mxN-mstride*i:mstride*i];
                auto tmp = power*odd[i];
                odd[i] = even[i] - tmp;
                even[i] = even[i] + tmp;
            }
        }
    }
    if(reverse) {
        mint fac = mint(1)/n;
        for(int i=0;i<n;++i) in[i]=in[i]*fac;
    }
}


vector<cd> polymul(vector<cd>& a, vector<cd>& b) {
    int n = a.size(), m = b.size(), ptwo = 1;
    while(ptwo<(n+m)) ptwo*=2;
    a.resize(ptwo), b.resize(ptwo);
    fft(a.data(),ptwo); 
    fft(b.data(),ptwo);
    for(int i=0;i<ptwo;++i) 
        a[i] = a[i]*b[i];
    fft(a.data(),ptwo,true);
    a.resize(n+m-1);
    return a;
}
struct comp {
    bool operator()(const vector<cd>& a, const vector<cd>& b) const {
        return a.size()>b.size();
    }
};
vector<cd> allmul(vi coefs) {
    priority_queue<vector<cd>, vector<vector<cd>>, comp> pq;
    for(int i : coefs) {
        pq.push({1,i});
    }
    while(pq.size()>1) {
        vector<cd> a = pq.top(); pq.pop();
        vector<cd> b = pq.top(); pq.pop();
        pq.push(polymul(a,b));
    }
    return pq.top();
}
const int mxF = 2e6+2;
mint fact[mxF], ifact[mxF];
mint ncr(int a, int b) {
    if(b>a or a<0) return 0;
    return fact[a]*ifact[b]*ifact[a-b];
}
void precomp2() {
    fact[0]=1;
    for(int i=1;i<mxF;++i) {
        fact[i]=fact[i-1]*i;
    }
    ifact[mxF-1] = mint(1)/fact[mxF-1];
    for(int i=mxF-2;i>=0;--i) {
        ifact[i]=ifact[i+1]*(i+1);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    precomp();
    precomp2();
    int n; cin >> n;
    vi deg(n);
    for(int i=0;i<n-1;++i) {
        int u,v; cin >> u>> v,--u,--v;
        deg[u]++,deg[v]++;
    }
    vi coefs;
    for(int i=0;i<n;++i) {
        deg[i]-=(i!=0);
        if(deg[i]) {
            coefs.push_back(deg[i]);
        }
    }
    auto res = allmul(coefs);
    mint ans = 0;
    for(int i=0;i<(int)res.size();++i) {
        if(i%2==0) ans+=res[i]*fact[n-i];
        else ans=ans-res[i]*fact[n-i];
    }
    cout << ans.d << '\n';

}