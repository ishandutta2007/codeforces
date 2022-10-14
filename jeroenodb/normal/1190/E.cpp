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
const int mxN = 2e5+1, LG = 19, oo = 1e9;
using F = double;
typedef complex<F> pt;
#define X real()
#define Y imag()
void read(pt& p) {
    int a,b; cin >> a >> b;
    p = {a,b};
}
bool comp(pt a, pt b) {
    return make_pair(a.X,a.Y)<make_pair(b.X,b.Y);
}
const F tau = acos(-1)*2;
int jmp[LG][mxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m; cin >> n >> m;
    vector<pt> pts(n);
    for(int i=0;i<n;++i) {
        read(pts[i]);
    }
    sort(all(pts),comp);
    pts.resize(unique(all(pts))-pts.begin());
    n = pts.size();
    auto good = [&](F r) {
        vector<F> ivs;
        for(auto& p : pts) {
            auto a = arg(p), b = acos(r/abs(p));
            ivs.push_back(fmod(a-b+tau,tau));
            ivs.push_back(fmod(a+b+tau,tau));
        }
        int N = 2*n;
        vi ord(N); iota(all(ord),0);
        sort(all(ord),[&](auto a, auto b) {return ivs[a]<ivs[b];});
        vi ip(N);
        for(int i=0;i<N;++i) ip[ord[i]]=i;
        int wrap=oo;
        for(int i=0;i<N;i+=2) if(ip[i]<ip[i+1]) wrap = min(wrap,ip[i+1]+1);
        if(wrap==oo) return true;
        auto fjmp = jmp[0];
        fjmp[N-1]=wrap;
        for(int i=N-2;i>=0;--i) {
            fjmp[i]=fjmp[i+1]+1;
            if(ord[i+1]%2==0) {
                fjmp[i] = min(fjmp[i], (ip[ord[i+1]^1]-i-1+N)%N + 1 );
            }
        }
        for(int j=1;j<LG;++j) for(int i=0;i<2*n;++i) jmp[j][i] = min(2*n, jmp[j-1][i]+jmp[j-1][(jmp[j-1][i]+i)%N]);
        for(int i=0;i<N;++i) {
            int ans=0,at=i;
            for(int j=0;j<LG;++j) if(m&(1<<j)) {
                ans+=jmp[j][at];
                at = (at+jmp[j][at])%N;
            }
            if(ans>=N) {
                return true;
            }
        }
        return false;
        
    };
    F lo=1e-9,hi = 1e18;
    for(int i=0;i<n;++i) hi = min(hi,abs(pts[i]));
    if(hi<=1e-12) {
        cout << "0\n";
        exit(0);
    }
    while(hi-lo>0.4e-6) {
        F mid = (lo+hi)/2;
        if(good(mid)) lo = mid;
        else hi = mid;
    }
    cout << setprecision(12) << lo << '\n';

}