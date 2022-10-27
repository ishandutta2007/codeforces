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
int mxN = -1, oo = 1e9;

bool ask(int bit) {
    vi v;
    for(int i=0;i<mxN;++i) if(i & (1<<bit)) {
        v.push_back(i+1);
    }
    cout << "? " << v.size() << ' ' << v << endl;
    string ans; cin >> ans;
    return ans=="YES";
}
void answer(int ans) {
    if(ans>mxN) return;
    cout << "! " << ans << endl;
    string res; cin >> res;
    if(res==":)") exit(0);
}
std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
template<class I> I rnd(I l,I r){return std::uniform_int_distribution<I>(l,r)(rng);}
int main() {
    cin >> mxN;
    if(mxN==1) {
        answer(1);
    }
    int LG=0;
    while( (1<<LG) <=(mxN-1)) ++LG;
    ++LG; // one extra
    // connected to 17 <=> know it for sure, 0 is off, 1 is on
    vi col(LG);
    int comps=LG;
    vi cmp(LG);
    iota(all(cmp),0);
    auto join = [&](int u, int v, int e) {
        // cerr << u << ' ' << v << ' ' << e << '\n';
        if(cmp[u]==cmp[v]) {
            return;
        }
        int par = (col[u]^col[v])^e;
        int cv = cmp[u];
        for(int i=0;i<LG;++i) if(cmp[i]==cv) {
            col[i] ^= par;
            cmp[i]=cmp[v];
        }
        comps--;
    };
    int c=-1;
    array<bool,4> r = {};
    while(comps>2) {
        int a=0;
        if(c!=-1) a=c;
        while(cmp[a]==cmp[LG-1]) ++a;
        int b = 0;
        while(cmp[b]==cmp[LG-1] or cmp[b]==cmp[a]) ++b;
        
        if(c==-1) r[0]=ask(a);
        r[1]=ask(b);
        r[2]=ask(b);
        c=-1;
        if(r[1]==r[2]) {
            // .... or J... or J..J or ...J
            join(b,LG-1,r[1]);
        } else {
            r[3]=ask(a);
            
            if(r[0]!=r[3]) {
                // J.J. or .J.J
                c=a;
                join(a,b,r[0]^r[2]);
            } else {
                // .J.. or ..J.
                join(a,LG-1,r[0]);
                
            }
            r[0]=r[3];
        }
    }
    int ans=0;
    int guess[2] = {};
    for(int i=0;i<LG-1;++i) {
        if(cmp[i]==cmp[LG-1]) {
            ans|=int(col[i]^col[LG-1])<<i;
        } else {
            guess[0]|=int(col[i])<<i;
            guess[1]|=int(!col[i])<<i;
        }
    }
    int a[2] = {ans|guess[0],ans|guess[1]};
    a[0]++,a[1]++;
    if(a[0]>a[1]) swap(a[0],a[1]);
    answer(a[0]);
    answer(a[1]);
}