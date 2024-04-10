#include "bits/stdc++.h"
using namespace std;
#define all(x) begin(x),end(x)
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { string sep; for (const T &x : v) os << sep << x, sep = " "; return os; }
#define debug(a) cerr << "(" << #a << ": " << a << ")\n";
typedef long long ll;
typedef vector<short> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pi;
const int mxN = 500+1, oo = 1e9;
bool adj[mxN*2][mxN*2];
short a[mxN*2][mxN], cols[mxN][mxN];
bitset<mxN*2> arrleft;
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
    bool operator==(const mint& o) {
        return d==o.d;
    }
    friend mint& operator+=(mint& a, const mint& o) {
        a.d+=o.d;
        if(a.d>=MOD) a.d-=MOD;
        return a;
    }
};
void solve() {
    int n; cin >> n;
    for(int i=0;i<2*n;++i) for(int j=0;j<n;++j) 
        cin >> a[i][j],--a[i][j];
    for(int i=0;i<n;++i) 
        fill(cols[i],cols[i]+n,0);
    for(int i=0;i<2*n;++i) 
        for(int j=0;j<n;++j) cols[j][a[i][j]]++;
    mint ans=1;
    arrleft.set();
    vi sol;
    for(int rep=0;rep<n;++rep) {
        int col=-1,val=-1;
        for(int i=0;i<n;++i) {
            for(int j=0;j<n;++j)
            if(cols[i][j]==1) {
                col=i,val=j;
                goto foundcand;
            }
        }
        foundcand: int use=-1;
        if(val!=-1) {
            // found unique val in column
            for(int i=arrleft._Find_first();i<2*n;i=arrleft._Find_next(i)) {
                if(a[i][col]==val) {
                    use=i;
                    break;
                }
            }
        } else {
            use = arrleft._Find_first();
            assert(use<2*n);
            ans=ans*2;
        }
        auto remove = [&](int j) {
            arrleft[j]=false;
            for(int i=0;i<n;++i) {
                cols[i][a[j][i]]--;
            }
        };
        remove(use);
        for(int i=arrleft._Find_first();i<2*n;i=arrleft._Find_next(i)) {
            for(int j=0;j<n;++j) {
                if(a[i][j]==a[use][j]) {
                    remove(i);
                    break;
                }
            }
        }
        sol.push_back(use+1);
    }
    cout << ans.d << '\n' << sol << '\n';
}
int main() {
    int t; cin >> t;
    while(t--) {
        solve();
    }
}