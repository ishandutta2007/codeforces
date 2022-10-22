#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using i64 = int_fast64_t;
using pii = pair<int,int>;
using pll = pair<i64,i64>;
template <class T> constexpr T inf = numeric_limits<T>::max() / (T)2;
template <class T> using heap = priority_queue<T>;
template <class T> using minheap = priority_queue<T,vector<T>,greater<T>>;
#define fir first
#define sec second
#define mkp make_pair
#define mkt make_tuple
#define emb emplace_back
#define emp emplace
#define all(v) begin(v), end(v)
namespace std {
    template <class T> void hash_combine(size_t &seed, T const &key) {
        seed ^= hash<T>()(key) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
    }
    template <class T, class U> struct hash<pair<T,U>> {
        size_t operator()(pair<T,U> const &pr) const
        {
            size_t seed = 0;
            hash_combine(seed,pr.first);
            hash_combine(seed,pr.second);
            return seed;
        }
    };
}
void ios_untie() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}
void file_setup() {
    if(!freopen("stderr.txt","wt",stderr)) {
        std::cerr << "Failed to open the stderr file\n";
        freopen("CON","wt",stderr);
    }
    if(!freopen("stdout.txt","wt",stdout)) {
        std::cerr << "Failed to open the stdout file\n";
        freopen("CON","wt",stdout);
    }
    if(!freopen("stdin.txt","rt",stdin)) {
        std::cerr << "Failed to open the stdin file.\n";
        freopen("CON","rt",stdin);
    }
}
template <class A, size_t N, class T> void init(A (&array)[N], const T &val) { fill((T*)array,(T*)(array + N),val); }
i64 binry(i64 ok, i64 ng, const function<bool(i64)> &f) {
    while(abs(ok-ng)>1) {
        i64 mid=(ok+ng)/2;
        (f(mid) ? ok : ng) = mid;
    }
    return ok;
}


/*-------------------------------*/


int n,k;
int a[1<<19];
i64 b[1<<19];
i64 ans;

void solve() {
    reverse(a,a+n);
    for(int i=0; i<n; ++i) {
        b[i+1]=b[i]+a[i];
    }
    ans+=b[n];
    sort(b+1,b+n,greater<i64>());
    for(int i=1; i<k; ++i) ans+=b[i];
    cout<<ans<<endl;
}

signed main() {
    ios_untie();
#ifdef LOCAL
    file_setup();
#endif

    cin>>n>>k;
    for(int i=0; i<n; ++i) cin>>a[i];
    solve();    
}