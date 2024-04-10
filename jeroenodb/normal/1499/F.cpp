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
const int mxN = 5000+1, oo = 1e9;
const long long MOD = 998244353;
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
};
mint& operator+=(mint& a, const mint& o) {
    a.d+=o.d;
    if(a.d>=MOD) a.d-=MOD;
    return a;
}
vi adj[mxN];
int k;
struct subdata {
    vector<mint> cnt = {1};
    void merge(const subdata& o) {
        vector<mint> cntans(max(cnt.size(),o.cnt.size()));
        for(int i=cnt.size()-1;i>=0;--i) {
            for(int j=0;j<min(k-i+1,(int)o.cnt.size());++j) {
                cntans[max(i,j)] += cnt[i]*o.cnt[j];
            }
        }
        swap(cnt,cntans);
    }
    void goup() {
        mint ans = 0;
        for(auto i: cnt) ans+=i;
        cnt.insert(cnt.begin(),ans);
    }
};
subdata dat[mxN];
void dfs(int at=0,int from=-1) {
    for(int to: adj[at]) {
        if(to==from) continue;
        dfs(to,at);
        dat[at].merge(dat[to]);
    }
    dat[at].goup();
}
int main() {
    int n; cin >> n >> k;
    for(int i=0;i<n-1;++i) {
        int a,b; cin >> a >> b;
        --a,--b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs();
    cout << dat[0].cnt[0].d << '\n';
}