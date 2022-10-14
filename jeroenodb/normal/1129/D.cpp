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
const long long MD = 998244353;
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
const int B = 400;
struct sqrtTree {
    vector<vector<mint>> blocks;
    vector<mint> dp;
    vi lazy,v;
    int n;
    sqrtTree(int n) : n(n) {
        int k = (n+B-1)/B;
        blocks.resize(k, vector<mint>(B));
        lazy.resize(k);
        v.resize(n),dp.resize(n);
    }
    void push(int i) {
        if(!lazy[i]) return;
        for(int j=i*B;j<min(n,(i+1)*B);++j) {
            v[j]+=lazy[i];
        }
        lazy[i]=0;
    }
    void pull(int i) {
        assert(lazy[i]==0);
        int l = i*B,r = min(n,(i+1)*B);
        int mn = *min_element(v.begin()+l,v.begin()+r);
        auto& b = blocks[i];
        fill(all(b),mint(0));
        for(int j=l;j<r;++j) {
            v[j]-=mn;
            b[v[j]]+=dp[j];
        }
        partial_sum(all(b),b.begin());
        lazy[i]=mn;
    }
    void update(int i, mint v) {
        push(i/B);
        dp[i]=v;
        pull(i/B);
    };
    void update(int l, int r, int sgn) {
        int i = l/B, j = r/B;
        push(i),push(j);
        while(l<=r and l<(i+1)*B) {
            v[l++]+=sgn;
        }
        while(r>=l and r>=j*B) {
            v[r--]+=sgn;
        }
        pull(i);
        if(i!=j) pull(j);
        for(int k=i+1;k<j;++k) {
            lazy[k]+=sgn;
        }
    }
    mint query(int k) {
        mint ans=0;
        for(int i=0;i<(int)blocks.size();++i) {
            int l = k-lazy[i], r = B-1;
            if(l<r) {
                ans+=blocks[i][r];
                if(l>=0) ans-=blocks[i][l];
            } 
        }
        return ans;
    }
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k; cin >> n >> k;
    vi a(n); for(auto& i : a) cin >> i;
    vi prv(n,-1), last(n+1,-1);
    mint total=1,ans=0;
    sqrtTree tree(n+1);
    tree.update(0,1);
    for(int i=0;i<n;++i) {
        prv[i] = last[a[i]];
        if(prv[i]!=-1) {
            tree.update(prv[prv[i]]+1,prv[i],-1);
        }
        tree.update(prv[i]+1,i,1);
        last[a[i]]=i;
        ans = total-tree.query(k);
        total+=ans;
        tree.update(i+1,ans);
    }
    cout << ans << '\n';
}