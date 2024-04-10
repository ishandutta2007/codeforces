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
const long long MD = 1e9+7;
template<long long MOD=MD> struct mdint {
    int d=0;
    mdint () {d=0;}
    mdint (long long _d) : d(_d%MOD){
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
using  mint = mdint<MD>;
const int mxF = 2e4+2;
mint fact[mxF], ifact[mxF];
mint ncr(int a, int b) {
    if(b>a or a<0) return 0;
    return fact[a]*ifact[b]*ifact[a-b];
}
void precomp() {
    fact[0]=1;
    for(int i=1;i<mxF;++i) {
        fact[i]=fact[i-1]*i;
    }
    ifact[mxF-1] = mint(1)/fact[mxF-1];
    for(int i=mxF-2;i>=0;--i) {
        ifact[i]=ifact[i+1]*(i+1);
    }
}
const int MX = 6.8e6;
mint dp[2][MX];
bitset<MX> vis[2];
typedef array<char,4> state;
int id(const state& s) {
    int res=0;
    for(auto i : s) res=res*51+i;
    return res;
}
state getS(int id) {
    state res = {};
    for(int i=3;i>=0;--i) {
        res[i] = id%51;
        id/=51;
    }
    return res;
}
auto old = dp[0],nw = dp[1];


int main() {
    int n; cin >> n;
    vi d(n); for(auto& i : d) cin >> i;
    {
        int s = id({d[0]==2,d[0]==3,d[1]==2,d[1]==3});
        old[s]=1;
        vis[0][s]=true;
    }
    vector<state> patterns;
    for(int num=1;num<=3;++num) {
        vi have = {0,0,0};
        for(int i=0;i<num;++i) have.push_back(1);
        do {
            int tmp=0,at=0;
            state st;
            for(int i : have) {
                if(i==0) st[at++]=tmp,tmp=0;
                else tmp++;
            }
            st[at++]=tmp,tmp=0;
            if(st[0] or st[1]) {
                if(st[0]+st[1]==1) patterns.push_back(st);
            } else if(st[2]+st[3]==1) patterns.push_back(st);
            
        } while(next_permutation(all(have)));
    }

    for(int node=2;node<n;++node) {
        int myd = d[node];
        auto& ov =  vis[node%2];
        auto& nv =  vis[(node+1)%2];
        nv.reset();
        nw[0]=0;
        for(auto at = ov._Find_first();at<MX;at=ov._Find_next(at)) {
            auto st = getS(at);
            auto cur = old[at];
            auto add = [&](state to) {
                int num = accumulate(all(to),0);
                if(num>myd) return;
                auto res = st;
                for(int i=0;i<4;++i) {
                    if(to[i]>st[i]) return;
                    res[i]-=to[i];
                    if(i==1 or i==3) 
                        res[i-1]+=to[i];
                }
                if(!to[0] and !to[1]) {
                    if(st[0] or st[1]) return;
                    res = {res[2],res[3],0,0};
                }

                mint coef=1;
                for(int i=0;i<4;++i) {
                    if(to[i]==1) coef*=st[i];
                    else if(to[i]==2) 
                        coef*=(int)st[i]*(st[i]-1)/2;
                    else if(to[i]==3)
                        coef*=(int)st[i]*(st[i]-1)*(st[i]-2)/6;
                }
                
                res[2]+=myd-num==1;
                res[3]+=myd-num==2;
                int j = id(res);
                if(!nv[j]) {
                    nv[j]=true;
                    nw[j]=0;
                }
                nw[j]+=cur*coef;
            };
            for(auto pat : patterns) add(pat);
        }
        swap(old,nw);
    }
    cout << old[0] << '\n';

}