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
std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
template<class I> I rnd(I l,I r){return std::uniform_int_distribution<I>(l,r)(rng);}
int main() {
    int n,y; cin >> n >> y;
    vi a(n); for(auto& i : a) cin >> i;
    int m; cin >> m >> y;
    vi b(m); for(auto& i : b) cin >> i;
    if(n==1 and m==1) {
        cout << "2\n";
        exit(0);
    }
    // must be at least 2 points on one side, check those
    // check prime factors of number
    int reps= 80; // (1e4+1e5*10)* 80
    int ans = 0;
    auto check = [&](int x, int p) {
        int mod = 2*p;
        x%=mod;
        int cur=0;
        for(auto i : a) {
            if(i%mod==x) cur++;
        }
        for(auto i : b) {
            if((i+p)%mod==x) cur++;
        }
        ans=max(ans,cur);
    };
    check(0,1);
    check(1,1);
    while(reps) {
        bool flip = rnd(0,1);
        if(flip) swap(a,b);
        if(a.size()==1) continue;
        int i = rnd(0,(int)a.size()-1);
        int j;
        do {
            j = rnd(0,(int)a.size()-1);
        } while(i==j);
        if(a[i]>a[j]) swap(i,j);
        int x = a[i], dif = a[j]-a[i];
        if(dif%2!=0) continue;
        dif/=2;
        auto bb = b[rnd(0,(int)b.size()-1)];
        // x+ 2*d*k +d = bb
        //  0 ~ bb-x + d (mod 2*d), d | bb
        int p = 2*oo;
        for(int o=1;o*o<=dif;++o) {
            if(dif%o==0) {
                auto isgood = [&](int div) {
                    auto tmp  = (bb-x+div)%(2*div);
                    if(tmp==0) {
                        p=min(p,div);
                    }
                };
                isgood(o);
                isgood(dif/o);
            }
        }
        if(p==2*oo) continue;
        check(x,p);
        reps--;
    }
    cout << ans << '\n';
}