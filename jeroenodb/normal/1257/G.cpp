#include "bits/stdc++.h"
using namespace std;
#define all(x) begin(x),end(x)
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { string sep; for (const T &x : v) os << sep << x, sep = " "; return os; }
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
int total;

vector<cd> polymul(vector<cd>& a, vector<cd>& b) {
    int n = a.size(), m = b.size(), ptwo = 1;
    while(ptwo<(n+m)) ptwo*=2;
    a.resize(ptwo), b.resize(ptwo);
    fft(a.data(),ptwo); 
    fft(b.data(),ptwo);
    for(int i=0;i<ptwo;++i) 
        a[i] = a[i]*b[i];
    fft(a.data(),ptwo,true);
    a.resize(min(total+1,n+m-1));
    return a;
}
vi cnts;
vector<cd> mul(int i, int j) {
    if(i==j) {
        return vector<cd>(cnts[i]+1,1);
    }
    int mid = (i+j)/2;
    auto a = mul(i,mid), b= mul(mid+1,j);
    return polymul(a,b);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    precomp();
    int n; cin >> n;
    total=n/2;
    {
    map<int,int> mp;
    for(int i=0;i<n;++i) {
        int p; cin >> p;
        mp[p]++;
    }
    for(auto [a,b] : mp) cnts.push_back(b);
    }
    random_shuffle(all(cnts));
    cout << mul(0,cnts.size()-1)[n/2].d << '\n';
}