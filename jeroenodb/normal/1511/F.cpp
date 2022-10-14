#pragma GCC optimize("O1")
#include "bits/stdc++.h"
using namespace std;
#define all(x) begin(x),end(x)
typedef long long ll;
const long long MD = 998244353;
template<long long MOD> struct mdint {
    int d=0;
    mdint () {d=0;}
    mdint (long long _d) : d(_d%MOD){};
    friend mdint& operator+=(mdint& a, const mdint& o) {
        a.d+=o.d; if(a.d>=MOD) a.d-=MOD;
        return a;
    }
    friend mdint& operator-=(mdint& a, const mdint& o) {
        a.d-=o.d; if(a.d<0) a.d+=MOD;
        return a;
    }
    friend mdint& operator*=(mdint& a, const mdint& o) {
        return a = mdint((ll)a.d*o.d);
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
typedef mdint<MD> mint;
#define rep(i,n) for(int i=0;i<n;++i)
template<typename T, int N> struct matrix {
    T mat[N][N];
    matrix() {
        rep(i,N) fill(mat[i],mat[i]+N,0);
    }
    friend matrix operator*(const matrix& a, const matrix& b) {
        matrix res;
        rep(i,N) rep(j,N) rep(k,N) {
            res.mat[i][k]+=a.mat[i][j]*b.mat[j][k];
        }
        return res;
    }
    static matrix eye() {
        matrix res;
        for(int i=0;i<N;++i) res.mat[i][i]=1;
        return res;
    }
    friend matrix pw(matrix& a, ll pwr) {
        matrix res = eye();
        while(pwr) {
            if(pwr&1) res=res*a;
            a=a*a;
            pwr/=2;
        }
        return res;
    }
};
matrix<mint,203> mat;
int id(int i, int j, int k) {
    return 1+(i*5+j)*5+k;
}
int main() {
    int n,m; cin >> n >> m;

    vector<string> ws(n);
    for(auto& i: ws) cin >> i;
    sort(all(ws),[&](const string& a, const string& b) {return a.size()<b.size();});

    for(int i=0;i<n;++i) {
        // from 0 to other state
        int sz = ws[i].size();
        for(int j=0;j<=i;++j) {
            if(ws[i].substr(0,ws[j].size()) == ws[j]) {
                if(sz==1) mat.mat[0][0]+=1;
                else mat.mat[0][id(i,sz-1,ws[j].size()-1)]+=1 + (i!=j);
            }
        }
        for(int j=1;j<sz;++j) {
            for(int k=1;k<=j;++k) {
                if(j==1 and k==1) {
                    mat.mat[id(i,j,k)][0]+=1;
                } else mat.mat[id(i,j,k)][id(i,j-1,k-1)]+=1;
            }
            for(int w=0;w<n;++w) {
                auto o = ws[w];
                int k = min(j,(int)o.size());
                if(o.substr(0,k)==ws[i].substr(sz-j,k)) {
                    if((int)o.size()<=j) {
                        if(j==1 and k==1) mat.mat[id(i,j,0)][0]+=1;
                        else mat.mat[id(i,j,0)][id(i,j-1,o.size()-1)]+=1;
                    } else mat.mat[id(i,j,0)][id(w,o.size()-1,j-1)]+=1;
                }
            }
        }
    }
    mat = pw(mat,m);
    cout << mat.mat[0][0].d << '\n';
}