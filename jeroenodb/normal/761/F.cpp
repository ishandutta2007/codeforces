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
const int mxN = 1e3+2, oo = 1e9;
template<typename T> using grid = array<array<T,mxN>,mxN>;
grid<ll> ts, ls[26];
grid<int> mults;
void clear(grid<int>& pp) {
    for(auto& i : pp) fill(all(i),0);
}
struct special {
    int a,b,c,d;
    char e;
    void read() {
        cin >> a >> b >> c >> d >> e;
        e-='a';
    }
    template<typename T> void add(grid<T>& p, T sgn=1) {
        p[a][b]+=sgn,p[c+1][d+1]+=sgn;
        p[c+1][b]-=sgn,p[a][d+1]-=sgn;
    }
    template<typename T> T query(const grid<T>& p) {
        return p[c][d]+p[a-1][b-1]-p[a-1][d]-p[c][b-1];
    }
    bool operator<(const special& o) const {return e<o.e;}
};

grid<int> p;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,k; cin >> n >> m >> k;
    vector<string> templ(n);
    for(auto& i : templ) {
        cin >> i;
        for(auto& j : i) j-='a';
    }
    // need 2D prefix sums of sum of |templ-special_i| for each i: ts
    // need 2D prefix sums of |a letter - special_i| for each i: ls

    vector<special> sps(k);
    for(auto& i : sps) i.read();
    sort(all(sps));
    auto it = sps.begin();
    auto prefixSum = [&](auto& pp) {
        for(int i=1;i<=n;++i) for(int j=1;j<=m;++j) {
            pp[i][j]+=pp[i][j-1]+pp[i-1][j]-pp[i-1][j-1];
        }
    };
    for(auto& i : sps) mults[1][1]++,i.add(mults,-1);
    prefixSum(mults);
    
    for(int c=0;c<26;++c) { // calculate ts
        clear(p);
        while(it!=sps.end() and it->e==c) {
            it->add(p);
            ++it;
        }
        for(auto& i : sps) {
            i.add(ls[c],(ll)abs(i.e-c));
        }
        
        prefixSum(ls[c]);
        for(int i=1;i<=n;++i) for(int j=1;j<=m;++j) {
            p[i][j]+=p[i][j-1]+p[i-1][j]-p[i-1][j-1];
            auto cost = abs(templ[i-1][j-1]-c);
            ts[i][j]+=p[i][j]*cost;
            ls[c][i][j]+=mults[i][j]*cost;
        }
        // debug(c);
        // for(int i=1;i<=n;++i) {
        //     cout << vi(ls[c][i].begin()+1,ls[c][i].begin()+m+1) << '\n';
        // }
        prefixSum(ls[c]);
    }
    // for(int i=1;i<=n;++i) {
    //     cout << vi(ts[i].begin()+1,ts[i].begin()+m+1) << '\n';
    // }
    prefixSum(ts);
    ll total = ts[n][m];
    ll ans= 1e18;
    for(auto i : sps) {
        auto& pp = ls[(int)i.e];
        auto outsideWindow = total-i.query(ts);
        auto insideWindow = i.query(pp);
        ans = min(ans, outsideWindow+insideWindow);
    }
    cout << ans << '\n';

}