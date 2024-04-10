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
const int mxN = 1600+1, oo = 1e9+2;

int pref[mxN];
int dp[mxN],prefmx[mxN];
vector<pi> ivs;
vi leftmost;
int solveDP(int m) {
    fill_n(dp,ivs.size(),-oo);
    dp[0]=0;
    for(int rep=0;rep<m;++rep) {
        for(int i=1;i<(int)ivs.size();++i) 
            prefmx[i] = max(dp[i],prefmx[i-1]);
        for(int i=ivs.size()-1;i>0;--i) {
            auto [l,r] = ivs[i];
            // overlapping
            if(leftmost[i]<i-1) dp[i] = max(dp[i],dp[leftmost[i]+1]+pref[r]-pref[ivs[leftmost[i]+1].second]);
            // nonoverlapping
            dp[i] = max(dp[i], prefmx[leftmost[i]] + pref[r]-pref[l-1]);
        }
    }
    return *max_element(dp, dp+ivs.size());
}
vi a;
int setupDP(int n, int m, int cutoff) {
    for(int i=1;i<=n;++i) {
        pref[i] = a[i-1]<=cutoff;
    }
    for(int i=1;i<=n;++i) pref[i]+=pref[i-1];
    return solveDP(m);
}
bool inside(pi c, pi d) {
    return d.first<=c.first and c.second<=d.second;
}
int main() {
    int n,s,m,k; cin >> n >> s >> m >> k;
    a.resize(n); for(auto& i : a) cin >> i;
    // get intervals
    ivs.resize(s);
    for(auto& [l,r] : ivs) cin >> l >> r;
    for(int i=0;i<(int)ivs.size();++i) {
        for(int j=0;j<(int)ivs.size();++j) if(i!=j) {
            if(inside(ivs[i],ivs[j])) {
                ivs.erase(ivs.begin()+i);
                --i;
                break;
            }
        }
    }
    ivs.push_back({0,0}); // dummy lefthandside segment
    sort(all(ivs));
    for(int i=0;i+1<ivs.size();++i) assert(ivs[i].second<ivs[i+1].second);
    leftmost.resize(ivs.size());
    for(int i=1,j=0;i<(int)ivs.size();++i) {
        while(j+1<i and ivs[j+1].second<ivs[i].first) 
            ++j;
        leftmost[i] =j;
    }
    vi b = a;
    b.push_back(oo);
    sort(all(b));
    int lo=0,hi=b.size()-1;
    while(lo<hi) {
        int mid = (lo+hi)/2;
        if(setupDP(n,m,b[mid])>=k) {
            hi=mid;
        } else lo=mid+1;
    }
    int res = b[lo];
    if(res==oo) cout << "-1\n";
    else cout << res << '\n';
    
    
}