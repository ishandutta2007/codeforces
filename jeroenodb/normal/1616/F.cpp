#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
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
const long long MD = 3;
template<char MOD=MD> struct mdint {
    char d=0;
    mdint () {d=0;}
    mdint (char _d) : d(_d%MOD){
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
        return a = mdint(a.d*o.d);
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
struct vec {
    typedef bitset<257> bs;
    bs a[3];
    vec() {
        a[0].set();
    }
    // implement times and +
    vec& operator+=(const vec& o) {
        bs r[3];
        r[2] = (a[0]&o.a[2])|(a[1]&o.a[1])|(a[2]&o.a[0]);
        r[1] = (a[1]&o.a[0])|(a[0]&o.a[1])|(a[2]&o.a[2]);
        r[0] = ~(r[2]|r[1]);
        move(r,r+3,a);
        return *this;
    }
    vec& operator*=(const vec& o) {
        bs r[3];
        r[0] = a[0]|o.a[0];
        r[1] = (a[1]&o.a[1])|(a[2]&o.a[2]);
        r[2] = ~(r[0]|r[1]);
        move(r,r+3,a);
        return *this;
    }
    friend vec operator+(vec a, const vec& b) {
        a+=b;
        return a;
    }
    vec& operator*=(mint v) {
        if(v.d==0) *this = vec();
        else if(v.d==2) *this = -*this;
        return *this;
    }
    friend vec operator*(vec a, const vec& b) {
        a*=b;
        return a;
    }
    friend vec operator*(vec a, mint b) {
        a*=b;
        return a;
    }
    friend vec operator-(vec a, const vec& b) {
        a-=b;
        return a;
    }
    vec operator-() const {
        auto res = *this;
        swap(res.a[1],res.a[2]);
        return res;
    }
    vec& operator-=(const vec& o) {
        return *this+=-o;
    }
    mint sum() const {
        return mint( (a[1].count()+a[2].count()*2)%3);
    }
    mint operator[](int i) const {
        int ans=0;
        while(!a[ans][i]) ++ans;
        return ans;
    }
    void set(int i, mint v) {
        a[1][i]=a[2][i]=a[0][i]=0;
        a[v.d][i]=1;
    }
};

typedef mint F;
vec gaussianElim(vector<vec>& A, int cols) {
    int at= 0;
    vi ids;
    for(int i=0;i<cols and at<(int)A.size();++i) {
        for(int j=at;j<A.size();++j) if(A[j][i].d) {
            swap(A[j],A[at]);
            break;
        }
        if(!A[at][i].d) continue;
        ids.push_back(i);
        for(int j=0;j<(int)A.size();++j) if(A[j][i].d and j!=at) {
            A[j]-=A[at]*(A[j][i]/A[at][i]);
        }
        ++at;
    }
    vec res;
    for(int i=ids.size()-1;i>=0;--i) {
        auto stuff = (A[i] * res).sum();
        auto tmp = (A[i][cols]-stuff)/A[i][ids[i]];
        assert(tmp.d>=0 and tmp.d<3);
        res.set(ids[i],tmp);
    }
    return res;
}
std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
template<class I> I rnd(I l,I r){return std::uniform_int_distribution<I>(l,r)(rng);}
void solve() {
    vector<vec> eqs;
    int n,m; cin >> n >> m;
    bool bad=false;
    auto add = [&](vec v) { // gram schmidt
        if(bad) return;
        for(const auto& i : eqs) {
            auto nonzero = (~v.a[0])&(~i.a[0]);
            int tmp = nonzero._Find_first();
            if(tmp<m) {
                v-=i*(v[tmp]/i[tmp]);
                auto zes =  v.a[0];
                zes[m]=1;
                #undef all
                if(zes.all()) break;
                #define all(x) begin(x),end(x)
            }
        }
        bool allzero=true;
        for(int i=0;i<m;++i) if(v[i].d) allzero=false;
        if(allzero){
            if(v[m].d) bad=true;
        } else eqs.push_back(v);
    };
    vector<array<int,2>> es(m);
    vvi g(n,vi(n,-1));
    {
    int id=0;
    for(auto& [u,v] : es) {
        int w; cin >> u >> v >> w,--u,--v;
        g[u][v]=g[v][u]=id;
        if(w!=-1) {
            vec ve;
            ve.set(id,1);
            ve.set(m,w-1);
            eqs.push_back(ve);
        }
        id++;
    }
    }
    vector<vec> myv;
    for(int i=0;i<n;++i) for(int j=i+1;j<n;++j) for(int k=j+1;k<n;++k) {
        if(g[i][j]!=-1 and g[j][k]!=-1 and g[k][i]!=-1) {
            vec ve;
            ve.set(g[i][j],1);
            ve.set(g[j][k],1);
            ve.set(g[k][i],1);
            myv.push_back(ve);
        }
    }
    shuffle(all(myv),rng);
    for(auto i : myv) add(i);

    
    if(bad) cout << "-1\n";
    else {
        auto res = gaussianElim(eqs,m);
        for(int i=0;i<m;++i) {

            cout << res[i].d+1 << ' ';
        } cout << '\n';
    }

}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--) solve();
}