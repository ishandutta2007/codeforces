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
const long long MOD = 1e9+7;
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
typedef complex<int> pt;
#define X real()
#define Y imag()
const int mxR = 2e3+10, mxN=2e3+10, oo = 1e9, mxF=1e4;
mint fact[mxF], ifact[mxF];
mint c(int a, int b) {
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
int pref[mxR][mxR],b[mxN],n,m,R;
int subr(int ax, int ay, int bx, int by) {
    if(ax>=bx or ay>=by) return 0;
    ax = max(0,ax),ay=max(0,ay),bx = min(mxR-1,bx), by=min(mxR-1,by);
    return pref[bx][by]-pref[bx][ay]-pref[ax][by]+pref[ax][ay];
}
int get(pt p) {
    return subr(p.X-R-1,p.Y-R-1,p.X+R,p.Y+R);
}
int get(pt p, pt q) {
    return subr(max(p.X-R-1,q.X-R-1),max(p.Y-R-1,q.Y-R-1), min(p.X+R,q.X+R),min(p.Y+R,q.Y+R));
}

pt sn[mxN];
void read(pt& p) {
    int x,y; cin >> x >> y;
    p = {x,y};
}

int main() {
    precomp();
    cin >> n >> m >> R;
    for(int i=0;i<n;++i) {
        read(sn[i]);
        pref[sn[i].X][sn[i].Y]++;
        cin >> b[i];
    }
    for(int i=1;i<mxR;++i) for(int j=1;j<mxR;++j) {
        pref[i][j]+=pref[i-1][j]+pref[i][j-1]-pref[i-1][j-1];
    }
    // precomputation done
    mint ans=0, totalways = c(n,m);
    // count up all B_i^2
    for(int i=0;i<n;++i) {
        int seeme = get(sn[i]);
        ans+=mint(b[i])*b[i]*(totalways-c(n-seeme,m));
    }
    // count up all 2*B_i*B_j
    for(int i=0;i<n;++i) {
        for(int j=i+1;j<n;++j) {
            int seei = get(sn[i]),seej=get(sn[j]),seeij=get(sn[i],sn[j]);
            auto cur = mint(b[i])*b[j]*2;
            auto factor = totalways-c(n-seei,m)-c(n-seej,m)+c(n-seei-seej+seeij,m);
            // one out of seei, one out of seej, or at least one out of seeij
            ans+=cur*factor;
        }
    }
    cout << ans.d << '\n';

}