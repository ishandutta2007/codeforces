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
struct myhash {
    size_t operator()(unsigned long long i) const {
        return ((i*125656243ULL)^42245245ULL)-1345ULL;
    }
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    vector<ll> a(n);
    for(auto& i : a) cin >> i;
    ll ans=0;

    for(int rep=0;rep<30;++rep) {
        auto g = a[rnd(0,n-1)];
        map<ll,int> cnt;
        {
        unordered_map<ll,int,myhash> ucnt;
        ucnt.reserve(10000);
        for(auto x : a) {
            ucnt[gcd(x,g)]++;
        }
        cnt = map<ll,int>(all(ucnt));
        }
        
        vector<pair<ll,int>> ps;
        ll gg=g;
        for(ll i=2;i*i<=gg;++i) {
            int tmp=0;
            while(gg%i==0) {
                gg/=i;
                tmp++;
            }
            if(tmp) ps.push_back({i,tmp});
        }
        if(gg!=1) ps.push_back({gg,1});

        for(auto [p,c] : ps) {
            for(auto it = cnt.rbegin();it!=cnt.rend();++it) {
                if(it->first%p==0) {
                    cnt[it->first/p]+=it->second;
                }
            }
        }
        for(auto [divisor,num] : cnt) {
            if(num*2>=n) {
                ans = max(divisor,ans);
            }
        }
    }
    cout << ans << '\n';
}