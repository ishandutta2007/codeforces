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
const int mxN = 1e5+1, oo = 1e9;
const char MD = 5;
template<typename T,T MOD=MD,typename L=ll> struct mdint {
    T d=0;
    mdint () {d=0;}
    mdint (L _d) : d(_d%MOD){
        if(d<0) d+=MOD;
    };
    friend mdint& operator+=(mdint& a, const mdint& o) {
        a.d+=o.d; if(a.d>=MOD) a.d-=MOD;
        return a;
    }
    friend mdint& operator-=(mdint& a, const mdint& o) {
        a.d-=o.d; if(a.d<0) a.d+=MOD;
        return a;
    }
    friend mdint& operator*=(mdint& a, const mdint& o) {
        return a = ((L)a.d*o.d)%MOD;
    }
    mdint operator*(const mdint& o) const {
        mdint res = *this;
        res*=o;
        return res;
    }
    mdint operator+(const mdint& o) const {
        mdint res = *this;
        res+=o;
        return res;
    }
    mdint operator-(const mdint& o) const {
        mdint res = *this;
        res-=o;
        return res;
    }
    mdint operator^(long long b) const {
        mdint tmp = 1;
        mdint power = *this;
        while(b) {
            if(b&1) {
                tmp = tmp*power;
            }
            power = power*power;
            b/=2;
        }
        return tmp;
    }
    friend mdint operator/=(mdint& a, const mdint& o) {
        a *= (o^(MOD-2));
        return a;
    }
    mdint operator/(const mdint& o) {
        mdint res = *this;
        res/=o;
        return res;
    }
    bool operator==(const mdint& o) { return d==o.d;}
    bool operator!=(const mdint& o) { return d!=o.d;}
    friend istream& operator>>(istream& c, mdint& a) {return c >> a.d;}
    friend ostream& operator<<(ostream& c, const mdint& a) {return c << a.d;}
};
using  mint = mdint<char,MD,char>;
typedef mint F;
void gaussianElim(vector<valarray<F>>& A, int m) {
    if(A.empty()) return;
    int at= 0;
    for(int i=0;i<m and at<(int)A.size();++i) {
        for(int j=at;j<(int)A.size();++j) if(A[j][i].d>A[at][i].d) 
            swap(A[j],A[at]);
        if(A[at][i]==0) continue;
        for(int j=0;j<(int)A.size();++j) if(j!=at and A[j][i]!=0) {
            A[j]-=A[at]*(A[j][i]/A[at][i]);
        }
        ++at;
    }
}
int main() {
    int n,m; 
    cin >> n >> m;
    vector<valarray<F>> A(m, valarray<F>(n+m));
    for(int i=0;i<n;++i) {
        string s; 
        cin >> s;
        for(int j=0;j<m;++j) A[j][i]=s[j]-'a';
    }
    for(int i=0;i<m;++i) A[i][i+n]=1;
    // for(auto v : A) {
    //     for(int i=0;i<n+m;++i) {
    //         cout << int(v[i].d) << ' ';
    //     } cout << '\n';
    // } cout << '\n';
    gaussianElim(A,n);
    // for(auto v : A) {
    //     for(int i=0;i<n+m;++i) {
    //         cout << int(v[i].d) << ' ';
    //     } cout << '\n';
    // }
    vector<valarray<F>> empt;
    for(auto& v : A) {
        bool bad=true;
        for(int i=0;i<n;++i) {
            if(v[i]!=0) bad=false;
        }
        valarray<F> w(m);
        for(int i=0;i<m;++i) w[i] = v[i+n];
        if(bad) empt.push_back(w);
    }
    int q; cin >> q;
    int freevar = n-(m-empt.size());
    auto sols = mdint<int,int(1e9+7)> (5)^freevar;
    while(q--) {
        string s; cin >> s;
        valarray<F> v(m);
        for(int i=0;i<m;++i) v[i]=s[i]-'a';
        bool bad=false;
        for(auto i : empt) {
            auto w = (v*i);
            mint sm=0;
            for(int j=0;j<m;++j) sm+=w[j];
            if(sm!=mint(0)) {
                bad=true;
                break;
            }
        }
        if(bad) cout << "0\n";
        else cout << sols << '\n';
    }

}